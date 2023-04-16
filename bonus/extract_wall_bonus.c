/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <xsaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:56:48 by xsaulnie          #+#    #+#             */
/*   Updated: 2022/03/14 17:56:59 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

char	extract_map(t_lststr *map, int x, int y)
{
	int	i;

	i = 0;
	while (map && i < y)
	{
		map = map->nxt;
		i++;
	}
	return ((map->str)[x]);
}

int	is_wall1(t_lststr *map, int x, int y)
{
	char	c;

	c = extract_map(map, x, y);
	if (c == '1')
		return (1);
	return (0);
}

int	is_wall2(t_lststr *map, int x, int y)
{
	char	c;

	c = extract_map(map, x, y);
	if (c == '2' || c == '1')
		return (2);
	return (0);
}

int	is_wall(t_lststr *map, int x, int y)
{
	char	c;

	c = extract_map(map, x, y);
	if (c == '1' || c == '2')
		return (1);
	return (0);
}
