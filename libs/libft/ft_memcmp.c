/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:10:01 by hmarconn          #+#    #+#             */
/*   Updated: 2021/11/17 14:00:26 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void	*s1, const void	*s2, size_t	n)
{
	size_t		i;
	const char	*str;
	const char	*line;

	str = s1;
	line = s2;
	i = 0;
	if (n == 0)
		return (0);
	while (str[i] == line[i] && i < n - 1)
		i++;
	return ((unsigned char)str[i] - (unsigned char)line[i]);
}
