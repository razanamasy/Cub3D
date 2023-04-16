/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:47:09 by hrazanam          #+#    #+#             */
/*   Updated: 2022/03/15 15:47:11 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	minimap_background(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 640 / 5)
	{
		j = 0;
		while (j < 640 / 5)
		{
			if (extract_map(game->inf.map, j / 64, i / 64) != '2')
				put_to_buff(game, j, i, BLACK);
			j++;
		}
		i++;
	}
}

void	minimap_wall(t_game *game, int x, int y, int color)
{
	int	depx;
	int	depy;
	int	i;
	int	j;

	depx = x * 64;
	depy = y * 64;
	i = 0 + depy;
	j = 0 + depx;
	while (i < 64 + depy)
	{
		j = 0 + depx;
		while (j < 64 + depx)
		{
			put_to_buff(game, j / 5, i / 5, color);
			j++;
		}
		i++;
	}
}

void	trace_wall(t_game *game, t_point *it, t_point *check, t_lststr *map)
{
	if (check->x < game->inf.dim[0] && check->x >= 0)
	{
		if ((map->str)[check->x] == '1' && check->y >= 0)
			minimap_wall(game, it->x, it->y, WHITE);
		if (is_posdir((map->str)[check->x], '0') && check->y >= 0)
			minimap_wall(game, it->x, it->y, GRAY);
	}
	it->x += 1;
	check->x += 1;
}

void	draw_minimap(t_game *game, t_perso perso, t_lststr *map)
{
	t_point	centre;
	t_point	it;
	t_point	check;
	char	c;

	init_minimap_calc(&check, &it);
	init_minimap_check(perso, &check, &centre);
	minimap_background(game);
	init_map_y(&map, check.y);
	while (it.y < 10 && map)
	{
		it.x = 0;
		check.x = centre.x - 5;
		c = '1';
		while (c != '\0' && it.x < 10)
			trace_wall(game, &it, &check, map);
		if (check.y >= 0)
				map = map->nxt;
		it.y++;
		check.y++;
	}
	all_super_ray(game, perso.th_dir);
	minimap_wall(game, 5, 5, YELLOW);
	magic_wand(perso, game);
}
