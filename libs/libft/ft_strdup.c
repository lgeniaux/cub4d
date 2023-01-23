/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:43:28 by hmarconn          #+#    #+#             */
/*   Updated: 2022/11/24 17:34:27 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(char	*src, int len)
{
	while (src[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strdup(const char	*src)
{
	int		len;
	int		i;
	char	*tab;

	i = 0;
	len = 0;
	len = ft_len((char *)src, len);
	tab = malloc(sizeof(*tab) * len + 1);
	if (!tab)
		return (0);
	while (src[i] != '\0')
	{
		tab[i] = src[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
