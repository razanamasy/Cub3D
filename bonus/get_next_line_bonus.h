/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:00:24 by hrazanam          #+#    #+#             */
/*   Updated: 2022/03/15 17:00:57 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "errno.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

int		get_next_line(int fd, char **line);
void	ft_del(char **p);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char **s1, char *s2, int endlpos);
char	*emptystr(void);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_endl(char *buf, size_t size);
void	restbuf(char *buf, int endl, int size);
int		ft_aff(char **line, char *buf, int endlpos);
int		ft_readline(int fd, char *buf, int endlpos, char **line);
#endif
