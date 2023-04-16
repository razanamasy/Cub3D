/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:14:46 by hrazanam          #+#    #+#             */
/*   Updated: 2022/03/14 17:20:28 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	hypo_add(t_perso src_ray, t_perso next_coli)
{
	double	hypo;
	double	length;

	hypo = 0;
	hypo = sqrt((fabs(next_coli.coord.x - src_ray.coord.x))
			* fabs(next_coli.coord.x - src_ray.coord.x)
			+ fabs(next_coli.coord.y - src_ray.coord.y)
			* fabs(next_coli.coord.y - src_ray.coord.y));
	length = hypo * cos(fabs(next_coli.coord.th - src_ray.th_dir));
	return (length);
}

int	next_multiple(double nb)
{
	int	multiple;

	multiple = 64 * ((int)(nb + 1) / 64);
	if (multiple < nb)
		multiple += 64;
	return (multiple);
}

int	last_multiple(double nb)
{
	int	multiple;

	multiple = 64 * ((int)(nb + 1) / 64);
	if (multiple > nb)
		multiple -= 64;
	return (multiple);
}

int	double_compare(double th1, double th2)
{
	double	res;

	res = fabs(th1 - th2);
	if (res <= 0.0001)
		return (1);
	else
		return (0);
}
