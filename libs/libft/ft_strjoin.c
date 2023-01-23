/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:08:28 by hmarconn          #+#    #+#             */
/*   Updated: 2021/11/18 11:08:04 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_len(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const	*s1, char const	*s2)
{
	int		len;
	int		b;
	int		a;
	char	*s3;

	len = 0;
	b = 0;
	a = 0;
	len = ft_len((char *)s1) + ft_len((char *)s2);
	s3 = malloc(sizeof(char) * len + 1);
	if (!s3)
		return (NULL);
	while (s1[b] != '\0')
	{
		s3[b] = s1[b];
		b++;
	}
	while (s2[a] != '\0')
	{
		s3[b] = s2[a];
		b++;
		a++;
	}
	s3[b] = '\0';
	return (s3);
}
