/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_upsymb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <xsaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:06:37 by xsaulnie          #+#    #+#             */
/*   Updated: 2022/03/14 17:06:39 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d_bonus.h"

void	change_upc(int ind, t_lststr *cur, char *up_c)
{
	if (ind > (int)(ft_strlen(cur->str)) - 1)
	{
		*up_c = ' ';
	}
	else
	{
		if ((cur->str)[ind] != ' ')
		{
			*up_c = (cur->str)[ind];
		}
	}
}

int	up_symb(t_lststr *map, int nb_line, int ind)
{
	char		up_c;
	int			i;
	t_lststr	*cur;

	if (nb_line == 0)
		return (1);
	cur = map;
	i = 0;
	up_c = ' ';
	while (cur && i < nb_line)
	{
		change_upc(ind, cur, &up_c);
		i++;
		cur = cur->nxt;
	}
	if (cur == NULL)
		return (1);
	if (up_c != '1' && up_c != ' ')
		return (0);
	return (1);
}

void	change_upc0(int ind, t_lststr *cur, char *up_c)
{
	if (ind > (int)(ft_strlen(cur->str)) - 1)
	{
		*up_c = '0';
	}
	else
	{
		if ((cur->str)[ind] != '0')
			*up_c = (cur->str)[ind];
	}
}

int	up_symb0(t_lststr *map, int nb_line, int ind)
{
	char		up_c;
	t_lststr	*cur;
	int			i;

	if (nb_line == 0)
		return (0);
	cur = map;
	i = 0;
	up_c = '0';
	while (cur && i < nb_line)
	{
		change_upc0(ind, cur, &up_c);
		i++;
		cur = cur->nxt;
	}
	if (cur == NULL)
		return (1);
	if (up_c != '1' && !(is_posdir(up_c, 0)))
		return (0);
	return (1);
}
