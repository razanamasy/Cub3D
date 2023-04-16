/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <xsaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:54:02 by xsaulnie          #+#    #+#             */
/*   Updated: 2022/03/14 12:54:05 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	end_cub_file(int fd, t_inf *inf)
{
	int		ret;
	char	*line;

	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			return (ft_delstr(&line), error_file(inf));
		if (line[0] != '\0')
			return (ft_delstr(&line), 0);
		ft_delstr(&line);
	}
	return (1);
}

int	parce_map_inf(char *path, t_inf *inf, int *fd)
{
	int		ret;
	char	*line;
	int		nb_line;

	if (!extention_cub(path, inf, fd))
		return (set_err(inf, EXTENSION), 0);
	ret = 1;
	nb_line = 0;
	while (ret && nb_line < 6)
	{
		ret = get_next_line(*fd, &line);
		if (ret == -1)
			return (ft_del(&line), error_file(inf));
		if (ret == 0)
			return (ft_del(&line), set_err(inf, FEW), 0);
		ret = correct_texture(line, inf);
		if (ret == 0)
			return (ft_delstr(&line), 0);
		if (ret == 1)
			nb_line++;
		ft_delstr(&line);
	}
	return (1);
}

int	get_first_line(t_inf *inf, int ret, int fd)
{
	char	*line;

	while (ret)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			return (error_file(inf));
		if (line[0] != '\0')
		{
			inf->dim[0] = ft_strlen(line);
			if (!check_map(line, inf, inf->dim[0]))
				return (set_err(inf, HEND), ft_delstr(&line), 0);
			if (!check_limit(line))
				return (set_err(inf, HEND), ft_delstr(&line), 0);
			ft_delstr(&line);
			break ;
		}
		ft_delstr(&line);
	}
	if (ret == 0)
		return (set_err(inf, NO_MAP), 0);
	return (1);
}

int	end_verif(t_inf *inf, int fd, int mod)
{
	if (!check_vertical_map(inf->map, inf))
		return (set_err(inf, VEND), 0);
	if (check_limit(lastlststr(inf->map)->str))
	{
		inf->dim[1] = strlstsize(inf->map);
		if (inf->start_pos[0] == -1)
			return (set_err(inf, NOPOS), 0);
		if (mod)
		{
			if (end_cub_file(fd, inf))
				return (1);
			return (set_err(inf, MORE), 0);
		}
		else
		{
			return (1);
		}
	}
	return (set_err(inf, VEND), 0);
}

int	parce_map(char *path, t_inf *inf)
{
	int		fd;
	int		ret;
	char	*line;

	ret = 1;
	if (!parce_map_inf(path, inf, &fd))
		return (0);
	if (!get_first_line(inf, ret, fd))
		return (0);
	while (ret)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			return (error_file(inf));
		if (line[0] == '\0')
			return (ft_delstr(&line), end_verif(inf, fd, 1));
		if (!check_map(line, inf, inf->dim[0]))
			return (set_err(inf, HEND), ft_delstr(&line), 0);
		ft_delstr(&line);
	}
	return (end_verif(inf, fd, 0));
}
