/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:59:48 by hrazanam          #+#    #+#             */
/*   Updated: 2022/03/14 18:10:27 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_perso(t_inf *inf, t_perso *perso)
{
	perso->coord.x = inf->start_pos[0] * 64 + 32;
	perso->coord.y = inf->start_pos[1] * 64 + 32;
	if (inf->start_pos[2] == 0)
	{
		perso->coord.th = M_PI2;
		perso->th_dir = M_PI2;
	}
	if (inf->start_pos[2] == 1)
	{
		perso->coord.th = M_3PI2;
		perso->th_dir = M_3PI2;
	}
	if (inf->start_pos[2] == 2)
	{
		perso->coord.th = 0;
		perso->th_dir = 0;
	}
	if (inf->start_pos[2] == 3)
	{
		perso->coord.th = M_PI;
		perso->th_dir = M_PI;
	}
	return (0);
}

int	wrong_argument(void)
{
	ft_putstr_fd(2, "error: cub3d bad argument\n");
	return (1);
}

void	init_game(t_game *game, t_plan	*image)
{
	load_perso(&(game->inf), &(game->perso));
	init_size(image);
	game->vars.mlx = mlx_init();
	game->vars.win = mlx_new_window(game->vars.mlx, 640, 640, "cub3d");
	load_texture(game);
	game->moved = 0;
	game->moved = 0;
	game->mouse.x = 320;
	game->mouse.y = 320;
}

int	main(int argc, char **argv)
{
	int		ret;
	t_plan	image;
	t_game	game;

	ini_inf(&game.inf);
	if (argc != 2)
		return (wrong_argument());
	ret = parce_map(argv[1], &game.inf);
	if (!ret)
		return (del_inf(&game.inf), print_err(game.inf.err), 1);
	modify_map(&(game.inf), game.inf.map);
	init_game(&game, &image);
	scan_ray(game.perso, &game);
	mlx_hook(game.vars.win, 17, 1L << 17, &exit_window_bis, &game);
	mlx_hook(game.vars.win, 2, 1 << 0, &key_hooks, &game);
	mlx_loop(game.vars.mlx);
	return (0);
}
