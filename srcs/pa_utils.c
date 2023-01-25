/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:09:04 by hmarconn          #+#    #+#             */
/*   Updated: 2023/01/25 19:03:39 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cube.h"

int	pa_getlen(t_data	*data, char	*buffer)
{
	int	len;

	len = 0;
	while (buffer[data->scroller] && (buffer[data->scroller] >= 33 && \
		buffer[data->scroller] <= 126))
	{
		len++;
		data->scroller++;
	}
	return (len);
}

void	print_type(int type)
{
	if (type == 0)
		return ;
	if (type == 1)
		printf("Error\nInvalid document\n");
	else if (type == 2)
		printf("Error\nInvalid elements\n");
	else if (type == 3)
		printf("Error\nInvalid Map\n");
	else if (type == 4)
		printf("Error\nMissing informations\n");
}

void	the_end(t_data	*data, int type)
{
	int	y;

	y = 0;
	while (y < data->mapper->height)
	{
		printf("%s\n", data->mapper->map[y]);
		y++;
	}
	y = 0;
	print_type(type);
	if (data->map_exists == 1)
	{
		printf("tester %i, %i\n", data->mapper->height, data->mapper->high_point);
		while (y < data->mapper->high_point)
		{
			printf("ici\n");
			if (data->mapper->map[y] != NULL)
			{
				printf("la %i\n", y);
				free(data->mapper->map[y]);
			}
			printf("cool\n");
			y++;
		}
		free(data->mapper->map);
	}
	y = 0;
	while (y < 4)
	{
		free(data->mapper->walls[y]);
		y++;
	}
}
