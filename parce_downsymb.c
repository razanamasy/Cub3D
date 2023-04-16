/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_downsymb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <xsaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:21:21 by xsaulnie          #+#    #+#             */
/*   Updated: 2022/03/14 17:21:25 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	down_symb(t_lststr *map, int nb_line, int ind)
{
	t_lststr	*cur;
	int			i;

	if (nb_line == strlstsize(map) - 1)
		return (1);
	cur = map;
	i = 0;
	while (cur && i < nb_line)
	{
		cur = cur->nxt;
		i++;
	}
	while (cur)
	{
		if (ind > (int)(ft_strlen(cur->str) - 1))
			break ;
		if ((cur->str)[ind] != ' ' && (cur->str)[ind] != '1')
			return (0);
		if ((cur->str)[ind] == '1')
			break ;
		cur = cur->nxt;
	}
	return (1);
}

int	down_symb0(t_lststr *map, int nb_line, int ind)
{
	t_lststr	*cur;
	int			i;

	if (nb_line == strlstsize(map) - 1)
		return (0);
	cur = map;
	i = 0;
	while (cur && i < nb_line)
	{
		cur = cur->nxt;
		i++;
	}
	while (cur)
	{
		if (ind > (int)(ft_strlen(cur->str) - 1))
			return (0);
		if ((cur->str)[ind] == ' ')
			return (0);
		if ((cur->str)[ind] == '1')
			break ;
		cur = cur->nxt;
	}
	return (1);
}
