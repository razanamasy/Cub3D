/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:46:34 by hrazanam          #+#    #+#             */
/*   Updated: 2022/03/15 15:46:36 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_minimap_calc(t_point *check, t_point *it)
{
	it->x = 0;
	it->y = 0;
	check->x = 0;
	check->y = 0;
}

void	init_minimap_check(t_perso perso, t_point *check, t_point *centre)
{
	centre->x = perso.coord.x / 64;
	centre->y = perso.coord.y / 64;
	check->y = centre->y - 5;
	check->x = centre->x - 5;
}

void	init_map_y(t_lststr **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		*map = (*map)->nxt;
		i++;
	}
}
