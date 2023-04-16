/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <xsaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:01:50 by xsaulnie          #+#    #+#             */
/*   Updated: 2022/03/14 18:02:11 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	comp_average(int x, double val)
{
	if (val - x < 1 && val - x > -1)
		return (1);
	return (0);
}

int	in_cub(t_coord x1, t_coord x2, int x, int y)
{
	if (x1.x < x2.x)
	{
		if (x < x1.x || x > x2.x)
			return (0);
	}
	else
	{
		if (x < x2.x || x > x1.x)
			return (0);
	}
	if (x1.y < x2.y)
	{
		if (y < x1.y || y > x2.y)
			return (0);
	}
	else
	{
		if (y < x2.y || y > x1.y)
			return (0);
	}
	return (1);
}

void	draw_vertical(t_game *game, t_coord x1, t_coord x2, int c)
{
	int	deb;
	int	end;
	int	i;

	if (x1.y < x2.y)
	{
		deb = (int)(x1.y);
		end = (int)(x2.y);
	}
	else
	{
		deb = (int)(x2.y);
		end = (int)(x1.y);
	}
	i = deb;
	while (i < end)
	{
		put_to_buff(game, x1.x, i, c);
		i++;
	}
}

void	draw_horizontal(t_game *game, t_coord x1, t_coord x2, int c)
{
	int	deb;
	int	end;
	int	i;

	if (x1.x < x2.x)
	{
		deb = (int)(x1.x);
		end = (int)(x2.x);
	}
	else
	{
		deb = (int)(x2.x);
		end = (int)(x1.x);
	}
	i = deb;
	while (i < end)
	{
		put_to_buff(game, i, x1.y, c);
		i++;
	}
}

void	draw_real_line(t_coord x1, t_coord x2, t_game *game, int c)
{
	double	delta;
	double	b;
	int		i;
	int		j;

	if (double_compare(x1.x, x2.x))
		draw_vertical(game, x1, x2, c);
	if (double_compare(x1.y, x2.y))
		draw_horizontal(game, x1, x2, c);
	delta = (x2.y - x1.y) / (x2.x - x1.x);
	b = x1.y - (delta * x1.x);
	i = 0;
	while (i < 640)
	{
		j = 0;
		while (j < 640)
		{
			if (comp_average(j, delta * i + b) && in_cub(x1, x2, i, j))
				put_to_buff(game, i, j, c);
			j++;
		}
		i++;
	}
}
