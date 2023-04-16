/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:07:55 by hrazanam          #+#    #+#             */
/*   Updated: 2022/03/14 17:58:18 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	init_size(t_plan *image)
{
	image->width = 640;
	image->height = 640;
	return (1);
}

void	init_main_screen(t_game *game)
{
	game->vars.img = mlx_new_image(game->vars.mlx, 640, 640);
	game->vars.addr = mlx_get_data_addr(game->vars.img,
			&(game->vars.bpp),
			&(game->vars.length), &(game->vars.endian));
	color_edges(game, game->inf.floor, game->inf.ceiling);
}
