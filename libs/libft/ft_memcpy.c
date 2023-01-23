/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:59:33 by hmarconn          #+#    #+#             */
/*   Updated: 2021/11/17 13:53:20 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		a;
	char		*i;
	const char	*u;

	u = src;
	i = dst;
	a = 0;
	if (u == NULL && i == NULL)
		return (NULL);
	while (a < n)
	{
		i[a] = u[a];
		a++;
	}
	return (dst);
}
