/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 09:13:26 by hmarconn          #+#    #+#             */
/*   Updated: 2021/11/15 10:10:25 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb2;

	if (n < 0)
	{
		nb2 = -n;
		ft_putchar('-', fd);
	}
	else
	{
		nb2 = n;
	}
	while (nb2 > 9)
	{
		ft_putnbr_fd(nb2 / 10, fd);
		nb2 = nb2 % 10;
	}
	ft_putchar(nb2 + '0', fd);
}
