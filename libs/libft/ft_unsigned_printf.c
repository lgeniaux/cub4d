/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_printf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:30:29 by hmarconn          #+#    #+#             */
/*   Updated: 2022/03/15 16:05:07 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar_printf(char c, int fd)
{
	write(fd, &c, 1);
}

static int	lines(unsigned int nb)
{
	int	l;

	l = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		l++;
	}
	return (l);
}

int	ft_unsigned_printf(unsigned int i)
{
	int	l;

	l = 0;
	l += lines(i);
	while (i > 9)
	{
		ft_unsigned_printf(i / 10);
		i = i % 10;
	}
	ft_putchar_printf(i + '0', 1);
	return (l);
}
