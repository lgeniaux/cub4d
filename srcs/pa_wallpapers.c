/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_wallpapers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:54:45 by hmarconn          #+#    #+#             */
/*   Updated: 2023/01/26 17:35:30 by hmarconn         ###   ########.fr       */
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

void	pa_wallbuilder(t_data	*data, char	*buffer, int wall)
{
	int		pan;
	int		pin;
	int		len;
	char	*tmp;

	pan = 0;
	pin = data->scroller;
	len = pa_getlen(data, buffer);
	tmp = ft_calloc(len + 1, sizeof(char));
	if (!tmp)
		the_end(data, 0);
	while (pan < len)
		tmp[pan++] = buffer[pin++];
	tmp[pan] = '\0';
	data->mapper->walls[wall] = ft_strdup(tmp);
	free(tmp);
	pa_wallsupervision(data, wall);
}

int	pa_walls(t_data	*data, char	*buffer, int wall)
{
	data->scroller += 2;
	if (!pa_wallsupervision_prequel(data, wall))
	{
		free (buffer);
		return (0);
	}
	while (buffer[data->scroller] && (buffer[data->scroller] < 33 || \
		buffer[data->scroller] > 126))
		data->scroller++;
	if (buffer[data->scroller] && buffer[data->scroller] == '.')
	{
		pa_wallbuilder(data, buffer, wall);
		return (1);
	}
	return (0);
}

int	pa_wallpapers(t_data	*data, char	*buffer)
{
	int	i;

	i = 0;
	if (buffer[data->scroller] == 'N' && buffer[data->scroller + 1] == 'O')
		i = pa_walls(data, buffer, 0);
	else if (buffer[data->scroller] == 'S' && buffer[data->scroller + 1] == 'O')
		i = pa_walls(data, buffer, 1);
	else if (buffer[data->scroller] == 'W' && buffer[data->scroller + 1] == 'E')
		i = pa_walls(data, buffer, 2);
	else if (buffer[data->scroller] == 'E' && buffer[data->scroller + 1] == 'A')
		i = pa_walls(data, buffer, 3);
	else
		return (0);
	if (i == 0)
		return (0);
	return (1);
}
