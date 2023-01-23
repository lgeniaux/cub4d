/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:35:09 by hmarconn          #+#    #+#             */
/*   Updated: 2022/03/15 16:03:42 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	truc(char c, va_list	ap, int l)
{
	if (c == 'c')
		l += ft_putchar_fd_printf(va_arg(ap, int), 1);
	else if (c == 's')
		l += ft_putstr_fd_printf(va_arg(ap, char *), 1);
	else if (c == 'i' || c == 'd')
		l += ft_putnbr_fd_printf(va_arg(ap, int), 1);
	else if (c == 'u')
		l += ft_unsigned_printf(va_arg(ap, unsigned int));
	else if (c == 'x')
		l += ft_hexax_printf(va_arg(ap, int), "0123456789abcdef");
	else if (c == 'X')
		l += ft_hexax_printf(va_arg(ap, int), "0123456789ABCDEF");
	else if (c == 'p')
		l += ft_pprint_printf(va_arg(ap, void *));
	else if (c == '%')
	{
		write(1, "%", 1);
		l++;
	}
	return (l);
}

int	ft_printf(const char	*str, ...)
{
	va_list	ap;
	int		i;
	int		l;

	l = 0;
	i = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{	
		if (str[i] == '%')
		{
			i++;
			l = truc(str[i], ap, l);
		}
		else
			l += ft_putchar_fd_printf(str[i], 1);
		i++;
	}
	va_end(ap);
	return (l);
}
