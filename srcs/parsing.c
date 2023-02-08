/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeniaux <lgeniaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:26:03 by hmarconn          #+#    #+#             */
/*   Updated: 2023/02/08 14:07:19 by lgeniaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cube.h"

int	pa_colors(t_data *data)
{
	if (data->buffer[data->scroller] == 'F')
	{
		data->scroller++;
		if (!pa_floors(data))
			return (0);
		data->mapper->floors = 1;
	}
	else if (data->buffer[data->scroller] == 'C')
	{
		data->scroller++;
		if (!pa_ceiling(data))
			return (0);
	}
	return (1);
}

void	init_phase(t_data *data)
{
	data->mapper->walls = ft_calloc(sizeof(char *), 4);
	if (!data->mapper->walls)
	{
		the_end(data, 0);
	}
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
