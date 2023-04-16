/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <xsaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:34:56 by xsaulnie          #+#    #+#             */
/*   Updated: 2022/03/14 16:35:06 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_lststr	*newlststr(char *str)
{
	t_lststr	*res;

	res = malloc(sizeof(t_lststr));
	if (res == NULL)
		return (NULL);
	res->str = str;
	res->nxt = NULL;
	return (res);
}

t_lststr	*lastlststr(t_lststr *lst)
{
	while (lst)
	{
		if (lst->nxt == NULL)
			return (lst);
		lst = lst->nxt;
	}
	return (lst);
}

void	addlststr(t_lststr **lst, t_lststr *newstr)
{
	if (*lst == NULL)
	{
		*lst = newstr;
		return ;
	}
	lastlststr(*lst)->nxt = newstr;
}

int	addstrlst(t_lststr **lst, char *str)
{
	char		*added;
	t_lststr	*addls;

	added = ft_strdup(str);
	if (added == NULL)
		return (1);
	addls = newlststr(added);
	if (addls == NULL)
		return (1);
	addlststr(lst, addls);
	return (0);
}

int	strlstsize(t_lststr *lst)
{
	int	res;

	if (lst == NULL)
		return (0);
	res = 0;
	while (lst)
	{
		res++;
		lst = lst->nxt;
	}
	return (res);
}
