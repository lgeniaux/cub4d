/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:44:25 by hmarconn          #+#    #+#             */
/*   Updated: 2021/12/01 16:14:13 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	start(char *str, char	*set, int pin)
{
	int	tic;

	tic = 0;
	while (set[tic] != '\0')
	{
		if (set[tic] == str[0])
		{
			pin++;
			return (start(str + 1, set, pin));
		}
		tic++;
	}
	return (pin);
}

static int	ending(char *str, char	*set, int len, int tac)
{
	int	x;

	x = 0;
	while (set[x] != '\0')
	{
		if (set[x] == str[len - 1] && len - 1 > 0)
		{
			x = -1;
			len--;
			tac++;
		}
		x++;
	}
	return (tac);
}

static char	*substr(char const	*s, unsigned int start, size_t	len)
{
	char		*v;
	size_t		i;
	size_t		length;

	length = ft_strlen((char *)s);
	i = 0;
	v = malloc(sizeof(char) * len + 1);
	if (!v)
		return (NULL);
	if (start > length)
		return (NULL);
	while (i < len)
	{
		v[i] = s[start + i];
		i++;
	}
	v[i] = '\0';
	return (v);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		pin;
	size_t		len;
	size_t		tac;
	char		*str;

	len = 0;
	pin = 0;
	tac = 0;
	pin = start((char *)s1, (char *)set, pin);
	len = ft_strlen(s1);
	if (pin == len)
		pin = 0;
	tac = ending((char *)s1 + pin, (char *)set, len - pin, tac);
	if (tac == len - 1)
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	else
		str = substr(s1, pin, (len - (pin + tac)));
	return (str);
}
