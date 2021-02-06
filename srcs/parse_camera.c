/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarsel <almarsel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 10:16:12 by almarsel          #+#    #+#             */
/*   Updated: 2021/02/05 15:26:16 by almarsel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_north(t_param *p)
{
	p->dir.x = 0;
	p->dir.y = -1;
	p->plane.x = -0.66;
	p->plane.y = 0;
}

void	set_south(t_param *p)
{
	p->dir.x = 0;
	p->dir.y = 1;
	p->plane.x = 0.66;
	p->plane.y = 0;
}

void	set_east(t_param *p)
{
	p->dir.x = 1;
	p->dir.y = 0;
	p->plane.x = 0;
	p->plane.y = -0.66;
}

void	set_west(t_param *p)
{
	p->dir.x = -1;
	p->dir.y = 0;
	p->plane.x = 0;
	p->plane.y = 0.66;
}

int		parse_camera(t_param *p, char dir, int x, int y)
{
	if (p->dirparsed)
		return (0);
	p->dirparsed = 1;
	p->pos.x = (double)(x) + 0.5;
	p->pos.y = (double)(y) + 0.5;
	if (dir == 'N')
		set_north(p);
	else if (dir == 'S')
		set_south(p);
	else if (dir == 'E')
		set_east(p);
	else if (dir == 'W')
		set_west(p);
	return (1);
}
