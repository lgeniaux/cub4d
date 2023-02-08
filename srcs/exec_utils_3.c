/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeniaux <lgeniaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:52:11 by lgeniaux          #+#    #+#             */
/*   Updated: 2023/02/08 15:08:16 by lgeniaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cube.h"

int	fill_buffer_second(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < 8)
	{
		data->info->texture[i] = (int *)malloc(sizeof(int) * (TEXTURE_HEIGHT
					* TEXTURE_WIDTH));
		if (!data->info->texture[i])
			return (-1);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < TEXTURE_HEIGHT * TEXTURE_WIDTH)
		{
			data->info->texture[i][j] = 0;
			j++;
		}
		i++;
	}
	return (0);
}

int	fill_buffer(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_H)
	{
		j = 0;
		while (j < WINDOW_W)
		{
			data->info->buf[i][j] = 0;
			j++;
		}
		i++;
	}
	data->info->texture = (int **)malloc(sizeof(int *) * 8);
	if (!data->info->texture)
		return (-1);
	if (fill_buffer_second(data) == -1)
		return (-1);
	return (0);
}

void	toparse_scroll(t_data *data)
{
	while (data->buffer[data->scroller] && data->buffer[data->scroller] != '\0' \
		&& (data->buffer[data->scroller] < 33 || data->buffer[data->scroller] > \
		126))
		data->scroller++;
}

int	pa_getlen(t_data *data)
{
	int	len;

	len = 0;
	while (data->buffer[data->scroller] && (data->buffer[data->scroller] >= 33
			&& data->buffer[data->scroller] <= 126))
	{
		len++;
		data->scroller++;
	}
	return (len);
}

int	test_utils(t_data	*data, int	*points, char	*tmp)
{
	int	len;

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
	return (1);
}
