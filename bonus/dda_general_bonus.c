/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_general.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:39:22 by hrazanam          #+#    #+#             */
/*   Updated: 2022/03/14 15:39:25 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

double	dda_ifmove_y(t_ddainfo info, t_perso src_ray, t_game	*game)
{
	int	i;

	i = 0;
	game->next_coli1.coord.x = src_ray.coord.x + (info.xf * info.fdist_x);
	game->next_coli1.coord.y = src_ray.coord.y + (info.yf * info.step_y);
	game->next_coli1.coord.th = src_ray.coord.th;
	if (!in_map(game->next_coli1.coord, game))
		return (0);
	while (!collisionx(game, game->next_coli1.coord))
	{
		game->next_coli1.coord.x += (info.xf * info.dist_x);
		game->next_coli1.coord.y += (info.yf * 64);
		if (!in_map(game->next_coli1.coord, game))
			return (0);
		i++;
	}
	return (hypo_add(src_ray, game->next_coli1));
}

double	dda_ifmove_x(t_ddainfo info, t_perso src_ray, t_game	*game)
{
	int	i;

	i = 0;
	game->next_coli2.coord.x = src_ray.coord.x + (info.xf * info.step_x);
	game->next_coli2.coord.y = src_ray.coord.y + (info.yf * info.fdist_y);
	game->next_coli2.coord.th = src_ray.coord.th;
	if (!in_map(game->next_coli2.coord, game))
		return (0);
	while (!collisiony(game, game->next_coli2.coord))
	{
		game->next_coli2.coord.x += (info.xf * 64.0);
		game->next_coli2.coord.y += (info.yf * info.dist_y);
		if (!in_map(game->next_coli2.coord, game))
			return (0);
		i++;
	}
	return (hypo_add(src_ray, game->next_coli2));
}

double	select_hypo(double hypo1, double hypo2, t_game	*game, int mode)
{
	if (hypo1 > 0)
	{
		if (mode == 1)
			search_side_hit(game->next_coli1.coord, game, 'y');
		else
			search_side_hit(game->next_coli2.coord, game, 'x');
		return (hypo1);
	}
	else
	{
		if (mode == 1)
			search_side_hit(game->next_coli2.coord, game, 'x');
		else
			search_side_hit(game->next_coli1.coord, game, 'y');
		return (hypo2);
	}
}

double	process_dda(t_ddainfo info, t_perso src_ray, t_game	*game)
{
	double	hypo[2];

	hypo[0] = dda_ifmove_y(info, src_ray, game);
	hypo[1] = dda_ifmove_x(info, src_ray, game);
	if (hypo[1] >= hypo[0])
		return (select_hypo(hypo[0], hypo[1], game, 1));
	else
		return (select_hypo(hypo[1], hypo[0], game, 2));
}

double	ft_dda(t_perso src_ray, t_game	*game)
{
	t_ddainfo	info;
	double		hit_lenght;

	if (is_special_case_simple(src_ray.coord.th))
	{
		hit_lenght = process_dda_nsew(src_ray, game);
		return (hit_lenght);
	}
	else if (src_ray.coord.th > 0 && src_ray.coord.th < M_PI / 2.0)
		info = init_info(src_ray.coord.th, 'E', 'N', src_ray);
	else if (src_ray.coord.th > M_PI / 2.0 && src_ray.coord.th < M_PI)
		info = init_info(M_PI - src_ray.coord.th, 'W', 'N', src_ray);
	else if (src_ray.coord.th > M_PI && src_ray.coord.th < (3.0 * (M_PI / 2.0)))
		info = init_info((3.0 * (M_PI / 2.0))
				- src_ray.coord.th, 'W', 'S', src_ray);
	else
		info = init_info(2.0 * M_PI - src_ray.coord.th, 'E', 'S', src_ray);
	hit_lenght = process_dda(info, src_ray, game);
	return (hit_lenght);
}
