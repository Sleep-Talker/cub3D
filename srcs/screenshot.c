/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarsel <almarsel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 03:41:01 by almarsel          #+#    #+#             */
/*   Updated: 2021/02/05 03:46:01 by almarsel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	shift(unsigned char *headers, int value)
{
	headers[0] = (unsigned char)(value);
	headers[1] = (unsigned char)(value >> 8);
	headers[2] = (unsigned char)(value >> 16);
	headers[3] = (unsigned char)(value >> 24);
}

void	write_headers(int fd, t_param *p, int size)
{
	unsigned	char	headers[54];
	int					i;

	i = 0;
	while (i < 54)
		headers[i++] = (unsigned char)(0);
	headers[0] = (unsigned char)('B');
	headers[1] = (unsigned char)('M');
	shift(headers + 2, size);
	headers[10] = (unsigned char)(54);
	headers[14] = (unsigned char)(40);
	shift(headers + 18, p->window->x);
	shift(headers + 22, p->window->y);
	headers[27] = (unsigned char)(1);
	headers[28] = (unsigned char)(24);
	write(fd, headers, 54);
}

int		write_colors(int fd, t_param *p, t_pt dim)
{
	static	unsigned	char	rgb[3] = {
		0, 0, 0 };
	int							i;
	int							j;

	i = 0;
	while (i < p->window->y)
	{
		j = 0;
		while (j < p->window->x)
		{
			rgb[0] = ((p->frameptr[(dim.y - i) * dim.x + j]) >> 16);
			rgb[1] = ((p->frameptr[(dim.y - i) * dim.x + j]) >> 8);
			rgb[2] = (p->frameptr[(dim.y - i) * dim.x + j]);
			if ((write(fd, rgb + 2, 1)) < 0)
				return (0);
			if ((write(fd, rgb + 1, 1)) < 0)
				return (0);
			if ((write(fd, rgb, 1)) < 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	write_image(t_param *p)
{
	int		outputfd;
	int		filesize;
	t_pt	dim;

	filesize = 54 + (p->window->x * p->window->y);
	if (!(outputfd = open("screenshot.bmp", O_WRONLY | O_CREAT, 0777)))
		write(1, "couldn't create bmp\n", 20);
	dim = (t_pt){p->window->x, p->window->y - 1};
	write_headers(outputfd, p, filesize);
	write_colors(outputfd, p, dim);
	close(outputfd);
}

void	screenshot(char **argv, t_param *p, int fd)
{
	if (!(fd = open(argv[1], O_RDONLY)))
		exit(2);
	if (!(check_and_parse(argv, fd, p)))
	{
		write(1, "invalid .cub file", 17);
		exit(2);
	}
	single_ray_cast(p);
	write_image(p);
	free_and_exit(p);
}
