/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <xsaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:24:32 by xsaulnie          #+#    #+#             */
/*   Updated: 2022/03/14 16:24:45 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	addones(t_lststr *lst, int len)
{
	char	*cpy;
	char	*one;

	cpy = ft_strdup(lst->str);
	if (cpy == NULL)
		return (1);
	one = ones(len);
	if (one == NULL)
		return (ft_delstr(&cpy), 1);
	ft_delstr(&(lst->str));
	lst->str = ft_strjoino(cpy, one);
	if (lst->str == NULL)
		return (ft_delstr(&cpy), ft_delstr(&one), 1);
	return (ft_delstr(&cpy), ft_delstr(&one), 0);
}

t_lststr	*extract_line(t_lststr *map, int l)
{
	int	i;

	i = 0;
	if (l == 0)
		return (map);
	while (i < l)
	{
		map = map->nxt;
		i++;
	}
	return (map);
}

int	modify_map(t_inf *inf, t_lststr *map)
{
	t_lststr	*cur;
	int			len;

	cur = map;
	while (cur)
	{
		modone(&(cur->str));
		len = ft_strlen(cur->str);
		if (len < inf->dim[0])
		{
			if (addones(cur, inf->dim[0] - len))
				return (del_inf(inf), exit(1), 1);
		}
		cur = cur->nxt;
	}
	return (0);
}

char	*str_ones(int nb)
{
	int		i;
	char	*res;

	i = 0;
	res = malloc(sizeof(char) * (nb + 1));
	if (res == NULL)
		return (NULL);
	while (i < nb)
	{
		res[i] = '1';
		i++;
	}
	res[i] = '\0';
	return (res);
}
