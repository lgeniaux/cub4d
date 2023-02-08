/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_genmap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeniaux <lgeniaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:24:30 by hmarconn          #+#    #+#             */
/*   Updated: 2023/02/08 15:19:22 by lgeniaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cube.h"

int	pa_ceiling_steptwo(t_data	*data, int i)
{
	if (data->buffer[data->scroller] && \
		(data->buffer[data->scroller] >= '0' && \
		data->buffer[data->scroller] <= '9') && i == 3)
		return (0);
	else if (i < 3)
		return (0);
	data->mapper->ceilings = 1;
	return (1);
}

static void	filler_secondutil(t_data	*data, int x)
{
	while (data->buffer[x] != '\0')
	{
		data->mapper->map[data->y][x] = data->buffer[x];
		x++;
	}
	data->mapper->map[data->y][x] = '\0';
	data->y++;
}

static int	mapfiller_scroller(t_data *data, int len)
{
	int	x;

	x = 0;
	while (x < len && data->buffer[x] != '1' && data->buffer[x] != '0' && \
		data->buffer[x] != 'N' && data->buffer[x] != 'S' && \
		data->buffer[x] != 'E' && data->buffer[x] != 'W')
	{
		x++;
	}
	return (x);
}

static int	the_map_filler_util(t_data	*data, int len)
{
	int	x;

	x = 0;
	if ((data->buffer[0] < 33 || data->buffer[0] > 126) && \
		(data->buffer[0] != '\0' && data->buffer[0] != '\n'))
	{
		x = mapfiller_scroller(data, len);
		if (x == len && data->mapper->high_point == 0)
			data->mapper->high_point = data->y;
	}
	if (len == 1 && (data->buffer[0] == '\n' && data->mapper->high_point == 0))
		data->mapper->high_point = data->y;
	x = 0;
	if (len == 1)
		data->mapper->height = x;
	data->mapper->map[data->y] = ft_calloc(len + 1, sizeof(char));
	if (!data->mapper->map[data->y])
		return (0);
	data->index++;
	filler_secondutil(data, x);
	return (1);
}

int	the_map_filler(t_data	*data)
{
	int	len;
	int	x;

	x = 0;
	len = ft_strlen(data->buffer);
	if (data->mapper->high_point == 0)
	{
		if (!the_map_filler_util(data, len))
			return (0);
	}
	else
	{
		x = 0;
		while (data->buffer[x] && data->buffer[x] != '\n' && \
			data->buffer[x] != '\0')
		{
			if (data->buffer[x] >= 33 && data->buffer[x] <= 126)
				return (0);
			x++;
		}
	}
	return (1);
}
