/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:56:34 by hmarconn          #+#    #+#             */
/*   Updated: 2021/11/17 13:30:02 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(char	*str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
		a++;
	return (a);
}

size_t	ft_strlcat(char	*dest, const char	*src, size_t	destsize)
{
	size_t		a;
	size_t		b;
	int			c;

	b = 0;
	a = 0;
	while (a < destsize && dest[a] != '\0')
		a++;
	c = a + ft_len((char *)src);
	if (destsize <= a)
		return (c);
	while (src[b] != '\0' && b < (destsize - a - 1))
	{
		dest[a + b] = (char)src[b];
		b++;
	}
	dest[a + b] = '\0';
	return (c);
}
