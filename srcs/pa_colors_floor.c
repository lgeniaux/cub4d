/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_colors_floor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeniaux <lgeniaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:07:04 by hmarconn          #+#    #+#             */
/*   Updated: 2023/02/08 14:41:40 by lgeniaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cube.h"

static int	pa_floors_length(t_data	*data)
{
	int	len;

	len = 0;
	while (data->buffer[data->scroller] && (data->buffer[data->scroller] >= '0' && \
			data->buffer[data->scroller] <= '9'))
	{
		len++;
		data->scroller++;
	}
	return (len);
}

static int	pa_floors_step(t_data	*data, int i)
{
	if (data->buffer[data->scroller] && (data->buffer[data->scroller] >= '0' && \
		data->buffer[data->scroller] <= '9') && i == 3)
		return (0);
	else if (i < 3)
		return (0);
	return (1);
}

static int	pa_floors_firstphase(t_data	*data)
{
	if (data->mapper->floors == 1)
	{
		free(data->buffer);
		data->buffer = NULL;
		return (0);
	}
	if (data->buffer[data->scroller] >= 'A' && data->buffer[data->scroller] <= 'Z')
	{
		return (0);
	}
	while (data->buffer[data->scroller] && (data->buffer[data->scroller] < '0' \
		|| data->buffer[data->scroller] > '9'))
		data->scroller++;
	return (1);
}

int	test(t_data	*data, int	*points, char	*tmp)
{
	int	len;

	while (data->buffer[data->scroller] && (data->buffer[data->scroller] >= '0' && \
		data->buffer[data->scroller] <= '9') && points[2] < 3)
	{
		points[0] = data->scroller;
		len = pa_floors_length(data);
		tmp = ft_calloc(len + 1, sizeof(char));
		if (!tmp)
			exit (52);
		points[1] = 0;
		while (points[1] < len)
			tmp[points[1]++] = data->buffer[points[0]++];
		tmp[points[1]] = '\0';
		if (!pa_floorcolorcheck(data, tmp, points[2]))
		{
			free(data->buffer);
			data->buffer = NULL;
			return (0);
		}
		tmp = NULL;
		data->scroller += data->buffer[data->scroller] == ',';
		points[2]++;
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
