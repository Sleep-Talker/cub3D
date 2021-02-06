/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarsel <almarsel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 08:47:54 by almarsel          #+#    #+#             */
/*   Updated: 2021/02/06 04:12:40 by almarsel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	dda(t_param *p)
{
	while (p->hit == 0)
	{
		if (p->sidedist.x < p->sidedist.y)
		{
			p->sidedist.x += p->delta.x;
			p->mappt.x += p->step.x;
			p->side = 0;
			if (p->step.x == 1)
				p->orient = 2;
			else if (p->step.x == -1)
				p->orient = 3;
		}
		else
		{
			p->sidedist.y += p->delta.y;
			p->mappt.y += p->step.y;
			p->side = 1;
			if (p->step.y == 1)
				p->orient = 0;
			else if (p->step.y == -1)
				p->orient = 1;
		}
		if (!(check_hit(p)))
			break ;
	}
}

void	dda_init(t_param *p)
{
	p->hit = 0;
	p->delta.x = sqrt(1 + (p->raydir.y * p->raydir.y)
			/ (p->raydir.x * p->raydir.x));
	p->delta.y = sqrt(1 + (p->raydir.x * p->raydir.x)
			/ (p->raydir.y * p->raydir.y));
	if (p->raydir.x < 0)
	{
		p->step.x = -1;
		p->sidedist.x = (p->raypos.x - p->mappt.x) * p->delta.x;
	}
	else
	{
		p->step.x = 1;
		p->sidedist.x = (p->mappt.x + 1.0 - p->raypos.x) * p->delta.x;
	}
	if (p->raydir.y < 0)
	{
		p->step.y = -1;
		p->sidedist.y = (p->raypos.y - p->mappt.y) * p->delta.y;
	}
	else
	{
		p->step.y = 1;
		p->sidedist.y = (p->mappt.y + 1.0 - p->raypos.y) * p->delta.y;
	}
}
