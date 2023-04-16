/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cadran.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:11:19 by hrazanam          #+#    #+#             */
/*   Updated: 2022/03/14 17:14:23 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_cadran(double th)
{
	if (double_compare(th, 0.0) || double_compare(th, 2.0 * M_PI))
		return (10);
	else if (double_compare(th, M_PI / 2.0))
		return (20);
	else if (double_compare(th, M_PI))
		return (30);
	else if (double_compare(th, 3.0 * M_PI / 2.0))
		return (40);
	else if (th > 0 && th < M_PI / 2.0)
		return (1);
	else if (th > M_PI / 2.0 && th < M_PI)
		return (2);
	else if (th > M_PI && th < (3.0 * (M_PI / 2.0)))
		return (3);
	else
		return (4);
}

int	in_circle(double ray)
{
	if ((ray >= 2 * M_PI || ray < 0) && (!double_compare(ray, 0.0)))
		return (0);
	return (1);
}

double	check_modulo(double ray)
{
	double	real_ray;

	real_ray = 0.0;
	if (double_compare(ray, 0.0))
		real_ray = 2.0 * M_PI;
	else if (ray > 2 * M_PI)
		real_ray = fabs(ray - 2 * M_PI);
	else if (ray < 0)
		real_ray = fabs(2 * M_PI + ray);
	return (real_ray);
}

int	is_special_case(double th)
{
	if (double_compare(th, 0.0) || double_compare(th, 2.0 * M_PI)
		|| double_compare(th, M_PI / 2.0)
		|| double_compare(th, M_PI)
		|| double_compare(th, 3.0 * M_PI / 2.0))
		return (1);
	else
		return (0);
}

int	is_special_case_simple(double th)
{
	if (double_compare(th, 0.0) || double_compare(th, M_PI / 2.0)
		|| double_compare(th, M_PI)
		|| double_compare(th, 3.0 * M_PI / 2.0))
		return (1);
	else
		return (0);
}
