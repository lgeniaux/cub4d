/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeniaux <lgeniaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:08:41 by lgeniaux          #+#    #+#             */
/*   Updated: 2023/02/08 15:28:38 by lgeniaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cube.h"

static void	north(t_data *data)
{
	data->info->dir_x = 0.0;
	data->info->dir_y = -1.0;
	data->info->plane_x = 0.66;
	data->info->plane_y = 0.0;
	data->info->rot_speed = -0.05;
}

static void	south(t_data *data)
{
	data->info->dir_x = 0.0;
	data->info->dir_y = 1.0;
	data->info->plane_x = -0.66;
	data->info->plane_y = 0.0;
	data->info->rot_speed = 0.05;
}

static void	east(t_data *data)
{
	data->info->dir_x = 1.0;
	data->info->dir_y = 0.0;
	data->info->plane_x = 0.0;
	data->info->plane_y = 0.66;
	data->info->rot_speed = 0.05;
}

static void	west(t_data *data)
{
	data->info->dir_x = -1.0;
	data->info->dir_y = 0.0;
	data->info->plane_x = 0.0;
	data->info->plane_y = -0.66;
	data->info->rot_speed = -0.05;
}

void	player_direction(t_data *data)
{
	if (data->mapper->player == NORTH)
		north(data);
	else if (data->mapper->player == SOUTH)
		south(data);
	else if (data->mapper->player == EAST)
		east(data);
	else if (data->mapper->player == WEST)
		west(data);
}
