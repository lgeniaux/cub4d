/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_colors_ceiling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:32:47 by hmarconn          #+#    #+#             */
/*   Updated: 2023/02/04 16:53:09 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cube.h"

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
    if (buffer[data->scroller] >= 'A' && buffer[data->scroller] <= 'Z')
    {
        return (0);
    }
	while (buffer[data->scroller] && (buffer[data->scroller] < '0' || buffer[data->scroller] > '9'))
    {
        data->scroller++;
    }
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
            free(buffer);
            buffer = NULL;
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
	if (!pa_ceiling_saveplace(data, buffer))
		return (0);
	if (!test(data, buffer, points, tmp))
		return (0);
	if (!pa_ceiling_steptwo(data, buffer, data->y))
		return (0);
	data->y = 0;
	return (1);
}
