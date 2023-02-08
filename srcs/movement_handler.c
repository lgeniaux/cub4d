/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeniaux <lgeniaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:22:33 by lgeniaux          #+#    #+#             */
/*   Updated: 2023/02/08 15:32:49 by lgeniaux         ###   ########.fr       */
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

void	rotate_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->info->dir_x;
	data->info->dir_x = data->info->dir_x * cos(data->info->rot_speed)
		- data->info->dir_y * sin(data->info->rot_speed);
	data->info->dir_y = old_dir_x * sin(data->info->rot_speed)
		+ data->info->dir_y * cos(data->info->rot_speed);
	old_plane_x = data->info->plane_x;
	data->info->plane_x = data->info->plane_x
		* cos(data->info->rot_speed) - data->info->plane_y
		* sin(data->info->rot_speed);
	data->info->plane_y = old_plane_x * sin(data->info->rot_speed)
		+ data->info->plane_y * cos(data->info->rot_speed);
}

void	rotate_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->info->dir_x;
	data->info->dir_x = data->info->dir_x * cos(-data->info->rot_speed)
		- data->info->dir_y * sin(-data->info->rot_speed);
	data->info->dir_y = old_dir_x
		* sin(-data->info->rot_speed) + data->info->dir_y
		* cos(-data->info->rot_speed);
	old_plane_x = data->info->plane_x;
	data->info->plane_x = data->info->plane_x * cos(-data->info->rot_speed)
		- data->info->plane_y * sin(-data->info->rot_speed);
	data->info->plane_y = old_plane_x * sin(-data->info->rot_speed)
		+ data->info->plane_y * cos(-data->info->rot_speed);
}

int	key_press(int key, t_data *data)
{
	if (key == K_W)
		move_forward(data);
	if (key == K_S)
		move_backward(data);
	if (key == K_D)
		rotate_right(data);
	if (key == K_A)
		rotate_left(data);
	if (key == K_ESC)
		ft_exit(data);
	mlx_clear_window(data->info->mlx, data->info->win);
	main_loop(data);
	return (0);
}
