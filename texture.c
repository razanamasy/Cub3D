/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <xsaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:38:37 by xsaulnie          #+#    #+#             */
/*   Updated: 2022/03/14 16:38:42 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_texture(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->tex[i].img != NULL)
			mlx_destroy_image(game->vars.mlx, game->tex[i].img);
		i++;
	}
	return ;
}

void	ft_putstr_fd(int fd, char *str)
{
	int	len;

	len = ft_strlen(str);
	write(fd, str, len);
}

void	load_one_texture(t_game *game, int ind)
{
	t_texture	*tex;

	tex = &(game->tex[ind]);
	tex->mlx = game->vars.mlx;
	tex->path = game->inf.texture[ind];
	tex->img = mlx_xpm_file_to_image(tex->mlx, tex->path, &(tex->w), &(tex->h));
	if (tex->img == NULL)
	{
		ft_putstr_fd(2, "error on loading xpm\n");
		exit_window(0, game);
	}
	tex->addr = mlx_get_data_addr(tex->img,
			&tex->bpp, &tex->length, &tex->endian);
}

void	load_texture(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->tex[i].img = NULL;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		load_one_texture(game, i);
		i++;
	}
}
