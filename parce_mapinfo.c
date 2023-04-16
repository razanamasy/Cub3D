/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_mapinfo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <xsaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:58:54 by xsaulnie          #+#    #+#             */
/*   Updated: 2022/03/14 16:58:55 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

int	correctrgbformat(char *format)
{
	char	**rgb;
	int		i;
	int		ret;
	int		c[3];

	i = 0;
	if (verif_virg(format))
		return (-1);
	rgb = ft_split(format, ',');
	if (len_dstr(rgb) != 3)
		return (ft_deldstr(&rgb), -1);
	while (rgb[i])
	{
		ret = custom_atoi(rgb[i]);
		if (ret == -1)
			return (ft_deldstr(&rgb), -1);
		c[i] = ret;
		i++;
	}
	return (ft_deldstr(&rgb), c[0] << 16 | c[1] << 8 | c[2]);
}

int	correct_color(char *dir, char *format, t_inf *inf)
{
	int	ret;

	ret = 0;
	if (ft_strncmp(dir, "F", 1) == 0)
	{
		if (inf->floor != -1)
			return (set_err(inf, MCOL), 0);
		ret = correctrgbformat(format);
		if (ret == -1)
			return (set_err(inf, RGB), 0);
		inf->floor = ret;
		return (1);
	}
	if (ft_strncmp(dir, "C", 1) == 0)
	{
		if (inf->ceiling != -1)
			return (set_err(inf, MCOL), 0);
		ret = correctrgbformat(format);
		if (ret == -1)
			return (set_err(inf, RGB), 0);
		inf->ceiling = ret;
		return (1);
	}
	return (set_err(inf, COL), 0);
}

int	load_texture_path(t_inf *inf, char *format, int i)
{
	int	fd;

	if (inf->texture[i] != NULL)
		return (set_err(inf, MTEX), 0);
	fd = open(format, O_RDONLY);
	if (fd == -1)
		return (set_err(inf, INTEX), 0);
	close(fd);
	inf->texture[i] = ft_strdup(format);
	if (inf->texture[i] == NULL)
		return (del_inf(inf), exit(1), 1);
	return (1);
}

int	correct_direction(char *dir, char *format, t_inf *inf)
{
	if (ft_strlen(dir) > 2)
		return (set_err(inf, DIR), 0);
	if (ft_strncmp(dir, "NO", 2) == 0)
		return (load_texture_path(inf, format, 0));
	if (ft_strncmp(dir, "SO", 2) == 0)
		return (load_texture_path(inf, format, 1));
	if (ft_strncmp(dir, "WE", 2) == 0)
		return (load_texture_path(inf, format, 2));
	if (ft_strncmp(dir, "EA", 2) == 0)
		return (load_texture_path(inf, format, 3));
	if (correct_color(dir, format, inf))
		return (1);
	set_err(inf, DIR);
	return (0);
}

int	correct_texture(char *line, t_inf *inf)
{
	int		i;
	char	**linesp;

	if (line[0] == '\0')
		return (2);
	i = 0;
	linesp = ft_split(line, ' ');
	if (linesp == NULL)
		return (del_inf(inf), exit(1), -1);
	if (len_dstr(linesp) != 2)
		return (mes_sp(linesp, inf), set_err(inf, TEX), ft_deldstr(&linesp), 0);
	if (!correct_direction(linesp[0], linesp[1], inf))
		return (ft_deldstr(&linesp), 0);
	ft_deldstr(&linesp);
	return (1);
}
