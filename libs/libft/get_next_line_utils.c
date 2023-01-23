/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:07:31 by hmarconn          #+#    #+#             */
/*   Updated: 2022/03/15 16:13:02 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char	*src, char c)
{
	int		len;
	int		i;
	char	*tab;

	if (!src)
		return (NULL);
	i = 0;
	len = ft_strlenbis((const char *) src);
	while (src[i] != '\0' && src[i] != c)
		i++;
	if (i < len && c != '\0')
		len = i + 1;
	tab = malloc(sizeof(char *) * (len + 1));
	if (!tab)
		return (0);
	i = 0;
	while (i < len)
	{
			tab[i] = src[i];
			i++;
	}
	tab[i] = '\0';
	return (tab);
}

size_t	ft_strlenbis(const char	*str)
{
	size_t	i;

	i = 0;
	while (str && str[i] != 0)
			i++;
	return (i);
}

char	*ft_strjoingen(char	*s1, char *s2)
{
	int		len;
	int		b;
	int		a;
	char	*s3;

	len = 0;
	b = 0;
	a = 0;
	len = ft_strlenbis((const char *)s1) + ft_strlenbis((const char *)s2);
	s3 = malloc(sizeof(char) * len + 1);
	if (!s3)
		return (NULL);
	while (s1 && s1[b] != '\0')
	{
			s3[b] = s1[b];
			b++;
	}
	while (s2 && s2[a] != '\0')
	{
			s3[b++] = s2[a];
			a++;
	}
	s3[b] = '\0';
	free (s1);
	return (s3);
}
