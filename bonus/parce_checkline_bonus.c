/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_checkline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <xsaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:12:19 by xsaulnie          #+#    #+#             */
/*   Updated: 2022/03/14 17:12:22 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d_bonus.h"

int	check_limit(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	uncorrect_symb(char *line)
{
	int		i;
	char	c;

	i = 0;
	c = 'a';
	while (line[i] != '\0')
	{
		c = line[i];
		if (!is_posdir(c, 0) && c != ' ' && c != '1' && c != '0')
			return (1);
		i++;
	}
	return (0);
}

int	check_map(char *line, t_inf *inf, int dim)
{
	int	i;
	int	len;

	if (uncorrect_symb(line))
		return (set_err(inf, UNCORRECT), 0);
	len = ft_strlen(line);
	if (len > dim)
		inf->dim[0] = len;
	i = 0;
	if (line[0] != '1' && line[0] != ' ')
		return (0);
	if (line[len - 1] != '1' && line[len - 1] != ' ')
		return (0);
	while (line[i] != '\0')
	{
		if (line[i] == ' ' && (!pre_symb(line, i) || !post_symp(line, i)))
			return (0);
		if (line[i] == '0' && (!pre_symb0(line, i) || !post_symb0(line, i)))
			return (0);
		i++;
	}
	if (addstrlst(&(inf->map), line))
		return (del_inf(inf), exit(1), 1);
	return (1);
}
