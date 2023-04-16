/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <xsaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:53:56 by xsaulnie          #+#    #+#             */
/*   Updated: 2022/03/15 15:48:21 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	in_map(t_coord p, t_game *game)
{
	if (p.x > game->inf.dim[0] * 64 || p.x < 0)
		return (0);
	if (p.y > game->inf.dim[1] * 64 || p.y < 0)
		return (0);
	if (double_compare(p.x, game->inf.dim[0] * 64))
		return (0);
	if (double_compare(p.y, game->inf.dim[1] * 64))
		return (0);
	return (1);
}

int	no_map(t_coord p, t_game *game)
{
	int	dec[2];

	dec[0] = 0;
	dec[1] = 0;
	if (!in_map(p, game))
		return (1);
	if (rest(p.x, 64) == 0)
	{
		if (is_wall2(game->inf.map, p.x / 64, p.y / 64))
			return (1);
		if (is_wall2(game->inf.map, p.x / 64 - 1, p.y / 64))
			return (1);
	}
	if (rest(p.y, 64) == 0)
	{
		if (is_wall2(game->inf.map, p.x / 64, p.y / 64))
			return (1);
		if (is_wall2(game->inf.map, p.x / 64, (p.y / 64) - 1))
			return (1);
	}
	if (is_wall2(game->inf.map, p.x / 64, p.y / 64))
		return (1);
	return (0);
}

int	adjust_spangle(double th, t_point *c)
{
	if (th == M_PI / 4)
	{
		c->y = c->y - 1;
		return (1);
	}
	if (th == 3 * M_PI / 4)
	{
		c->y = c->y - 1;
		c->x = c->x - 1;
		return (1);
	}
	if (th == 5 * M_PI / 4)
	{
		c->x = c->x - 1;
		return (1);
	}
	return (0);
}

int	adjust_anglex(double th, t_point *c)
{
	if (th > M_PI / 4 && th < 3 * M_PI / 4)
	{
		c->y = c->y - 1;
		return (1);
	}
	if (th > 3 * M_PI / 4 && th < 5 * M_PI / 4)
	{
		if (th < M_PI)
			c->y = c->y - 1;
		return (1);
	}
	if (th > 5 * M_PI / 4 && th < 7 * M_PI / 4)
		return (1);
	if ((th < M_PI / 4 || th > 7 * M_PI / 4))
	{
		if (th < M_PI / 4)
			c->y = c->y - 1;
		return (1);
	}
	return (0);
}

int	adjust_angley(double th, t_point *c)
{
	if (th > M_PI / 4 && th < 3 * M_PI / 4)
	{
		if (th > M_PI / 2)
			c->x = c->x - 1;
		return (1);
	}
	if (th > 3 * M_PI / 4 && th < 5 * M_PI / 4)
	{
		c->x = c->x - 1;
		return (1);
	}
	if (th > 5 * M_PI / 4 && th < 7 * M_PI / 4)
	{
		if (th < 3 * M_PI / 2)
			c->x = c->x - 1;
		return (1);
	}
	if ((th < M_PI / 4 || th > 7 * M_PI / 4))
		return (1);
	return (0);
}
