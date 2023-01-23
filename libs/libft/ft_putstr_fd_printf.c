/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 09:01:54 by hmarconn          #+#    #+#             */
/*   Updated: 2022/04/21 15:50:21 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd_printf(char	*s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		ft_putstr_fd_printf("(null)", 1);
		return (6);
	}
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}
