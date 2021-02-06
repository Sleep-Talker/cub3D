/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarsel <almarsel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 02:16:10 by almarsel          #+#    #+#             */
/*   Updated: 2021/02/05 09:43:36 by almarsel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	go_through_res_line(char *line, t_param *p)
{
	int	i;

	i = 0;
	while (is_white_space(line[i]) || line[i] == '0')
		i++;
	p->window->x = abs(ft_atoi(line + i));
	i += int_size(p->window->x) + 1;
	while (is_white_space(line[i]) || line[i] == '0')
		i++;
	p->window->y = abs(ft_atoi(line + i));
	i += int_size(p->window->y);
	while (is_white_space(line[i]))
		i++;
	if (i != (int)ft_strlen(line))
		return (0);
	return (1);
}

int	parse_res(char *line, t_param *p)
{
	int x;
	int y;
	int	i;

	i = 0;
	if (!(go_through_res_line(line, p)))
		return (-10);
	mlx_get_screen_size(p->window->mlx, &x, &y);
	if (p->window->x > x)
		p->window->x = x;
	if (p->window->y > y)
		p->window->y = y;
	if (!(p->window->x) || !(p->window->y))
		return (-10);
	if (!(p->wallsdist = malloc(sizeof(double) * (p->window->x + 1))))
		return (-10);
	while (i < p->window->x)
		p->wallsdist[i++] = 0;
	p->resparsed = 1;
	return (1);
}

int	parse_texture(int id, char *line, t_param *p)
{
	int	fd;
	int w;
	int h;

	w = 64;
	h = 64;
	while (is_white_space(*line))
		line++;
	fd = open(line, O_RDONLY);
	if (fd > 1)
	{
		close(fd);
		p->tex[id].img = mlx_xpm_file_to_image(p->window->mlx,
				line, &p->tex[id].w, &p->tex[id].h);
		p->tex[id].ptr = (unsigned int *)mlx_get_data_addr(p->tex[id].img,
				&p->tex[id].bpp, &p->tex[id].size_line, &p->tex[id].endian);
		return (1);
	}
	else
		return (-5 - id);
}

int	isvalid(char *line, t_param *p)
{
	int	ret;

	ret = 0;
	if (line[0] == 'R')
		ret = parse_res(&line[2], p);
	if (line[0] == 'N' && line[1] == 'O')
		ret = parse_texture(0, &line[2], p);
	if (line[0] == 'S' && line[1] == 'O')
		ret = parse_texture(1, &line[2], p);
	if (line[0] == 'W' && line[1] == 'E')
		ret = parse_texture(2, &line[2], p);
	if (line[0] == 'E' && line[1] == 'A')
		ret = parse_texture(3, &line[2], p);
	if (line[0] == 'S' && line[1] != 'O')
		ret = parse_texture(4, &line[2], p);
	if (line[0] == 'F' || line[0] == 'C')
		ret = parse_color(&line[0], p->color);
	return (ret);
}

int	check_and_parse(char **argv, int fd, t_param *param)
{
	char	*line;
	int		offset;
	int		ret;

	offset = 0;
	get_next_line(param->still, fd, &line);
	while ((ret = isvalid(line, param)) > 0)
	{
		free(line);
		get_next_line(param->still, fd, &line);
		offset++;
	}
	if (offset != 8)
	{
		free(line);
		return (ret);
	}
	param->scrdist = round(param->window->x / 2 / tan((FOV / 2) * RAD));
	param->sizeconst = (float)64 / param->scrdist;
	param->map->size = get_map_dimensions(param, argv[1], &line, &fd);
	if (!(parse_map(fd, line, param)))
		return (-4);
	else
		param->gridparsed = 1;
	return (1);
}
