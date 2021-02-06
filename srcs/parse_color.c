/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarsel <almarsel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 08:26:30 by almarsel          #+#    #+#             */
/*   Updated: 2021/02/05 04:19:10 by almarsel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		convert_color(int rgb[3])
{
	int	convert;

	convert = rgb[0];
	convert = (convert << 8) + rgb[1];
	convert = (convert << 8) + rgb[2];
	return (convert);
}

int		through_color_line(char *line, int offset)
{
	int	i;
	int	rgb[3];

	i = 0;
	ft_memset(rgb, 0, 3);
	while (i < 3)
	{
		if (!line[offset])
			return (-1);
		rgb[i] = ft_atoi(&line[offset]);
		if (rgb[i] < 0 || rgb[i] > 255)
			return (-1);
		offset += 1 + int_size(rgb[i++]);
		if (i == 3)
			offset--;
		while (is_white_space(line[offset]) || line[offset] == '0')
			offset++;
	}
	if (offset != (int)ft_strlen(line))
		return (-1);
	return (convert_color(rgb));
}

int		parse_color(char *line, t_color *color)
{
	int	i;
	int	offset;
	int	value;

	i = 0;
	offset = 1;
	while (is_white_space(line[offset]) || line[offset] == '0')
		offset++;
	if ((value = through_color_line(line, offset)) == -1)
		return (-line[0]);
	if (line[0] == 'F')
		color->floor = value;
	else if (line[0] == 'C')
		color->ceiling = value;
	return (1);
}
