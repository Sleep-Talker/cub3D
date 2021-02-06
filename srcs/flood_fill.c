/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarsel <almarsel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 08:36:10 by almarsel          #+#    #+#             */
/*   Updated: 2021/02/05 04:12:24 by almarsel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		reached_limit(t_param *p, t_pt pt)
{
	return (pt.x == 0 || pt.y == 0 ||
			pt.x == p->map->size.x - 1 || pt.y == p->map->size.y - 1
			|| p->map->grid[pt.x][pt.y] == ' ');
}

int		can_access(char **grid, t_pt pt)
{
	return (!!(ft_strchr("02 ", grid[pt.x][pt.y])));
}

void	flood_fill(t_param *p, t_pt coord)
{
	if (reached_limit(p, coord))
	{
		write(1, "Error:\nmap should be closed by walls. \
Player should be inside.\n", 63);
		free_and_exit(p);
	}
	if (p->map->grid[coord.x][coord.y] == '2')
		p->map->grid[coord.x][coord.y] = 'F';
	else
		p->map->grid[coord.x][coord.y] = 'O';
	if (can_access(p->map->grid, (t_pt){coord.x - 1, coord.y}))
		flood_fill(p, (t_pt){coord.x - 1, coord.y});
	if (can_access(p->map->grid, (t_pt){coord.x + 1, coord.y}))
		flood_fill(p, (t_pt){coord.x + 1, coord.y});
	if (can_access(p->map->grid, (t_pt){coord.x, coord.y - 1}))
		flood_fill(p, (t_pt){coord.x, coord.y - 1});
	if (can_access(p->map->grid, (t_pt){coord.x, coord.y + 1}))
		flood_fill(p, (t_pt){coord.x, coord.y + 1});
}
