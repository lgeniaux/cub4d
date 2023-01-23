/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_colors_floor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:07:04 by hmarconn          #+#    #+#             */
/*   Updated: 2023/01/23 16:01:27 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cube.h"

int	pa_floorcolorcheck(t_data	*data, char	*tmp, int i)
{
	if (i == 0)
	{
		if (!pa_firstfloor(data, tmp))
			return (0);
	}
	else if (i == 1)
	{
		if (!pa_secondfloor(data, tmp))
			return (0);
	}
	else
	{
		if (!pa_thirdfloor(data, tmp))
			return (0);
	}
	free(tmp);
	tmp = NULL;
	return (1);
}

int	pa_floors(t_data	*data, char	*buffer)
{
	int		len;
	int		pin;
	int		pan;
	char	*tmp;
	int		i;

	len = 0;
	pan = 0;
	i = 0;
	if (data->mapper->floors == 1)
	{
		free(buffer);
		return (0);
	}
	while (buffer[data->scroller] < '0' || buffer[data->scroller] > '9')
		data->scroller++;
	while (buffer[data->scroller] && (buffer[data->scroller] >= '0' && \
		buffer[data->scroller] <= '9') && i < 3)
	{
		pin = data->scroller;
		len = 0;
		while (buffer[data->scroller] && (buffer[data->scroller] >= '0' && \
			buffer[data->scroller] <= '9'))
		{
			len++;
			data->scroller++;
		}
		tmp = ft_calloc(len + 1, sizeof(char));
		if (!tmp)
			exit (52);
		pan = 0;
		while (pan < len)
			tmp[pan++] = buffer[pin++];
		tmp[pan] = '\0';
		if (!pa_floorcolorcheck(data, tmp, i))
			return (0);
		tmp = NULL;
		if (buffer[data->scroller] == ',')
			data->scroller++;
		i++;
	}
	if (buffer[data->scroller] && (buffer[data->scroller] >= '0' && \
		buffer[data->scroller] <= '9') && i == 3)
		return (0);
	else if (i < 3)
		return (0);
	data->mapper->floors = 1;
	return (1);
}
