/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_colors_ceiling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeniaux <lgeniaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:32:47 by hmarconn          #+#    #+#             */
/*   Updated: 2023/02/08 16:15:51 by lgeniaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cube.h"

static int	pa_ceiling_length(t_data	*data)
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

static int	pa_ceiling_saveplace(t_data	*data)
{
	if (data->mapper->ceilings == 1)
	{
		free(data->buffer);
		return (0);
	}
	if (data->buffer[data->scroller] >= 'A' && \
		data->buffer[data->scroller] <= 'Z')
	{
		return (0);
	}
	while (data->buffer[data->scroller] && \
		(data->buffer[data->scroller] < '0' || \
		data->buffer[data->scroller] > '9'))
	{
		data->scroller++;
	}
	return (1);
}

static int	test_utils_ceiling(t_data *data, int *points, char *tmp)
{
	int	len;

	len = 0;
	points[1] = 0;
	points[0] = data->scroller;
	len = pa_ceiling_length(data);
	tmp = ft_calloc(len + 1, sizeof(char));
	if (!tmp)
		exit (52);
	while (points[1] < len)
		tmp[points[1]++] = data->buffer[points[0]++];
	tmp[points[1]] = '\0';
	if (!pa_ceilingcolorcheck(data, tmp, data->y))
	{
		free(data->buffer);
		data->buffer = NULL;
		return (0);
	}
	tmp = NULL;
	data->scroller += data->buffer[data->scroller] == ',';
	data->y++;
	return (1);
}

static int	test(t_data	*data, int *points, char	*tmp)
{
	while (data->buffer[data->scroller] && \
		(data->buffer[data->scroller] >= '0' && \
		data->buffer[data->scroller] <= '9') && data->y < 3)
	{
		if (!test_utils_ceiling(data, points, tmp))
			return (0);
	}
	return (1);
}

int	pa_ceiling(t_data	*data)
{
	char	*tmp;
	int		points[2];

	points[0] = 0;
	points[1] = 0;
	tmp = NULL;
	if (!pa_ceiling_saveplace(data))
		return (0);
	if (!test(data, points, tmp))
		return (0);
	if (!pa_ceiling_steptwo(data, data->y))
		return (0);
	data->y = 0;
	return (1);
}
