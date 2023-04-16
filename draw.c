/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <xsaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:59:46 by xsaulnie          #+#    #+#             */
/*   Updated: 2022/03/14 16:00:20 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	black_screen(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < 640)
	{
		j = 0;
		while (j < 640)
		{
			put_to_buff(game, i, j, BLACK);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(game->vars.mlx,
		game->vars.win, game->vars.img, 0, 0);
}

float	rest(float f, int nb)
{
	float	quot;

	quot = (int)(f / nb);
	return ((f - quot * nb));
}

void	load_texelx(t_game *game, t_point *tix)
{
	if (game->col.side_hit == 0 || game->col.side_hit == 1)
		tix->x = (int)(rest(game->col.coord.x, 64));
	if ((game->col.side_hit == 2 || game->col.side_hit == 3))
		tix->x = (int)(rest(game->col.coord.y, 64));
}

void	load_pixely(int len, t_point *pix, int *end)
{
	int	ofset;

	if (len > 640)
	{
		pix->y = 0;
		*end = 640;
	}
	else
	{
		ofset = 320 - len / 2;
		pix->y = ofset;
		*end = len + ofset;
	}
}

void	draw_textured_wall(int len, int x, t_game *game, t_texture *tex)
{
	t_point	tix;
	t_point	pix;
	double	i;
	double	dpy;
	int		end;

	dpy = 64.0 / len;
	load_texelx(game, &tix);
	load_pixely(len, &pix, &end);
	if (len > 640)
		i = ((len - 640) / 2) * dpy;
	else
		i = 0;
	pix.x = x;
	while (pix.y < end)
	{
		tix.y = (int)(i);
		put_tex_to_buf(game, tex, tix, pix);
		i += dpy;
		pix.y++;
	}
	return ;
}
