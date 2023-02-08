/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_wallpapers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeniaux <lgeniaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:54:45 by hmarconn          #+#    #+#             */
/*   Updated: 2023/02/08 14:02:59 by lgeniaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cube.h"

void	pa_wallsupervision(t_data	*data, int wall)
{
	if (wall == 0)
		data->mapper->north_wall = 1;
	else if (wall == 1)
		data->mapper->south_wall = 1;
	else if (wall == 2)
		data->mapper->east_wall = 1;
	else
		data->mapper->west_wall = 1;
}

int	pa_wallsupervision_prequel(t_data	*data, int wall)
{
	if (wall == 0 && data->mapper->north_wall == 1)
		return (0);
	else if (wall == 1 && data->mapper->south_wall == 1)
		return (0);
	else if (wall == 2 && data->mapper->east_wall == 1)
		return (0);
	else if (wall == 3 && data->mapper->west_wall == 1)
		return (0);
	return (1);
}

void	pa_wallbuilder(t_data	*data, int wall)
{
	int		pan;
	int		pin;
	int		len;
	char	*tmp;

	pan = 0;
	pin = data->scroller;
	len = pa_getlen(data);
	tmp = ft_calloc(len + 1, sizeof(char));
	if (!tmp)
		the_end(data, 0);
	while (pan < len)
		tmp[pan++] = data->buffer[pin++];
	tmp[pan] = '\0';
	data->mapper->walls[wall] = ft_strdup(tmp);
	free(tmp);
	pa_wallsupervision(data, wall);
}

int	pa_walls(t_data	*data, int wall)
{
	data->scroller += 2;
	if (!pa_wallsupervision_prequel(data, wall))
	{
		free(data->buffer);
		data->buffer = NULL;
		return (0);
	}
	while (data->buffer[data->scroller] && (data->buffer[data->scroller] < 33 \
		|| data->buffer[data->scroller] > 126))
		data->scroller++;
	if (data->buffer[data->scroller] && data->buffer[data->scroller] == '.')
	{
		pa_wallbuilder(data, wall);
		return (1);
	}
	return (0);
}

int	pa_wallpapers(t_data	*data)
{
	int	i;

	i = 0;
	if (data->buffer[data->scroller] == 'N' && data->buffer[data->scroller + 1] \
		== 'O')
		i = pa_walls(data, 0);
	else if (data->buffer[data->scroller] == 'S' \
		&& data->buffer[data->scroller + 1] == 'O')
		i = pa_walls(data, 1);
	else if (data->buffer[data->scroller] == 'W' \
		&& data->buffer[data->scroller + 1] == 'E')
		i = pa_walls(data, 2);
	else if (data->buffer[data->scroller] == 'E' \
		&& data->buffer[data->scroller + 1] == 'A')
		i = pa_walls(data, 3);
	else
		return (0);
	if (i == 0)
		return (0);
	return (1);
}
