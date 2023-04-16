/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:58:29 by hrazanam          #+#    #+#             */
/*   Updated: 2022/03/14 17:40:25 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	on_grid(t_perso perso, t_lststr *map)
{
	int	x;
	int	y;

	x = (int)perso.coord.x / 64;
	y = (int)perso.coord.y / 64;
	if ((int)perso.coord.x % 64 == 0)
	{
		if (extract_map(map, x, y) == '1'
			|| extract_map(map, x - 1, y) == '1')
			return (1);
	}
	if ((int)perso.coord.y % 64 == 0)
	{
		if (extract_map(map, x, y) == '1'
			|| extract_map(map, x, y - 1) == '1')
			return (1);
	}
	if ((int)perso.coord.x % 64 == 0 && (int)perso.coord.y % 64 == 0)
		if (extract_map(map, x - 1, y - 1) == '1')
			return (1);
	return (0);
}

void	first_half(t_perso *src_ray_save, t_game *game, double *ret, int i)
{
	src_ray_save->coord.th += 0.00122718463031;
	if (!in_circle(src_ray_save->coord.th))
		src_ray_save->coord.th = check_modulo(src_ray_save->coord.th);
	*ret = ft_dda(*src_ray_save, game);
	draw_textured_wall(51300 / *ret, i + 319,
		game, &(game->tex[game->col.side_hit]));
}

void	second_half(t_perso *src_ray_save, t_game *game, double *ret, int i)
{
	src_ray_save->coord.th -= 0.00122718463031;
	if (!in_circle(src_ray_save->coord.th))
		src_ray_save->coord.th = check_modulo(src_ray_save->coord.th);
	*ret = ft_dda(*src_ray_save, game);
	draw_textured_wall(51300 / *ret, 321 + i,
		game, &(game->tex[game->col.side_hit]));
}

void	draw_each_ray(t_perso src_ray, t_game *game, double ret)
{
	int		i;
	t_perso	src_ray_save;

	i = 0;
	src_ray_save = src_ray;
	draw_textured_wall(51300 / ret, 320, game,
		&(game->tex[game->col.side_hit]));
	while (i > -320)
	{
		first_half(&src_ray_save, game, &ret, i);
		i--;
	}
	src_ray_save = src_ray;
	i = 0;
	while (i < 319)
	{
		second_half(&src_ray_save, game, &ret, i);
		i++;
	}
}

void	scan_ray(t_perso src_ray, t_game *game)
{
	double	ret;
	t_perso	src_ray_save;

	src_ray_save = src_ray;
	init_main_screen(game);
	if (extract_map(game->inf.map, game->perso.coord.x / 64,
			game->perso.coord.y / 64) == '1'
		|| on_grid(game->perso, game->inf.map)
		|| !in_map(game->perso.coord, game))
	{
		black_screen(game);
		mlx_destroy_image(game->vars.mlx, game->vars.img);
		return ;
	}
	if (!in_circle(src_ray_save.coord.th))
		src_ray_save.coord.th = check_modulo(src_ray_save.coord.th);
	ret = ft_dda(src_ray_save, game);
	draw_each_ray(src_ray, game, ret);
	mlx_put_image_to_window(game->vars.mlx, game->vars.win,
		game->vars.img, 0, 0);
	mlx_destroy_image(game->vars.mlx, game->vars.img);
}
