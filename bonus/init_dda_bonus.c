/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dda.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:05:21 by hrazanam          #+#    #+#             */
/*   Updated: 2022/03/14 16:06:21 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	reinit_save(t_perso *src_ray_save, t_perso src_ray)
{
	src_ray_save->coord.x = src_ray.coord.x;
	src_ray_save->coord.y = src_ray.coord.y;
	src_ray_save->coord.th = src_ray.coord.th;
}

void	init_step_coef(t_ddainfo *info, t_perso src_ray, char hor, char vert)
{
	if (vert == 'N')
	{
		info->step_y = src_ray.coord.y - last_multiple(src_ray.coord.y);
		info->yf = -1;
	}
	else
	{
		info->step_y = next_multiple(src_ray.coord.y) - src_ray.coord.y;
		info->yf = 1;
	}
	if (hor == 'E')
	{
		info->step_x = next_multiple(src_ray.coord.x) - src_ray.coord.x;
		info->xf = 1;
	}
	else
	{
		info->step_x = src_ray.coord.x - last_multiple(src_ray.coord.x);
		info->xf = -1;
	}
}

void	init_dist(double theta, char hor, char vert, t_ddainfo *info)
{
	if (vert == 'N' || (vert == 'S' && hor == 'E'))
	{
		info->fdist_x = info->step_y / tan(theta);
		info->dist_x = 64.0 / tan(theta);
		info->fdist_y = info->step_x * tan(theta);
		info->dist_y = 64.0 * tan(theta);
	}
	else if (vert == 'S' && hor == 'W')
	{
		info->fdist_x = info->step_y * tan(theta);
		info->dist_x = 64.0 * tan(theta);
		info->fdist_y = info->step_x / tan(theta);
		info->dist_y = 64.0 / tan(theta);
	}
}

t_ddainfo	init_info(double theta, char hor, char vert, t_perso src_ray)
{
	t_ddainfo	info;

	init_step_coef(&info, src_ray, hor, vert);
	init_dist(theta, hor, vert, &info);
	return (info);
}
