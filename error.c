/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <xsaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:17:26 by xsaulnie          #+#    #+#             */
/*   Updated: 2022/03/14 16:17:39 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_err(t_inf *inf, t_err err)
{
	if (inf->err == NO_ERROR || err == MORE)
		inf->err = err;
	return ;
}

void	check_firsterr(t_err err)
{
	if (err == EXTENSION)
		ft_putstr_fd(2, "error: map file not a .cub extension\n");
	if (err == FEW)
		ft_putstr_fd(2, "error: too few informaton about the map\n");
	if (err == TEX)
		ft_putstr_fd(2, "error: incorrect texture format\n");
	if (err == DIR)
		ft_putstr_fd(2, "error: texture direction incorrect\n");
	if (err == RGB)
		ft_putstr_fd(2, "error: rgb format incorrect\n");
	if (err == COL)
		ft_putstr_fd(2, "error: wrong color name\n");
	if (err == NO_MAP)
		ft_putstr_fd(2, "error: no map on the file\n");
	if (err == HEND)
		ft_putstr_fd(2, "error: map not closed\n");
	if (err == MORE)
		ft_putstr_fd(2, "error: other informations after the map\n");
	if (err == VEND)
		ft_putstr_fd(2, "error: map not closed\n");
	if (err == POS)
		ft_putstr_fd(2, "error: wrong start position\n");
}

void	check_seconderr(t_err err)
{
	if (err == UNCORRECT)
		ft_putstr_fd(2, "error: uncorrect symbol on the map\n");
	if (err == NO_ERROR)
		ft_putstr_fd(2, "error: print_error bug !\n");
	if (err == MCOL)
		ft_putstr_fd(2, "error: missing a color on the file\n");
	if (err == MTEX)
		ft_putstr_fd(2, "error: missing texture on the file\n");
	if (err == INTEX)
		ft_putstr_fd(2, "error: incorrect texture file\n");
	if (err == NOFILE)
		ft_putstr_fd(2, "error: unable to open file\n");
	if (err == NOPOS)
		ft_putstr_fd(2, "error: missing player posision\n");
	if (err == BADSPC)
		ft_putstr_fd(2,
			"error: bad spacing for color, format must be RRR,GGG,BBB\n");
}

void	print_err(t_err err)
{
	check_firsterr(err);
	check_seconderr(err);
	return ;
}

int	error_file(t_inf *inf)
{
	ft_putstr_fd(2, "error: problem reading file\n");
	del_inf(inf);
	exit(1);
	return (1);
}
