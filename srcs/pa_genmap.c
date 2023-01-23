/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_genmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:37:43 by hmarconn          #+#    #+#             */
/*   Updated: 2023/01/23 14:48:15 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cube.h"

static int	the_map_maker(t_data *data)
{
	int	x;
	int	y;
	int	i;
	int	test;

	i = 0;
	x = 0;
	y = 0;
	test = 0;
	data->buff = 0;
	data->fd = 0;
	data->mapper->height = 1;
	data->fd = open(data->doc, O_RDONLY);
	if (data->fd <= 0)
		return (0);
	data->buff = get_next_line(data->fd);
	while (data->buff)
	{
		free(data->buff);
		data->buff = get_next_line(data->fd);
		if (i >= data->i)
			data->mapper->height++;
		i++;
	}
	free(data->buff);
	close(data->fd);
	data->mapper->map = malloc(sizeof(char *) * data->mapper->height);
	if (!data->mapper->map)
		return (0);
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
		if ((buffer[0] < 33 || buffer[0] > 126) && (buffer[0] != '\0' && \
			buffer[0] != '\n'))
		{
			while (x < len && buffer[x] != '1' && buffer[x] != '0' && \
				buffer[x] != 'N' && buffer[x] != 'S' && buffer[x] != 'E' && \
					buffer[x] != 'W')
				x++;
			if (x == len && data->mapper->high_point == 0)
				data->mapper->high_point = data->y;
		}
		if (len == 1 && (buffer[0] == '\n' && data->mapper->high_point == 0))
			data->mapper->high_point = data->y;
		x = 0;
		data->mapper->map[data->y] = ft_calloc(len + 1, sizeof(char));
		if (!data->mapper->map[data->y])
			return (0);
		while (buffer[x] != '\0')
		{
			data->mapper->map[data->y][x] = buffer[x];
			x++;
		}
		data->mapper->map[data->y][x] = '\0';
		data->y++;
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

int	ft_strlen_parsing(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	the_wall_parser(t_data	*data)
{
	int	y;
	int	x;
	int	len;
	int	last_len;

	y = 0;
	len = 0;
	if (data->mapper->high_point == 0)
		data->mapper->high_point = data->y;
	while (y < data->mapper->high_point)
	{
		len = ft_strlen_parsing(data->mapper->map[y]);
		x = 0;
		while (x < len)
		{
			if (data->mapper->map[y][x] == '0')
			{
				if (x == 0 || x == len - 1 || y == 0 || y == \
					data->mapper->height - 1)
					return (0);
				if (data->mapper->map[y][x - 1] != '1' && \
					data->mapper->map[y][x - 1] != '0' && \
						data->mapper->map[y][x - 1] \
						!= 'N' && data->mapper->map[y][x - 1] != 'S' && \
							data->mapper->map[y][x - 1] != 'E' && \
								data->mapper->map[y][x - 1] != 'W')
					return (0);
				else if (data->mapper->map[y][x + 1] != '1' && \
					data->mapper->map[y][x + 1] != '0' && \
						data->mapper->map[y][x + 1] \
						!= 'N' && data->mapper->map[y][x + 1] != 'S' && \
							data->mapper->map[y][x + 1] != 'E' && \
								data->mapper->map[y][x + 1] != 'W')
					return (0);
				else if (data->mapper->map[y - 1][x] != '1' && \
					data->mapper->map[y - 1][x] != '0' && \
						data->mapper->map[y - 1][x] \
						!= 'N' && data->mapper->map[y - 1][x] != 'S' && \
							data->mapper->map[y - 1][x] != 'E' && \
								data->mapper->map[y - 1][x] != 'W')
					return (0);
				else if (data->mapper->map[y + 1][x] != '1' && \
					data->mapper->map[y + 1][x] != '0' && \
						data->mapper->map[y + 1][x] \
						!= 'N' && data->mapper->map[y + 1][x] != 'S' && \
							data->mapper->map[y + 1][x] != 'E' && \
								data->mapper->map[y + 1][x] != 'W')
					return (0);
			}
			else if (data->mapper->map[y][x] == 'N' || \
				data->mapper->map[y][x] == 'S' || data->mapper->map[y][x] \
					== 'E' || data->mapper->map[y][x] == 'W')
			{
				if (data->mapper->player == 0)
				{
					data->mapper->xplayer = x;
					data->mapper->yplayer = y;
					data->mapper->player = 1;
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
			}
			else if (data->mapper->map[y][x] != '1' && data->mapper->map[y][x] \
				!= '\n' && data->mapper->map[y][x] != '\0' && \
					data->mapper->map[y][x] != ' ')
				return (0);
			last_len = len;
			x++;
		}	
		y++;
	}
	return (1);
}

int	the_map_parser(t_data	*data)
{
	int	i;

	i = 1;
	if (!the_map_maker(data))
	{
		printf("test3\n");
		return (0);
	}
	data->buff = NULL;
	data->fd = 0;
	data->fd = open(data->doc, O_RDONLY);
	if (data->fd <= 0)
		return (0);
	data->buff = get_next_line(data->fd);
	while (data->buff)
	{
		if (i >= data->i)
		{
			if (!the_map_filler(data, data->buff))
			{
				printf("test2\n");
				return (0);
			}
		}
		free(data->buff);
		data->buff = get_next_line(data->fd);
		i++;
	}
	if (data->buff != NULL)
		free(data->buff);
	close(data->fd);
	if (!the_wall_parser(data))
	{
		printf("test1\n");
		return (0);
	}
	return (1);
}
