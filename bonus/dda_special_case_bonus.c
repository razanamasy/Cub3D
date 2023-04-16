/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_special_case.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:32:22 by hrazanam          #+#    #+#             */
/*   Updated: 2022/03/14 15:32:26 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

double	dda_hor(int xf, t_perso src_ray, t_game	*game)
{
	t_perso	next_coli;
	t_coord	step;
	int		i;

	i = 0;
	if (double_compare(src_ray.coord.th, 0.0))
		step.x = next_multiple(src_ray.coord.x) - src_ray.coord.x;
	else
		step.x = src_ray.coord.x - last_multiple(src_ray.coord.x);
	next_coli.coord.x = src_ray.coord.x + (xf * step.x);
	next_coli.coord.y = src_ray.coord.y;
	next_coli.coord.th = src_ray.coord.th;
	while (!collision_hor(game, next_coli.coord))
	{
		next_coli.coord.x += (xf * 64);
		next_coli.coord.y += 0;
		i++;
	}
	game->col.coord.x = next_coli.coord.x;
	game->col.coord.y = game->perso.coord.y;
	return (fabs(next_coli.coord.x - src_ray.coord.x));
}

double	dda_vert(int yf, t_perso src_ray, t_game	*game)
{
	t_perso	next_coli;
	t_coord	step;
	int		i;

	i = 0;
	if (double_compare(src_ray.coord.th, M_PI / 2.0))
		step.y = src_ray.coord.y - last_multiple(src_ray.coord.y);
	else
		step.y = next_multiple(src_ray.coord.y) - src_ray.coord.y;
	next_coli.coord.x = src_ray.coord.x;
	next_coli.coord.y = src_ray.coord.y + (yf * step.y);
	next_coli.coord.th = src_ray.coord.th;
	while (!collision_ver(game, next_coli.coord))
	{
		next_coli.coord.x += 0;
		next_coli.coord.y += (yf * 64);
		i++;
	}
	game->col.coord.x = game->perso.coord.x;
	game->col.coord.y = game->perso.coord.y;
	return (fabs(next_coli.coord.y - src_ray.coord.y));
}

double	process_dda_nsew(t_perso src_ray, t_game	*game)
{
	double	hit_lenght;

	if (double_compare(src_ray.coord.th, 0.0))
	{
		hit_lenght = dda_hor(1, src_ray, game);
		game->col.side_hit = 2;
	}
	if (double_compare(src_ray.coord.th, M_PI / 2.0))
	{
		hit_lenght = dda_vert(-1, src_ray, game);
		game->col.side_hit = 0;
	}
	if (double_compare(src_ray.coord.th, M_PI))
	{
		hit_lenght = dda_hor(-1, src_ray, game);
		game->col.side_hit = 3;
	}
	if (double_compare(src_ray.coord.th, (3.0 * (M_PI / 2.0))))
	{
		hit_lenght = dda_vert(1, src_ray, game);
		game->col.side_hit = 1;
	}
	return (fabs(hit_lenght));
}
