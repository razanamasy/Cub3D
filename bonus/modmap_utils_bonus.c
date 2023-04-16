/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modmap_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <xsaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:11:06 by xsaulnie          #+#    #+#             */
/*   Updated: 2022/03/14 18:11:24 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

char	*ft_strjoino(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	lens1;
	size_t	lens2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	lens1 = ft_strlen((char *)s1);
	lens2 = ft_strlen((char *)s2);
	i = 0;
	res = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (res == NULL)
		return (NULL);
	while (i < lens1 + lens2 + 1)
	{
		if (i < lens1)
			res[i] = s1[i];
		else
			res[i] = s2[i - lens1];
		i++;
	}
	res[lens1 + lens2] = '\0';
	return (res);
}

char	*ones(int len)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	while (i < len)
	{
		res[i] = '2';
		i++;
	}
	res[i] = '\0';
	return (res);
}

void	modone(char **str)
{
	int	i;

	i = 0;
	while ((*str)[i] != '\0')
	{
		if ((*str)[i] == ' ')
			(*str)[i] = '2';
		i++;
	}
}
