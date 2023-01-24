/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:26:03 by hmarconn          #+#    #+#             */
/*   Updated: 2023/01/24 14:14:14 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cube.h"

int	pa_colors(t_data	*data, char	*buffer)
{
	if (buffer[data->scroller] == 'F')
	{
		data->scroller++;
		if (!pa_floors(data, buffer))
			return (0);
		data->mapper->floors = 1;
	}
	else if (buffer[data->scroller] == 'C')
	{
		data->scroller++;
		if (!pa_ceiling(data, buffer))
			return (0);
	}
	return (1);
}

void	init_phase(t_data	*data)
{
	data->mapper->ceilings = 0;
	data->mapper->floors = 0;
	data->mapper->north_wall = 0;
	data->mapper->south_wall = 0;
	data->mapper->east_wall = 0;
	data->mapper->west_wall = 0;
	data->fd_section = 0;
	data->i = 0;
	data->y = 0;
	data->mapper->player = 0;
	data->mapper->high_point = 0;
	data->map_exists = 0;
}

int	to_parse(t_data	*data, char	*buffer)
{
	data->scroller = 0;
	data->i++;
	while (buffer[data->scroller] != '\0')
	{
		if (data->fd_section == 0)
		{
			while (buffer[data->scroller] && buffer[data->scroller] != '\0' && \
				(buffer[data->scroller] < 33 || buffer[data->scroller] > 126))
				data->scroller++;
			while (buffer[data->scroller] && (buffer[data->scroller] >= 33 && \
				buffer[data->scroller] <= 126) && data->fd_section == 0)
			{
				if (buffer[data->scroller] == 'N' || buffer[data->scroller] \
					== 'S' \
					|| buffer[data->scroller] == 'E' || \
						buffer[data->scroller] == 'W')
				{
					if (!pa_wallpapers(data, buffer))
						return (0);
				}
				else if (buffer[data->scroller] == 'F' || \
					buffer[data->scroller] == 'C')
				{
					if (!pa_colors(data, buffer))
						return (0);
				}
				else if (buffer[data->scroller] >= '0' && \
					buffer[data->scroller] <= '9')
				{
					data->fd_section = 1;
					return (1);
				}
				else if (buffer[data->scroller] >= 33 && \
					buffer[data->scroller] <= 126)
					return (0);
			}
		}
	}
	return (1);
}

void	the_tester(t_data	*data)
{
	int	y;

	y = 0;
	printf("F :%d %d %d\nC :%d %d %d\n", data->mapper->floor[0], \
		data->mapper->floor[1], data->mapper->floor[2], \
			data->mapper->ceiling[0], data->mapper->ceiling[1], \
				data->mapper->ceiling[2]);
	printf("%d\n", data->mapper->height);
	while (y < data->mapper->high_point)
	{
		printf("%s\n", data->mapper->map[y]);
		y++;
	}
}
