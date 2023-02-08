/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_colors_floor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:07:04 by hmarconn          #+#    #+#             */
/*   Updated: 2023/02/08 13:35:56 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cube.h"

static int	pa_floors_length(t_data	*data, char	*buffer)
{
	int	len;

	len = 0;
	while (buffer[data->scroller] && (buffer[data->scroller] >= '0' && \
			buffer[data->scroller] <= '9'))
	{
		len++;
		data->scroller++;
	}
	return (len);
}

static int	pa_floors_step(t_data	*data, char	*buffer, int i)
{
	if (buffer[data->scroller] && (buffer[data->scroller] >= '0' && \
		buffer[data->scroller] <= '9') && i == 3)
		return (0);
	else if (i < 3)
		return (0);
	return (1);
}

static int	pa_floors_firstphase(t_data	*data, char	*buffer)
{
	if (data->mapper->floors == 1)
	{
		free(buffer);
		return (0);
	}
	if (buffer[data->scroller] >= 'A' && buffer[data->scroller] <= 'Z')
	{
		return (0);
	}
	while (buffer[data->scroller] && (buffer[data->scroller] < '0' \
		|| buffer[data->scroller] > '9'))
		data->scroller++;
	return (1);
}

int	test(t_data	*data, char	*buffer, int	*points, char	*tmp)
{
	int	len;

	while (buffer[data->scroller] && (buffer[data->scroller] >= '0' && \
		buffer[data->scroller] <= '9') && points[2] < 3)
	{
		points[0] = data->scroller;
		len = pa_floors_length(data, buffer);
		tmp = ft_calloc(len + 1, sizeof(char));
		if (!tmp)
			exit (52);
		points[1] = 0;
		while (points[1] < len)
			tmp[points[1]++] = buffer[points[0]++];
		tmp[points[1]] = '\0';
		if (!pa_floorcolorcheck(data, tmp, points[2]))
		{
			free(buffer);
			buffer = NULL;
			return (0);
		}
		tmp = NULL;
		data->scroller += buffer[data->scroller] == ',';
		points[2]++;
	}
	return (1);
}

int	pa_floors(t_data	*data, char	*buffer)
{
	int		points[3];
	char	*tmp;

	points[0] = 0;
	points[1] = 0;
	points[2] = 0;
	tmp = NULL;
	if (!pa_floors_firstphase(data, buffer))
		return (0);
	if (!test(data, buffer, points, tmp))
		return (0);
	if (!pa_floors_step(data, buffer, points[2]))
		return (0);
	return (1);
}
