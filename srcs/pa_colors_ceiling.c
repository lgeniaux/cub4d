/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_colors_ceiling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:32:47 by hmarconn          #+#    #+#             */
/*   Updated: 2023/01/30 18:21:31 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cube.h"

int	pa_ceilingcolorcheck(t_data	*data, char	*tmp, int i)
{
	if (i == 0)
	{
		if (!first_ceiling(data, tmp))
			return (0);
	}
	else if (i == 1)
	{
		if (!second_ceiling(data, tmp))
			return (0);
	}
	else
	{
		if (!third_ceiling(data, tmp))
			return (0);
	}
	free(tmp);
	tmp = NULL;
	return (1);
}

static int	pa_ceiling_length(t_data	*data, char	*buffer)
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

int	pa_ceiling_steptwo(t_data	*data, char	*buffer, int i)
{
	if (buffer[data->scroller] && (buffer[data->scroller] >= '0' && \
		buffer[data->scroller] <= '9') && i == 3)
		return (0);
	else if (i < 3)
		return (0);
	data->mapper->ceilings = 1;
	return (1);
}

static int	pa_ceiling_saveplace(t_data	*data, char	*buffer)
{
	if (data->mapper->ceilings == 1)
	{
		free(buffer);
		return (0);
	}
	while (buffer[data->scroller] < '0' || buffer[data->scroller] > '9')
		data->scroller++;
	return (1);
}

static int	test(t_data	*data, char	*buffer, int *points, char	*tmp)
{
	int	len;

	while (buffer[data->scroller] && (buffer[data->scroller] >= '0' && \
		buffer[data->scroller] <= '9') && data->y < 3)
	{
		points[1] = 0;
		points[0] = data->scroller;
		len = pa_ceiling_length(data, buffer);
		tmp = ft_calloc(len + 1, sizeof(char));
		if (!tmp)
			exit (52);
		while (points[1] < len)
			tmp[points[1]++] = buffer[points[0]++];
		tmp[points[1]] = '\0';
		if (!pa_ceilingcolorcheck(data, tmp, data->y))
		{
			if (buffer != NULL)
				free(buffer);
			return (0);
		}
		tmp = NULL;
		data->scroller += buffer[data->scroller] == ',';
		data->y++;
	}
	return (1);
}

int	pa_ceiling(t_data	*data, char	*buffer)
{
	char	*tmp;
	int		points[2];

	points[0] = 0;
	points[1] = 0;
	tmp = NULL;
	printf("%i, %i, %i\n", data->scroller, data->i, data->y);
	if (!pa_ceiling_saveplace(data, buffer))
		return (0);
	if (!test(data, buffer, points, tmp))
		return (0);
	if (!pa_ceiling_steptwo(data, buffer, data->y))
		return (0);
	data->y = 0;
	return (1);
}
