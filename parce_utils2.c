/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <xsaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:23:50 by xsaulnie          #+#    #+#             */
/*   Updated: 2022/03/14 17:23:51 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	ini_inf(t_inf *inf)
{
	inf->dim[0] = 0;
	inf->dim[1] = 0;
	inf->map = NULL;
	inf->start_pos[0] = -1;
	inf->start_pos[1] = -1;
	inf->start_pos[2] = -1;
	inf->ceiling = -1;
	inf->floor = -1;
	inf->texture[0] = NULL;
	inf->texture[1] = NULL;
	inf->texture[2] = NULL;
	inf->texture[3] = NULL;
	inf->err = NO_ERROR;
}

int	custom_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] && ft_isdigit(str[i]))
	{
		res = 10 * res + (str[i] - '0');
		if (res >= 256)
			return (-1);
		i++;
	}
	if (str[i] != '\0')
		return (-1);
	return (res);
}

int	is_posdir(char c, char cplus)
{
	if (cplus != 0)
	{
		if (c == cplus)
			return (1);
	}
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	load_startpos(t_inf *inf, int i, int j, char c)
{
	if (inf->start_pos[0] != -1)
		return (1);
	inf->start_pos[1] = i;
	inf->start_pos[0] = j;
	if (c == 'N')
		inf->start_pos[2] = 0;
	else if (c == 'S')
		inf->start_pos[2] = 1;
	else if (c == 'E')
		inf->start_pos[2] = 2;
	else if (c == 'W')
		inf->start_pos[2] = 3;
	return (0);
}

int	extention_cub(char *path, t_inf *inf, int *fd)
{
	int	len;

	*fd = open(path, O_RDONLY);
	if (*fd == -1)
		return (set_err(inf, NOFILE), 0);
	len = ft_strlen(path);
	if (len < 4)
		return (0);
	if (path[len - 1] != 'b' || path[len - 2] != 'u')
		return (0);
	if (path[len - 3] != 'c' || path[len - 4] != '.')
		return (0);
	return (1);
}
