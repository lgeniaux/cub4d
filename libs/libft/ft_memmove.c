/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:06:50 by hmarconn          #+#    #+#             */
/*   Updated: 2021/11/17 13:38:06 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*a;
	char	*b;

	a = dst;
	b = (char *) src;
	if (b < a)
	{
		while (len-- > 0)
		{
			a[len] = b[len];
		}
		return ((void *)a);
	}
	return ((void *)ft_memcpy(a, b, len));
}
