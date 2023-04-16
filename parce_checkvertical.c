/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_checkvertical.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <xsaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:14:43 by xsaulnie          #+#    #+#             */
/*   Updated: 2022/03/14 17:15:39 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

int	wrong_space(char c, t_lststr *map, int i, int j)
{
	if (c != ' ')
		return (0);
	if (!up_symb(map, i, j) || !down_symb(map, i, j))
		return (1);
	return (0);
}

int	wrong_zero(char c, t_lststr *map, int i, int j)
{
	if (c != '0')
		return (0);
	if (!up_symb0(map, i, j) || !down_symb0(map, i, j))
		return (1);
	return (0);
}

int	check_vertical_map(t_lststr *map, t_inf *inf)
{
	char		*line;
	t_lststr	*cur;
	int			i;
	int			j;

	i = 0;
	cur = map;
	while (cur)
	{
		line = cur->str;
		j = 0;
		while (line[j] != '\0')
		{
			if (wrong_space(line[j], map, i, j))
				return (set_err(inf, VEND), 0);
			if (wrong_zero(line[j], map, i, j))
				return (set_err(inf, VEND), 0);
			if (is_posdir(line[j], 0) && load_startpos(inf, i, j, line[j]))
				return (set_err(inf, POS), 0);
			j++;
		}	
		cur = cur->nxt;
		i++;
	}
	return (1);
}
