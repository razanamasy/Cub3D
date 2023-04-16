/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <xsaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:23:25 by xsaulnie          #+#    #+#             */
/*   Updated: 2022/03/15 16:59:06 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#define BUFFER_SIZE 16384

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*res;
	size_t	total_size;

	i = 0;
	total_size = size * nmemb;
	res = (void *)malloc(total_size);
	if (res == NULL)
		return (NULL);
	while (i < total_size)
	{
		((unsigned char *)(res))[i] = 0;
		i++;
	}
	return (res);
}

void	restbuf(char *buf, int endl, int size)
{
	int	i;

	if (buf == NULL)
		return ;
	i = 0;
	while (i < size - endl)
	{
		buf[i] = buf[i + endl + 1];
		i++;
	}
	buf[i] = '\0';
}

int	ft_aff(char **line, char *buf, int endlpos)
{
	*line = ft_strjoin(line, buf, endlpos);
	if (*line == NULL)
	{
		ft_del(line);
		return (-1);
	}
	return (0);
}

int	ft_readline(int fd, char *buf, int endlpos, char **line)
{
	int	ret;

	ret = 1;
	while (ret)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			ft_del(line);
			return (-1);
		}
		buf[ret] = '\0';
		endlpos = ft_endl(buf, BUFFER_SIZE);
		if (endlpos != -1)
		{
			if (ft_aff(line, buf, endlpos) == -1)
				return (-1);
			restbuf(buf, endlpos, BUFFER_SIZE);
			return (1);
		}
		else if (ft_aff(line, buf, ft_strlen(buf)) == -1)
			return (-1);
	}
	buf[0] = '\0';
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char static	buf[BUFFER_SIZE + 1];
	int			endlpos;

	if (BUFFER_SIZE <= 0 || line == NULL || fd < 0)
		return (-1);
	*line = emptystr();
	if (*line == NULL)
		return (-1);
	endlpos = ft_endl(buf, BUFFER_SIZE);
	if (endlpos != -1)
	{
		if (ft_aff(line, buf, endlpos) == -1)
			return (-1);
		restbuf(buf, endlpos, BUFFER_SIZE);
		return (1);
	}
	else if (buf[0] != '\0')
	{
		if (ft_aff(line, buf, ft_strlen(buf)) == -1)
			return (-1);
	}
	return (ft_readline(fd, buf, endlpos, line));
}
