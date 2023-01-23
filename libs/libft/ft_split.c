/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:26:50 by hmarconn          #+#    #+#             */
/*   Updated: 2021/12/01 16:13:24 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char	*str, char c)
{
	int	tic;
	int	tac;
	int	boom;

	tic = 0;
	tac = 0;
	boom = 0;
	while (str[tic] != '\0')
	{
		if (str[tic] == c)
			tac = 1;
		else if (tic == 0 && str[tic] != c)
		{
			tac = 0;
			boom++;
		}
		else if (str[tic] != c && tac == 1)
		{
			tac = 0;
			boom++;
		}
		tic++;
	}
	return (boom);
}

static int	ft_len(char	*str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

static char	**model(char	**tab, char	*s, char c, int y)
{
	int	len;
	int	i;

	i = 0;
	len = ft_len((char *)s, c);
	tab[y] = malloc(sizeof(char) * (len + 1));
	if (!tab[y])
		return (NULL);
	while (i < len)
	{
		tab[y][i] = s[i];
		i++;
	}
	tab[y][i] = '\0';
	return (tab);
}

static char	**medium(char **tab, char	*s, char c, int words)
{
	int	y;
	int	i;

	i = 0;
	y = 0;
	while (s[i] != '\0' && y < words)
	{
		if (s[i] == c || i == 0)
		{
			while (s[i] == c)
				i++;
			tab = model(tab, s + i, c, y);
			if (!tab)
				return (NULL);
			y++;
		}
		i++;
	}
	tab[y] = 0;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		words;

	words = count((char *)s, c);
	if (words == 0)
	{
		tab = malloc(sizeof(char *));
		tab[0] = 0;
		return (tab);
	}
	tab = malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	tab = medium(tab, (char *)s, c, words);
	if (!tab)
		return (NULL);
	return (tab);
}
