/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_wall_parser_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:28:38 by hmarconn          #+#    #+#             */
/*   Updated: 2023/02/08 13:37:33 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cube.h"

static void	set_player(t_data	*data, int x, int y)
{
	if (data->mapper->map[y][x] == 'N')
		data->mapper->player = 1;
	else if (data->mapper->map[y][x] == 'S')
		data->mapper->player = 2;
	else if (data->mapper->map[y][x] == 'E')
		data->mapper->player = 3;
	else if (data->mapper->map[y][x] == 'W')
		data->mapper->player = 4;
}

static int	wall_parser_second(t_data	*data, int len, int x, int y)
{
	if (data->mapper->player == 0)
	{
		data->mapper->xplayer = x;
		data->mapper->yplayer = y;
	}
	else
		return (0);
	if (x == 0 || x == len - 1 || y == 0 || y == \
		data->mapper->height - 1)
		return (0);
	if (data->mapper->map[y][x - 1] != '1' && \
		data->mapper->map[y][x - 1] != '0')
		return (0);
	else if (data->mapper->map[y][x + 1] != '1' && \
		data->mapper->map[y][x + 1] != '0')
		return (0);
	else if (data->mapper->map[y - 1][x] != '1' && \
		data->mapper->map[y - 1][x] != '0')
		return (0);
	else if (data->mapper->map[y + 1][x] != '1' && \
		data->mapper->map[y + 1][x] != '0')
		return (0);
	return (1);
}

static int	wall_parser_util(t_data	*data, int len, int x, int y)
{
	if (data->mapper->map[y][x] == '0')
	{
		if (!wall_parser_first(data, len, x, y))
		{
			printf("a\n");
			return (0);
		}
	}
	else if (data->mapper->map[y][x] == 'N' || \
		data->mapper->map[y][x] == 'S' || data->mapper->map[y][x] \
			== 'E' || data->mapper->map[y][x] == 'W')
	{
		if (!wall_parser_second(data, len, x, y))
		{
			printf("b\n");
			return (0);
		}
		set_player(data, x, y);
	}
	else if (data->mapper->map[y][x] != '1' && data->mapper->map[y][x] \
		!= '\n' && data->mapper->map[y][x] != '\0' && \
			data->mapper->map[y][x] != ' ')
	{
		return (0);
	}
	return (1);
}

int	the_wall_parser(t_data	*data)
{
	int	y;
	int	x;
	int	len;

	y = 0;
	len = 0;
	if (data->mapper->high_point == 0)
		data->mapper->high_point = data->y;
	y = 0;
	while (y < data->mapper->high_point)
	{
		len = ft_strlen_parsing(data->mapper->map[y]);
		x = 0;
		while (x < len)
		{
			if (!wall_parser_util(data, len, x, y))
				return (0);
			x++;
		}	
		y++;
	}
	return (1);
}
