/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pprint_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:07:13 by hmarconn          #+#    #+#             */
/*   Updated: 2022/03/15 16:07:05 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	hexap_printf(unsigned long long pt, char	*base)
{
	int					l;
	unsigned long long	val;

	l = 0;
	val = pt;
	while (val > 15)
	{
		val = val / 16;
		l++;
	}
	if (pt > 15)
	{
		hexap_printf(pt / 16, base);
	}
	ft_putchar_fd_printf(base[pt % 16], 1);
	l++;
	return (l);
}

int	ft_pprint_printf(void	*va)
{
	int					l;
	char				*base;
	unsigned long long	val;

	val = (unsigned long long)va;
	base = "0123456789abcdef";
	l = 2;
	ft_putstr_fd_printf("0x", 1);
	l += hexap_printf(val, base);
	return (l);
}
