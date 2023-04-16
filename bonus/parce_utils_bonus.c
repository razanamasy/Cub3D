/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <xsaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:32:20 by xsaulnie          #+#    #+#             */
/*   Updated: 2022/03/14 16:32:29 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

char	*ft_strdup(char *str)
{
	int		len;
	char	*res;
	int		i;

	len = ft_strlen(str);
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = str[i];
		i++;
	}
	res[len] = '\0';
	return (res);
}

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	if (len <= 0)
		return (0);
	i = 0;
	while (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i] && i < len &&
			((unsigned char *)s1)[i] && ((unsigned char *)s2)[i])
		i++;
	if (i == len)
		return (0);
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	len_dstr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	mes_sp(char **linesp, t_inf *inf)
{
	if (ft_strncmp(linesp[0], "C", 1) == 0)
		set_err(inf, BADSPC);
	if (ft_strncmp(linesp[0], "F", 1) == 0)
		set_err(inf, BADSPC);
}
