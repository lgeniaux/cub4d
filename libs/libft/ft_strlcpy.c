/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:29:56 by hmarconn          #+#    #+#             */
/*   Updated: 2021/11/17 13:29:14 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char	*dest, const char	*src, size_t	destsize)
{
	size_t	a;
	size_t	i;

	a = 0;
	i = 0;
	while (src[i] != '\0')
		i++;
	if (destsize <= 0)
		return (i);
	while (a < destsize - 1 && src[a] != '\0')
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0';
	return (i);
}
