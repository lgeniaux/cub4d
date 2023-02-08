/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_genmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeniaux <lgeniaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:37:43 by hmarconn          #+#    #+#             */
/*   Updated: 2023/02/08 14:40:25 by lgeniaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cube.h"

static	int	the_map_maker_util(t_data	*data, int i)
{
	while (data->buff)
	{
		free(data->buff);
		data->buff = get_next_line(data->fd);
		if (i >= data->i)
			data->mapper->height++;
		i++;
	}
	return (i);
}

static int	the_map_maker(t_data *data)
{
	int	i;

	i = 0;
	data->buff = 0;
	data->fd = 0;
	data->mapper->height = 1;
	data->fd = open(data->doc, O_RDONLY);
	if (data->fd <= 0)
		return (0);
	data->buff = get_next_line(data->fd);
	i = the_map_maker_util(data, i);
	free(data->buff);
	close(data->fd);
	data->mapper->map = malloc(sizeof(char *) * (data->mapper->height + 2));
	if (!data->mapper->map)
		return (0);
	data->map_exists = 1;
	data->mapper->map[data->mapper->height + 1] = NULL;
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

static int	tmp_util(t_data	*data)
{
	int	i;

	i = 1;
	data->buffer = NULL;
	data->buffer = get_next_line(data->fd);
	while (data->buffer)
	{
		if (i >= data->i)
		{
			if (!the_map_filler(data))
			{
				free(data->buffer);
				data->buffer = NULL;
				return (0);
			}
		}
		free(data->buffer);
		data->buffer = get_next_line(data->fd);
		i++;
	}
	free(data->buffer);
	close(data->fd);
	return (1);
}

int	the_map_parser(t_data	*data)
{
	if (!the_map_maker(data))
		return (0);
	data->buff = NULL;
	data->fd = 0;
	data->fd = open(data->doc, O_RDONLY);
	if (data->fd <= 0)
	{
		return (0);
	}
	if (!tmp_util(data))
	{
		return (0);
	}
	if (!the_wall_parser(data))
	{
		return (0);
	}
	return (1);
}
