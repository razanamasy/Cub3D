/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:56:18 by hrazanam          #+#    #+#             */
/*   Updated: 2022/03/14 15:58:34 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	left_special(double *dec, t_game *game)
{
	if (get_cadran(game->perso.th_dir) == 10)
		dec[1] = DP;
	if (get_cadran(game->perso.th_dir) == 20)
		dec[0] = DP;
	if (get_cadran(game->perso.th_dir) == 30)
		dec[1] = -DP;
	if (get_cadran(game->perso.th_dir) == 40)
		dec[0] = -DP;
}

void	left_general(double *dec, t_game *game, double *th_calc)
{
	if (get_cadran(game->perso.th_dir) == 1)
	{
		dec[0] = (cos(*th_calc) * DP);
		dec[1] = (sin(*th_calc) * DP);
	}
	if (get_cadran(game->perso.th_dir) == 2)
	{
		dec[0] = (cos(*th_calc) * DP);
		dec[1] = -(sin(*th_calc) * DP);
	}
	if (get_cadran(game->perso.th_dir) == 3)
	{
		dec[0] = -(sin(*th_calc) * DP);
		dec[1] = -(cos(*th_calc) * DP);
	}
	if (get_cadran(game->perso.th_dir) == 4)
	{
		dec[0] = -((cos(*th_calc) * DP));
		dec[1] = +(sin(*th_calc) * DP);
	}
}

int	go_left(t_game *game)
{
	t_coord	dir;
	double	th_calc;
	double	dec[2];

	dec[0] = 0;
	dec[1] = 0;
	th_calc = game->perso.th_dir;
	th_calc = get_leftright_th(game->perso.th_dir);
	get_dir_down(&dir, get_cadran(game->perso.th_dir));
	if (is_special_case(game->perso.th_dir))
		left_special(dec, game);
	else
		left_general(dec, game, &th_calc);
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
