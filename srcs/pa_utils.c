/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeniaux <lgeniaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:09:04 by hmarconn          #+#    #+#             */
/*   Updated: 2023/02/08 14:45:59 by lgeniaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cube.h"

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
	else if (type == 5)
		printf("Error\nMap not found\n");
}

void	free_execution(t_data *data)
{
	int	y;

	y = 0;
	while (y < 8)
	{
		if (data->info->texture[y] != NULL)
			free(data->info->texture[y]);
		y++;
	}
	if (data->info->texture != NULL)
		free(data->info->texture);
	if (data->info->mlx)
		free(data->info->mlx);
	if (data->info != NULL)
	{
		free(data->info);
	}
	if (data->raycast != NULL)
	{
		free(data->raycast);
	}
}

void	free_map(t_data	*data)
{
	int	y;

	y = 0;
	if (data->map_exists == 1)
	{
		while (y < data->index)
		{
			if (data->mapper->map[y])
				free(data->mapper->map[y]);
			y++;
		}
		free(data->mapper->map);
	}
}

void	the_end(t_data *data, int type)
{
	int	y;

	y = 0;
	print_type(type);
	printf("fin\n");
	if (data->buffer != NULL)
		free(data->buffer);
	free_map(data);
	y = 0;
	while (y < 4)
	{
		if (data->mapper->walls[y] != NULL)
			free(data->mapper->walls[y]);
		y++;
	}
	if (data->mapper->walls)
		free(data->mapper->walls);
	if (type == 6)
		free_execution(data);
	exit(18);
}
