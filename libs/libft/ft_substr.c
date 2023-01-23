/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:05:24 by hmarconn          #+#    #+#             */
/*   Updated: 2021/11/18 11:25:05 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(char	*s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const	*s, unsigned int start, size_t	len)
{
	char		*v;
	size_t		i;
	size_t		length;

	length = ft_len((char *)s + start);
	if (length < len)
		len = length;
	i = 0;
	v = malloc(sizeof(char) * len + 1);
	if (!v)
		return (NULL);
	length = ft_len((char *)s);
	if (start > length - 1)
	{
		v[i] = '\0';
		return (v);
	}	
	while (i < len)
	{
		v[i] = s[start + i];
		i++;
	}
	v[i] = '\0';
	return (v);
}
