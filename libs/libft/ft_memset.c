/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:04:04 by hmarconn          #+#    #+#             */
/*   Updated: 2021/11/17 13:36:50 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void	*b, int c, size_t len)
{
	size_t		a;
	char		*d;

	d = b;
	a = 0;
	while (a < len)
	{
		d[a] = c;
		a++;
	}
	return (d);
}
