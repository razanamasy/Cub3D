/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <xsaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:23:35 by xsaulnie          #+#    #+#             */
/*   Updated: 2022/03/14 18:23:36 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_del(char **p)
{
	free(*p);
	*p = NULL;
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char **s1, char *s2, int endlpos)
{
	char	*res;
	size_t	i;
	size_t	lens1;
	size_t	lens2;

	if (*s1 == NULL || s2 == NULL)
		return (NULL);
	lens1 = ft_strlen(*s1);
	lens2 = ft_strlen(s2);
	i = 0;
	res = ft_calloc(lens1 + endlpos + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	while (i < lens1 + endlpos)
	{
		if (i < lens1)
			res[i] = (*s1)[i];
		else
			res[i] = s2[i - lens1];
		i++;
	}
	res[lens1 + endlpos] = '\0';
	ft_del(s1);
	return (res);
}

char	*emptystr(void)
{
	char	*res;

	res = (char *)malloc(sizeof(char));
	if (res == NULL)
		return (NULL);
	res[0] = '\0';
	return (res);
}

int	ft_endl(char *buf, size_t size)
{
	size_t	i;

	if (buf == NULL)
		return (-1);
	i = 0;
	while (i < size && buf[i] != '\0')
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
