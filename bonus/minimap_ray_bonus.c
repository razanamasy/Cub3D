/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:41:20 by hrazanam          #+#    #+#             */
/*   Updated: 2022/03/14 16:56:02 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	super_ray(t_game *game, double thdir, int deg)
{
	t_coord	p;
	t_coord	d;

	p.x = 70;
	p.y = 70;
	d.x = cos(thdir);
	d.y = -sin(thdir);
	while (*(unsigned int *)get_dstv(game, (int)p.x, (int)p.y) != WHITE
		&& (int)p.x < 127
		&& (int)p.y < 127 && (int)p.x > 0 && (int)p.y > 0)
	{
		put_to_buff(game, (int)p.x, (int)p.y, RED - (deg << 16));
		p.x += d.x;
		p.y += d.y;
	}
}

void	all_super_ray(t_game *game, double thdir)
{
	int		i;
	double	th;

	th = thdir;
	i = 0;
	super_ray(game, thdir, 0);
	while (i < 320)
	{
		th += 0.00122718463031;
		super_ray(game, th, i / 2);
		i++;
	}
	th = thdir;
	i = 0;
	while (i < 319)
	{
		th -= 0.00122718463031;
		super_ray(game, th, i / 2);
		i++;
	}
}

void	attr_vec_hor(double theta, t_coord org, t_coord *vec)
{
	if (double_compare(theta, 0))
	{
		vec->x = org.x + 20;
		vec->y = org.y;
	}
	else if (double_compare(theta, M_PI))
	{
		vec->x = org.x - 20;
		vec->y = org.y;
	}
}

void	attr_vec_vert(double theta, t_coord org, t_coord *vec)
{
	if (double_compare(theta, M_PI / 2))
	{
		vec->x = org.x;
		vec->y = org.y - 20;
	}
	else if (double_compare(theta, 3 * M_PI / 2))
	{
		vec->x = org.x;
		vec->y = org.y + 20;
	}
}

void	magic_wand(t_perso src_ray, t_game *game)
{
	t_coord	vec;
	t_coord	org;

	org.x = 70;
	org.y = 70;
	if (double_compare(src_ray.th_dir, 0)
		|| double_compare(src_ray.th_dir, M_PI))
		attr_vec_hor(src_ray.th_dir, org, &vec);
	else if (double_compare(src_ray.th_dir, M_PI / 2)
		|| double_compare(src_ray.th_dir, 3 * M_PI / 2))
		attr_vec_vert(src_ray.th_dir, org, &vec);
	else
	{
		vec.x = org.x + 20 * cos(src_ray.th_dir);
		vec.y = org.y - 20 * sin(src_ray.th_dir);
	}
	draw_real_line(org, vec, game, YELLOW);
}
