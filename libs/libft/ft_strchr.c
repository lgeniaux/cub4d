/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:04:55 by hmarconn          #+#    #+#             */
/*   Updated: 2022/03/15 16:12:44 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char	*s, int c)
{
	int	a;

	if (!s)
		return (NULL);
	a = 0;
	c = c % 256;
	while (s[a] != '\0')
	{
		if (s[a] == c)
			return ((char *)s + a);
		a++;
	}
	if (c == 0)
		return ((char *)s + a);
	return (NULL);
}
