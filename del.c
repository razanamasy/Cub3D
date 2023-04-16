/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <xsaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:29:32 by xsaulnie          #+#    #+#             */
/*   Updated: 2022/03/14 15:29:40 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	del_inf(t_inf *inf)
{
	int	i;

	i = 0;
	strlstclear(&inf->map);
	while (i < 4)
	{
		if (inf->texture[i] != NULL)
			ft_delstr(&(inf->texture[i]));
		i++;
	}
}

void	ft_delstr(char **str)
{
	if (*str != NULL)
		free(*str);
	*str = NULL;
}

void	ft_deldstr(char ***str)
{
	int	i;

	i = 0;
	if (str == NULL || *str == NULL)
		return ;
	while ((*str)[i])
	{
		ft_delstr(&((*str)[i]));
		i++;
	}
	free(*str);
	*str = NULL;
}

void	strlstclear(t_lststr **lst)
{
	t_lststr	*tmp;

	if (lst == NULL || *lst == NULL)
	{
		return ;
	}
	while (*lst != NULL)
	{
		if (*lst != NULL)
		{
			tmp = (*lst)->nxt;
			if ((*lst)->str != NULL)
				free((*lst)->str);
			free(*lst);
			*lst = NULL;
			*lst = tmp;
		}
	}
	return ;
}
