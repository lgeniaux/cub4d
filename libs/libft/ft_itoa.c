/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:25:25 by hmarconn          #+#    #+#             */
/*   Updated: 2021/12/01 16:19:05 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numbersize(int n)
{
	int				i;
	unsigned int	u;

	i = 0;
	if (n < 0)
		u = n * -1;
	else
		u = n;
	while (u > 9)
	{
		u = u / 10;
		i++;
	}
	return (i);
}

static char	*molding(int n)
{
	unsigned int	u;
	char			*str;

	u = 2;
	if (n < -9 || n > 9)
	{
		if (n < -9)
			u = (n * -1) * 10;
		else
			u = n;
		str = malloc(sizeof(char) * (numbersize(u) + 2));
		if (!str)
			return (NULL);
	}
	else
	{
		if (n < 0)
			u += 1;
		str = malloc(sizeof(char) * u);
		if (!str)
			return (NULL);
	}
	return (str);
}

static int	downsize(char	*str, unsigned int u)
{
	int	i;

	i = 0;
	str[0] = '-';
	i = numbersize(u) + 2;
	return (i);
}

char	*ft_itoa(int n)
{
	int				i;
	char			*str;
	unsigned int	u;

	u = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = molding(n);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		u = n * -1;
		i = downsize(str, u);
	}
	else
		i = numbersize(u) + 1;
	str[i--] = '\0';
	while (u > 9)
	{
		str[i--] = (u % 10) + '0';
		u = u / 10;
	}
	str[i--] = u + '0';
	return (str);
}
