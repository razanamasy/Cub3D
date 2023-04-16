/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <xsaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:21:30 by xsaulnie          #+#    #+#             */
/*   Updated: 2022/03/14 15:21:37 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	color_ceiling(t_game *game, int c)
{
	int	i;
	int	j;

	j = 0;
	while (j < 320)
	{
		i = 0;
		while (i < 640)
		{
			put_to_buff(game, i, j, c);
			i++;
		}
		j++;
	}
}

void	color_floor(t_game *game, int c)
{
	int	i;
	int	j;

	j = 320;
	while (j < 640)
	{
		i = 0;
		while (i < 640)
		{
			put_to_buff(game, i, j, c);
			i++;
		}
		j++;
	}
}

void	color_edges(t_game *game, int c_floor, int c_ceiling)
{
	color_floor(game, c_floor);
	color_ceiling(game, c_ceiling);
}
