/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_search_hit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:11:07 by hrazanam          #+#    #+#             */
/*   Updated: 2022/03/14 18:21:01 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	case_xy(t_coord coli, t_game *game, char mod)
{
	if (mod == 'y')
	{
		if (coli.th < M_PI)
		{
			game->col.side_hit = 0;
			return ;
		}
		game->col.side_hit = 1;
		return ;
	}
	else
	{
		if (coli.th > M_PI / 2 && coli.th < 3 * M_PI / 2)
		{
			game->col.side_hit = 3;
			return ;
		}
		game->col.side_hit = 2;
		return ;
	}
}

void	search_side_hit(t_coord coli, t_game *game, char mod)
{
	game->col.coord.x = coli.x;
	game->col.coord.y = coli.y;
	if ((int)(coli.y) % 64 == 0 && (int)(coli.x) % 64 == 0)
		return (case_xy(coli, game, mod));
	if ((int)(coli.y) % 64 == 0)
	{
		if (coli.th < M_PI)
		{
			game->col.side_hit = 0;
			return ;
		}
		game->col.side_hit = 1;
		return ;
	}
	if ((int)(coli.x) % 64 == 0)
	{
		if (coli.th > M_PI / 2 && coli.th < 3 * M_PI / 2)
		{
			game->col.side_hit = 3;
			return ;
		}
		game->col.side_hit = 2;
		return ;
	}
}
