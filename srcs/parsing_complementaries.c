/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_complementaries.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:00:24 by hmarconn          #+#    #+#             */
/*   Updated: 2023/01/26 17:45:53 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cube.h"

static int	to_parse_one(t_data	*data, char	*buffer)
{
	if (buffer[data->scroller] == 'N' || buffer[data->scroller] \
		== 'S' \
		|| buffer[data->scroller] == 'E' || \
			buffer[data->scroller] == 'W')
	{
		if (!pa_wallpapers(data, buffer))
			return (0);
	}
	return (1);
}

static int	to_parse_two(t_data	*data, char	*buffer)
{
	if (buffer[data->scroller] == 'F' || \
		buffer[data->scroller] == 'C')
	{
		if (!pa_colors(data, buffer))
			return (0);
	}
	return (1);
}

static int	to_parse_three(t_data	*data, char	*buffer)
{
	if (buffer[data->scroller] >= '0' && \
		buffer[data->scroller] <= '9')
	{
		data->fd_section = 1;
		return (1);
	}
	return (0);
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
				if (!to_parse_one(data, buffer))
					return (0);
				else if (!to_parse_two(data, buffer))
					return (0);
				else if (to_parse_three(data, buffer))
					return (1);
				else if (buffer[data->scroller] >= 33 && \
					buffer[data->scroller] <= 126)
				{
					free(buffer);
					return (0);
				}
			}
		}
	}
	return (1);
}
