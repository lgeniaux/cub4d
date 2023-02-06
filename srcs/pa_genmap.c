/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_genmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:37:43 by hmarconn          #+#    #+#             */
/*   Updated: 2023/01/23 16:35:41 by hmarconn         ###   ########.fr       */
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
	data->mapper->map = malloc(sizeof(char *) * data->mapper->height);
	if (!data->mapper->map)
		return (0);
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
