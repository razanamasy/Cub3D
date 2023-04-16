/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hook_left_right.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:20:54 by hrazanam          #+#    #+#             */
/*   Updated: 2022/03/14 17:21:18 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

double	get_leftright_th(double th)
{
	double	th_calc;

	if (th > 0 && th < M_PI / 2.0)
		th_calc = (M_PI / 2.0) - th;
	else if (th > M_PI / 2.0 && th < M_PI)
		th_calc = th - (M_PI2);
	else if (th > M_PI && th < (3.0 * (M_PI / 2.0)))
		th_calc = th - M_PI;
	else
		th_calc = th - 3.0 * M_PI / 2.0;
	return (th_calc);
}
