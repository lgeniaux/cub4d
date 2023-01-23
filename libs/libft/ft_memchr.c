/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:23:15 by hmarconn          #+#    #+#             */
/*   Updated: 2021/11/17 12:26:34 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void	*s, int c, size_t	n)
{
	size_t		a;
	const char	*b;

	b = s;
	a = 0;
	c = c % 256;
	while (a < n)
	{
		if (b[a] == c)
			return ((char *)b + a);
		a++;
	}
	return (NULL);
}
