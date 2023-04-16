/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_searchsymb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <xsaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:01:33 by xsaulnie          #+#    #+#             */
/*   Updated: 2022/03/14 17:01:34 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

int	pre_symb0(char *str, int ind)
{
	while (ind != -1 && is_posdir(str[ind], '0'))
		ind--;
	if (ind == -1)
		return (0);
	if (str[ind] == '1')
		return (1);
	return (0);
}

int	pre_symb(char *str, int ind)
{
	while (ind != -1 && str[ind] == ' ')
		ind--;
	if (ind == -1 || str[ind] == '1')
		return (1);
	return (0);
}

int	post_symb0(char *str, int ind)
{
	while (str[ind] != '\0' && is_posdir(str[ind], '0'))
		ind++;
	if (str[ind] == '\0')
		return (0);
	if (str[ind] == '1')
		return (1);
	return (0);
}

int	post_symp(char *str, int ind)
{
	while (str[ind] != '\0' && str[ind] == ' ')
		ind++;
	if (str[ind] == '\0' || str[ind] == '1')
		return (1);
	return (0);
}

int	verif_virg(char *format)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(format);
	if (!ft_isdigit(format[0]) || !ft_isdigit(format[len - 1]))
		return (-1);
	while (i < len - 1)
	{
		if (format[i] == ',')
		{
			if (!ft_isdigit(format[i + 1]))
				return (1);
		}
		i++;
	}
	return (0);
}
