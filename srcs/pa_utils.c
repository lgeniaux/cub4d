/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:09:04 by hmarconn          #+#    #+#             */
/*   Updated: 2023/01/23 11:49:42 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cube.h"

int	pa_getlen(t_data	*data, char	*buffer)
{
	int	len;

	len = 0;
	while (buffer[data->scroller] && (buffer[data->scroller] >= 33 && \
		buffer[data->scroller] <= 126))
	{
		len++;
		data->scroller++;
	}
	return (len);
}

void	the_end(t_data	*data)
{
	int	y;

	y = 0;
	printf("%d\n", data->mapper->height);
	printf("%i\n", data->map_exists);
	if (data->map_exists == 1)
	{
		while (y < data->mapper->height)
		{
			free(data->mapper->map[y]);
			y++;
		}
		free(data->mapper->map);
	}
	y = 0;
	while (y < 4)
	{
		free(data->mapper->walls[y]);
		y++;
	}
}
