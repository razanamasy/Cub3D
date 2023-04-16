/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <xsaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:14:01 by xsaulnie          #+#    #+#             */
/*   Updated: 2022/03/15 15:48:07 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	adjust_angle(double th, t_point *c, char mod)
{
	if (adjust_spangle(th, c))
		return ;
	if (mod == 'x')
	{
		if (adjust_anglex(th, c))
			return ;
	}
	if (mod == 'y')
	{
		if (adjust_angley(th, c))
			return ;
	}
	return ;
}

int	collisionx(t_game *game, t_coord next_coli)
{
	t_point	p;

	p.y = (int)next_coli.y / 64;
	p.x = (int)next_coli.x / 64;
	adjust_angle(next_coli.th, &p, 'x');
	if (is_wall(game->inf.map, p.x, p.y))
		return (1);
	return (0);
}

int	collision_hor(t_game *game, t_coord next_coli)
{
	int	x;
	int	y;

	x = (int)next_coli.x / 64;
	y = (int)next_coli.y / 64;
	if (double_compare(next_coli.th, M_PI))
	{
		if (is_wall(game->inf.map, x - 1, y))
			return (1);
		return (0);
	}
	if (double_compare(next_coli.th, 0))
	{
		if (is_wall(game->inf.map, x, y))
			return (1);
		return (0);
	}
	return (0);
}

int	collision_ver(t_game *game, t_coord next_coli)
{
	int	x;
	int	y;

	x = (int)next_coli.x / 64;
	y = (int)next_coli.y / 64;
	if (double_compare(next_coli.th, M_PI / 2))
	{
		if (is_wall(game->inf.map, x, y - 1))
			return (1);
		return (0);
	}
	if (double_compare(next_coli.th, 3 * M_PI / 2))
	{
		if (is_wall(game->inf.map, x, y))
			return (1);
		return (0);
	}
	return (0);
}

int	collisiony(t_game *game, t_coord next_coli)
{
	t_point	p;

	p.x = (int)next_coli.x / 64;
	p.y = (int)next_coli.y / 64;
	adjust_angle(next_coli.th, &p, 'y');
	if (is_wall(game->inf.map, p.x, p.y))
		return (1);
	return (0);
}
