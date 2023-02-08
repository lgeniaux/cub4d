/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_colors_floor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeniaux <lgeniaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:07:04 by hmarconn          #+#    #+#             */
/*   Updated: 2023/02/08 15:08:46 by lgeniaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cube.h"

int	pa_floors_length(t_data	*data)
{
	int	len;

	len = 0;
	while (data->buffer[data->scroller] && \
		(data->buffer[data->scroller] >= '0' && \
		data->buffer[data->scroller] <= '9'))
	{
		len++;
		data->scroller++;
	}
	return (len);
}

int	pa_floors_step(t_data	*data, int i)
{
	if (data->buffer[data->scroller] && \
		(data->buffer[data->scroller] >= '0' && \
		data->buffer[data->scroller] <= '9') && i == 3)
		return (0);
	else if (i < 3)
		return (0);
	return (1);
}

int	pa_floors_firstphase(t_data	*data)
{
	if (data->mapper->floors == 1)
	{
		free(data->buffer);
		data->buffer = NULL;
		return (0);
	}
	if (data->buffer[data->scroller] >= 'A' && \
		data->buffer[data->scroller] <= 'Z')
	{
		return (0);
	}
	while (data->buffer[data->scroller] && \
		(data->buffer[data->scroller] < '0' \
		|| data->buffer[data->scroller] > '9'))
		data->scroller++;
	return (1);
}

int	test(t_data	*data, int	*points, char	*tmp)
{
	while (data->buffer[data->scroller] && \
		(data->buffer[data->scroller] >= '0' && \
		data->buffer[data->scroller] <= '9') && points[2] < 3)
	{
		if (!test_utils(data, points, tmp))
			return (0);
	}
	return (1);
}

int	pa_floors(t_data	*data)
{
	int		points[3];
	char	*tmp;

	points[0] = 0;
	points[1] = 0;
	points[2] = 0;
	tmp = NULL;
	if (!pa_floors_firstphase(data))
		return (0);
	if (!test(data, points, tmp))
		return (0);
	if (!pa_floors_step(data, points[2]))
		return (0);
	return (1);
}
