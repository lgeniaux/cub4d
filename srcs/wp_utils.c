/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wp_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:44:18 by hmarconn          #+#    #+#             */
/*   Updated: 2023/02/04 18:47:15 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cube.h"

static int	wp_one(t_data	*data, int x, int y)
{
	if (data->mapper->map[y][x - 1] != '1' && \
		data->mapper->map[y][x - 1] != '0' && \
			data->mapper->map[y][x - 1] \
			!= 'N' && data->mapper->map[y][x - 1] != 'S' && \
				data->mapper->map[y][x - 1] != 'E' && \
					data->mapper->map[y][x - 1] != 'W')
	{
		return (0);
	}
	return (1);
}

static int	wp_two(t_data	*data, int x, int y)
{
	if (data->mapper->map[y][x + 1] != '1' && \
		data->mapper->map[y][x + 1] != '0' && \
			data->mapper->map[y][x + 1] \
			!= 'N' && data->mapper->map[y][x + 1] != 'S' && \
				data->mapper->map[y][x + 1] != 'E' && \
					data->mapper->map[y][x + 1] != 'W')
	{
		return (0);
	}
	return (1);
}

static int	wp_three(t_data	*data, int x, int y)
{
	if (data->mapper->map[y - 1][x] != '1' && \
		data->mapper->map[y - 1][x] != '0' && \
			data->mapper->map[y - 1][x] \
			!= 'N' && data->mapper->map[y - 1][x] != 'S' && \
				data->mapper->map[y - 1][x] != 'E' && \
					data->mapper->map[y - 1][x] != 'W')
	{
		return (0);
	}
	return (1);
}

static int	wp_fourth(t_data	*data, int x, int y)
{
	printf("data->mapper->map[y] %s\n", data->mapper->map[y]);
	printf("wp: %i, %i %i \n", y, x, data->mapper->high_point);
	if (data->mapper->map[y + 1] == NULL)
		printf("pb\n"); 
	if (data->mapper->map[y + 1][x] != '1' && \
		data->mapper->map[y + 1][x] != '0' && \
			data->mapper->map[y + 1][x] \
			!= 'N' && data->mapper->map[y + 1][x] != 'S' && \
				data->mapper->map[y + 1][x] != 'E' && \
					data->mapper->map[y + 1][x] != 'W')
	{
		return (0);
	}
	printf("passe\n");
	return (1);
}

int	wall_parser_first(t_data	*data, int len, int x, int y)
{
	if (x == 0 || x == len - 1 || y == 0 || y == \
		data->mapper->height - 1)
		return (0);
	if (!wp_one(data, x, y))
		return (0);
	else if (!wp_two(data, x, y))
		return (0);
	else if (!wp_three(data, x, y))
		return (0);
	else if (!wp_fourth(data, x, y))
		return (0);
	return (1);
}
