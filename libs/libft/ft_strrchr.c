/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:02:11 by hmarconn          #+#    #+#             */
/*   Updated: 2021/11/12 11:51:26 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static int	ft_len(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strrchr(const char	*s, int c)
{
	int		len;
	char	d;
	char	*str;

	d = c;
	str = (char *)s;
	len = ft_len(str);
	if (d == '\0')
		return (str + len);
	len--;
	while (len >= 0)
	{
		if (str[len] == d)
			return (str + len);
		len--;
	}
	return (NULL);
}
