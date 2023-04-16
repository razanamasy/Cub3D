/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to_buff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <xsaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:05:53 by xsaulnie          #+#    #+#             */
/*   Updated: 2022/03/14 18:06:04 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

char	*get_dstv(t_game *game, int x, int y)
{
	char	*dst;

	dst = game->vars.addr + (y * game->vars.length + x * (game->vars.bpp / 8));
	return (dst);
}

char	*get_dst(t_texture *tex, int x, int y)
{
	char	*dst;

	dst = tex->addr + (y * tex->length + x * (tex->bpp / 8));
	return (dst);
}

void	put_tex_to_buf(t_game *game, t_texture *tex, t_point tix, t_point pix)
{
	char	*dst;
	char	*dstt;
	int		color;

	dst = get_dstv(game, pix.x, pix.y);
	dstt = get_dst(tex, tix.x, tix.y);
	color = *(unsigned int *)dstt;
	*(unsigned int *)dst = color;
}

void	put_to_buff(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->vars.addr + (y * game->vars.length + x * (game->vars.bpp / 8));
	*(unsigned int *)dst = color;
}
