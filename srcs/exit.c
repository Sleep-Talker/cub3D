/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarsel <almarsel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 08:36:49 by almarsel          #+#    #+#             */
/*   Updated: 2021/02/05 04:48:30 by almarsel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_sprites(t_param *p)
{
	int	i;

	i = 0;
	while (i < p->spritesnb)
	{
		free(p->sprites[i]);
		i++;
	}
	free(p->sprites);
}

void	free_grid(t_param *p)
{
	int	i;

	i = 0;
	if (p->gridparsed)
	{
		while (i < p->map->size.x)
		{
			free(p->map->grid[i]);
			i++;
		}
	}
	else
	{
		while (i < p->linesparsed)
		{
			free(p->map->grid[i]);
			i++;
		}
	}
	if (p->linesparsed || p->gridparsed)
		free(p->map->grid);
}

int		free_and_exit(t_param *p)
{
	int	i;

	i = 0;
	free_grid(p);
	if (p->gridparsed)
		free_sprites(p);
	while (i < FOPEN_MAX)
	{
		if (i < 5 && p->tex[i].img != NULL)
			mlx_destroy_image(p->window->mlx, p->tex[i].img);
		if (p->still[i])
			free(p->still[i]);
		i++;
	}
	free(p->map);
	if (p->window->window)
		mlx_destroy_window(p->window->mlx, p->window->window);
	free(p->window->mlx);
	free(p->window);
	free(p->color);
	if (p->wallsdist)
		free(p->wallsdist);
	exit(1);
}
