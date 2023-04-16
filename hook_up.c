/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:01:56 by hrazanam          #+#    #+#             */
/*   Updated: 2022/03/14 16:03:18 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	up_special(double *dec, t_game *game)
{
	if (get_cadran(game->perso.th_dir) == 10)
		dec[0] = DP;
	if (get_cadran(game->perso.th_dir) == 20)
		dec[1] = -DP;
	if (get_cadran(game->perso.th_dir) == 30)
		dec[0] = -DP;
	if (get_cadran(game->perso.th_dir) == 40)
		dec[1] = DP;
}

void	up_general(double *dec, t_game *game, t_coord *dir, double *th_calc)
{
	*th_calc = get_updown_th(game->perso.th_dir);
	get_dir_up(dir, get_cadran(game->perso.th_dir));
	if (get_cadran(game->perso.th_dir) == 1
		|| get_cadran(game->perso.th_dir) == 2)
	{
		dec[0] = dir->x * (cos(*th_calc) * DP);
		dec[1] = dir->y * (sin(*th_calc) * DP);
	}
	else
	{
		dec[0] = -dir->x * (cos(*th_calc) * DP);
		dec[1] = -dir->y * (sin(*th_calc) * DP);
	}
}

int	go_up(t_game *game)
{
	t_coord	dir;
	double	th_calc;
	double	dec[2];

	dec[0] = 0;
	dec[1] = 0;
	th_calc = game->perso.th_dir;
	if (is_special_case(game->perso.th_dir))
		up_special(dec, game);
	else
		up_general(dec, game, &dir, &th_calc);
	game->perso.coord.x += dec[0];
	game->perso.coord.y += dec[1];
	if (no_map(game->perso.coord, game))
	{
		game->perso.coord.x -= dec[0];
		game->perso.coord.y -= dec[1];
	}
	scan_ray(game->perso, game);
	return (0);
}
