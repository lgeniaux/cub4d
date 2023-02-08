/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_genmap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:24:30 by hmarconn          #+#    #+#             */
/*   Updated: 2023/02/04 19:45:14 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cube.h"

static void	filler_secondutil(t_data	*data, char	*buffer, int x)
{
	while (buffer[x] != '\0')
	{
		data->mapper->map[data->y][x] = buffer[x];
		x++;
	}
	data->mapper->map[data->y][x] = '\0';
	data->y++;
}

static int	mapfiller_scroller(char	*buffer, int len)
{
	int	x;

	x = 0;
	while (x < len && buffer[x] != '1' && buffer[x] != '0' && \
		buffer[x] != 'N' && buffer[x] != 'S' && buffer[x] != 'E' && \
			buffer[x] != 'W')
    {
        x++;
    }
	return (x);
}

static int	the_map_filler_util(t_data	*data, char	*buffer, int len)
{
	int	x;

	x = 0;
	if ((buffer[0] < 33 || buffer[0] > 126) && (buffer[0] != '\0' && \
		buffer[0] != '\n'))
	{
		x = mapfiller_scroller(buffer, len);
		if (x == len && data->mapper->high_point == 0)
			data->mapper->high_point = data->y;
	}
	if (len == 1 && (buffer[0] == '\n' && data->mapper->high_point == 0))
		data->mapper->high_point = data->y;
    x = 0;
	if (len == 1)
		data->mapper->height = x;
	data->mapper->map[data->y] = ft_calloc(len + 1, sizeof(char));
	if (!data->mapper->map[data->y])
		return (0);
    data->index++;
	filler_secondutil(data, buffer, x);
	return (1);
}

int	the_map_filler(t_data	*data, char	*buffer)
{
	int	len;
	int	x;

	x = 0;
	len = ft_strlen(buffer);
	if (data->mapper->high_point == 0)
	{
		if (!the_map_filler_util(data, buffer, len))
			return (0);
	}
	else
	{
		x = 0;
		while (buffer[x] && buffer[x] != '\n' && buffer[x] != '\0')
		{
			if (buffer[x] >= 33 && buffer[x] <= 126)
				return (0);
			x++;
		}
	}
	return (1);
}
