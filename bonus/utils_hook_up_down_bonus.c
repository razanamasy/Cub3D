/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hook_up_down.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:21:36 by hrazanam          #+#    #+#             */
/*   Updated: 2022/03/14 17:22:06 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

double	get_updown_th(double th)
{
	double	th_calc;

	if (th > 0 && th < M_PI / 2.0)
		th_calc = th;
	else if (th > M_PI / 2.0 && th < M_PI)
		th_calc = M_PI - th;
	else if (th > M_PI && th < (3.0 * (M_PI / 2.0)))
		th_calc = th - M_PI;
	else
		th_calc = 2.0 * M_PI - th;
	return (th_calc);
}

void	get_dir_up(t_coord *dir, int cadran)
{
	if (cadran == 1)
	{
		dir->x = 1;
		dir->y = -1;
	}
	else if (cadran == 2)
	{
		dir->x = -1;
		dir->y = -1;
	}
	else if (cadran == 3)
	{
		dir->x = 1;
		dir->y = -1;
	}
	else
	{
		dir->x = -1;
		dir->y = -1;
	}
}

void	get_dir_down(t_coord *dir, int cadran)
{
	if (cadran == 1)
	{
		dir->x = -1;
		dir->y = 1;
	}
	else if (cadran == 2)
	{
		dir->x = 1;
		dir->y = 1;
	}
	else if (cadran == 3)
	{
		dir->x = -1;
		dir->y = 1;
	}
	else if (cadran == 4)
	{
		dir->x = 1;
		dir->y = 1;
	}
}
