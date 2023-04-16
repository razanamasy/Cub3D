/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <xsaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:30:25 by xsaulnie          #+#    #+#             */
/*   Updated: 2022/03/14 16:30:37 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	turn_mouse_left(t_game *game, int dp)
{
	game->perso.coord.th += 0.00122718463031 * dp;
	game->perso.th_dir += 0.00122718463031 * dp;
	if (!in_circle(game->perso.th_dir))
	{
		game->perso.coord.th = check_modulo(game->perso.coord.th);
		game->perso.th_dir = game->perso.coord.th;
	}
	scan_ray(game->perso, game);
	return (0);
}

int	turn_mouse_right(t_game *game, int dp)
{
	game->perso.coord.th -= 0.00122718463031 * dp;
	game->perso.th_dir -= 0.00122718463031 * dp;
	if (!in_circle(game->perso.th_dir))
	{
		game->perso.coord.th = check_modulo(game->perso.coord.th);
		game->perso.th_dir = game->perso.coord.th;
	}
	scan_ray(game->perso, game);
	return (0);
}

int	mouse_move(int x, int y, t_game *game)
{
	t_point	p;

	if ((x == 320 && y == 320))
		return (0);
	if (game->moved == 1)
	{
		game->moved = 0;
		return (0);
	}
	if (x < 50 || y < 50 || x > 590 || y > 590)
	{
		game->mouse.x = 320;
		game->mouse.y = 320;
		game->moved = 1;
		return (mlx_mouse_move(game->vars.mlx, game->vars.win, 320, 320), 0);
	}
	p.x = game->mouse.x - x;
	p.y = game->mouse.x - y;
	if (p.x > 0)
		turn_mouse_left(game, p.x);
	else
		turn_mouse_right(game, -p.x);
	game->mouse.x = x;
	game->mouse.y = y;
	return (0);
}

int	center_mouse(int button, int x, int y, t_game *game)
{
	(void)button;
	if (x != 340 && y != 340)
		mlx_mouse_move(game->vars.mlx, game->vars.win, 320, 320);
	return (0);
}
