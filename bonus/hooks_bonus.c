/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:03:54 by hrazanam          #+#    #+#             */
/*   Updated: 2022/03/14 16:04:48 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	exit_window(int keycode, t_game *game)
{
	(void)keycode;
	del_inf(&game->inf);
	clean_texture(game);
	mlx_destroy_window(game->vars.mlx, game->vars.win);
	mlx_destroy_display(game->vars.mlx);
	free(game->vars.mlx);
	return (exit(0), 0);
}

int	exit_window_bis(t_game *game)
{
	del_inf(&game->inf);
	clean_texture(game);
	mlx_destroy_window(game->vars.mlx, game->vars.win);
	mlx_destroy_display(game->vars.mlx);
	free(game->vars.mlx);
	return (exit(0), 0);
}

void	switch_minimap(t_game *game)
{
	if (game->minimap == 1)
		game->minimap = 0;
	else
		game->minimap = 1;
	scan_ray(game->perso, game);
}

void	hook_process(int keycode, t_game *game)
{
	if (keycode == K_RIGHT)
		turn_right(game);
	if (keycode == K_LEFT)
		turn_left(game);
	if (keycode == K_W)
		go_up(game);
	if (keycode == K_S)
		go_down(game);
	if (keycode == K_A)
		go_right(game);
	if (keycode == K_D)
		go_left(game);
}

int	key_hooks(int keycode, t_game *game)
{
	if (!in_circle(game->perso.th_dir))
	{
		game->perso.coord.th = check_modulo(game->perso.coord.th);
		game->perso.th_dir = check_modulo(game->perso.coord.th);
	}
	if (keycode == K_ESC)
		exit_window(0, game);
	if (keycode == K_M)
		switch_minimap(game);
	hook_process(keycode, game);
	return (0);
}
