/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 09:13:26 by hmarconn          #+#    #+#             */
/*   Updated: 2022/03/15 16:04:30 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar_printf(char c, int fd)
{
	write(fd, &c, 1);
}

static int	lines(unsigned long long nb3)
{
	int	l;

	l = 1;
	while (nb3 > 9)
	{
		nb3 = nb3 / 10;
		l++;
	}
	return (l);
}

int	ft_putnbr_fd_printf(int n, int fd)
{
	unsigned long long	nb2;
	unsigned long long	nb3;
	int					l;

	l = 0;
	if (n < 0)
	{
		nb2 = (unsigned long long)n * -1;
		ft_putchar_printf('-', fd);
		l++;
	}
	else
		nb2 = (unsigned long long)n;
	nb3 = nb2;
	l += lines(nb3);
	while (nb2 > 9)
	{
		ft_putnbr_fd_printf(nb2 / 10, fd);
		nb2 = nb2 % 10;
	}
	ft_putchar_printf(nb2 + '0', fd);
	return (l);
}
