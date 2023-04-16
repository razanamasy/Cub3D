/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_rotation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:00:52 by hrazanam          #+#    #+#             */
/*   Updated: 2022/03/14 16:01:32 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	turn_left(t_game *game)
{
	game->perso.coord.th += DG * M_PI / 180;
	game->perso.th_dir += DG * M_PI / 180;
	if (!in_circle(game->perso.th_dir))
	{
		game->perso.coord.th = check_modulo(game->perso.coord.th);
		game->perso.th_dir = game->perso.coord.th;
	}
	scan_ray(game->perso, game);
	return (0);
}

int	turn_right(t_game *game)
{
	game->perso.coord.th -= DG * M_PI / 180;
	game->perso.th_dir -= DG * M_PI / 180;
	if (!in_circle(game->perso.th_dir))
	{
		game->perso.coord.th = check_modulo(game->perso.coord.th);
		game->perso.th_dir = game->perso.coord.th;
	}
	scan_ray(game->perso, game);
	return (0);
}
