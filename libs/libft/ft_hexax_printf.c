/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexax_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:34:57 by hmarconn          #+#    #+#             */
/*   Updated: 2022/03/15 16:05:33 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexax_printf(unsigned int nb, char	*base)
{
	int				l;
	unsigned int	nb2;

	l = 0;
	nb2 = nb;
	while (nb2 > 15)
	{
		nb2 = nb2 / 16;
		l++;
	}
	if (nb > 15)
	{
		ft_hexax_printf(nb / 16, base);
	}
	ft_putchar_fd_printf(base[nb % 16], 1);
	l++;
	return (l);
}
