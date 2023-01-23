/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:28:26 by hmarconn          #+#    #+#             */
/*   Updated: 2021/11/10 16:38:24 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*haystack, const char	*needle, size_t	len)
{
	size_t	i;
	int		b;
	int		c;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		b = 0;
		if (haystack[i] == needle[b])
		{
			c = i;
			while (haystack[i] == needle[b] && i < len)
			{
				if (needle[b + 1] == '\0')
					return ((char *)haystack + c);
				i++;
				b++;
			}
			i = c;
		}
		i++;
	}
	return (NULL);
}
