/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_handler_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeniaux <lgeniaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:25:48 by lgeniaux          #+#    #+#             */
/*   Updated: 2023/02/08 16:26:59 by lgeniaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cube.h"

void	move_forward(t_data *data)
{
	if (data->mapper->map[(int)(data->info->pos_y)][(int)(data->info->pos_x
			+ data->info->dir_x * data->info->move_speed)] != '1')
		data->info->pos_x += data->info->dir_x * data->info->move_speed;
	if (data->mapper->map[(int)(data->info->pos_y + data->info->dir_y
			* data->info->move_speed)][(int)(data->info->pos_x)] != '1')
		data->info->pos_y += data->info->dir_y * data->info->move_speed;
}

void	move_backward(t_data *data)
{
	if (data->mapper->map[(int)(data->info->pos_y)][(int)(data->info->pos_x
			- data->info->dir_x * data->info->move_speed)] != '1')
		data->info->pos_x -= data->info->dir_x * data->info->move_speed;
	if (data->mapper->map[(int)(data->info->pos_y - data->info->dir_y
			* data->info->move_speed)][(int)(data->info->pos_x)] != '1')
		data->info->pos_y -= data->info->dir_y * data->info->move_speed;
}

void	move_left(t_data *data)
{
	if (data->mapper->map[(int)(data->info->pos_y)][(int)(data->info->pos_x
			- data->info->plane_x * data->info->move_speed)] != '1')
		data->info->pos_x -= data->info->plane_x * data->info->move_speed;
	if (data->mapper->map[(int)(data->info->pos_y - data->info->plane_y
			* data->info->move_speed)][(int)(data->info->pos_x)] != '1')
		data->info->pos_y -= data->info->plane_y * data->info->move_speed;
}

void	move_right(t_data *data)
{
	if (data->mapper->map[(int)(data->info->pos_y)][(int)(data->info->pos_x
			+ data->info->plane_x * data->info->move_speed)] != '1')
		data->info->pos_x += data->info->plane_x * data->info->move_speed;
	if (data->mapper->map[(int)(data->info->pos_y + data->info->plane_y
			* data->info->move_speed)][(int)(data->info->pos_x)] != '1')
		data->info->pos_y += data->info->plane_y * data->info->move_speed;
}
