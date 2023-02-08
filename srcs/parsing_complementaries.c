/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_complementaries.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeniaux <lgeniaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:00:24 by hmarconn          #+#    #+#             */
/*   Updated: 2023/02/08 15:17:56 by lgeniaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cube.h"

static int	to_parse_one(t_data	*data)
{
	if (data->buffer[data->scroller] == 'N' || data->buffer[data->scroller] \
		== 'S' \
		|| data->buffer[data->scroller] == 'E' || \
			data->buffer[data->scroller] == 'W')
	{
		if (!pa_wallpapers(data))
			return (0);
	}
	return (1);
}

static int	to_parse_two(t_data	*data)
{
	if (data->buffer[data->scroller] == 'F' || \
		data->buffer[data->scroller] == 'C')
	{
		if (!pa_colors(data))
			return (0);
	}
	return (1);
}

static int	to_parse_three(t_data	*data)
{
	if (data->buffer[data->scroller] >= '0' && \
		data->buffer[data->scroller] <= '9')
	{
		data->fd_section = 1;
		return (1);
	}
	return (0);
}

static int	to_parse_four(t_data	*data)
{
	if (data->buffer[data->scroller] >= 33 && \
		data->buffer[data->scroller] <= 126)
	{
		return (0);
	}
	return (1);
}

int	to_parse(t_data	*data)
{
	data->scroller = 0;
	data->i++;
	printf("%i\n", data->i);
	while (data->buffer[data->scroller] != '\0')
	{
		if (data->fd_section == 0)
		{
			toparse_scroll(data);
			while (data->buffer[data->scroller] && \
				(data->buffer[data->scroller] >= 33 && \
				data->buffer[data->scroller] <= 126) && data->fd_section == 0)
			{
				if (!to_parse_one(data))
					return (0);
				else if (!to_parse_two(data))
					return (0);
				else if (to_parse_three(data))
					return (1);
				else if (!to_parse_four(data))
					return (0);
			}
		}
	}
	return (1);
}
