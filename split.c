/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xsaulnie <xsaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:34:01 by xsaulnie          #+#    #+#             */
/*   Updated: 2022/03/14 16:34:02 by xsaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	count(char const *s, char c)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] == '\0' && res == 0)
			return (0);
		while (s[i] != c && s[i] != '\0')
			i++;
		res++;
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	return (res);
}

static int	cleanalloc(char **tab, int indelem, int nbcar)
{
	int	i;

	i = 0;
	tab[indelem] = (char *)malloc((nbcar + 1) * sizeof(char));
	if (tab[indelem] == NULL)
	{
		while (i < indelem)
		{
			free(tab[i]);
			i++;
		}
		return (1);
	}
	return (0);
}

static int	alloc(char **tab, char const *s, char c)
{
	int	indelem;
	int	nbcar;
	int	i;

	i = 0;
	indelem = 0;
	while (s[i] != '\0')
	{
		nbcar = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			nbcar++;
			i++;
		}
		if (cleanalloc(tab, indelem, nbcar))
			return (1);
		indelem++;
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	return (0);
}

static void	affec(char **tab, char const *s, char c)
{
	int	indelem;
	int	nbcar;
	int	i;

	i = 0;
	indelem = 0;
	while (s[i] != '\0')
	{
		nbcar = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			tab[indelem][nbcar] = s[i];
			nbcar++;
			i++;
		}
		tab[indelem][nbcar] = '\0';
		indelem++;
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	tab[indelem] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		nbelem;

	if (s == NULL)
		return (NULL);
	nbelem = count(s, c);
	res = (char **)malloc((nbelem + 1) * (sizeof(char *)));
	if (res == NULL)
		return (NULL);
	if (nbelem == 0)
		res[0] = NULL;
	else
	{
		if (alloc(res, s, c))
			return (NULL);
		affec(res, s, c);
	}
	return (res);
}
