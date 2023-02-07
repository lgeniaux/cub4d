/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeniaux <lgeniaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:22:33 by lgeniaux          #+#    #+#             */
/*   Updated: 2023/02/07 16:35:46 by lgeniaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cube.h"

void	move_forward(t_data *data)
{
	if (data->mapper->map[(int)(data->info->posY)][(int)(data->info->posX
			+ data->info->dirX * data->info->moveSpeed)] != '1')
		data->info->posX += data->info->dirX * data->info->moveSpeed;
	if (data->mapper->map[(int)(data->info->posY + data->info->dirY
			* data->info->moveSpeed)][(int)(data->info->posX)] != '1')
		data->info->posY += data->info->dirY * data->info->moveSpeed;
}

void	move_backward(t_data *data)
{
	if (data->mapper->map[(int)(data->info->posY)][(int)(data->info->posX
			- data->info->dirX * data->info->moveSpeed)] != '1')
		data->info->posX -= data->info->dirX * data->info->moveSpeed;
	if (data->mapper->map[(int)(data->info->posY - data->info->dirY
			* data->info->moveSpeed)][(int)(data->info->posX)] != '1')
		data->info->posY -= data->info->dirY * data->info->moveSpeed;
}

void	rotate_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->info->dirX;
	data->info->dirX = data->info->dirX * cos(data->info->rotSpeed)
		- data->info->dirY * sin(data->info->rotSpeed);
	data->info->dirY = old_dir_x * sin(data->info->rotSpeed) + data->info->dirY
		* cos(data->info->rotSpeed);
	old_plane_x = data->info->planeX;
	data->info->planeX = data->info->planeX * cos(data->info->rotSpeed)
		- data->info->planeY * sin(data->info->rotSpeed);
	data->info->planeY = old_plane_x * sin(data->info->rotSpeed)
		+ data->info->planeY * cos(data->info->rotSpeed);
}

void	rotate_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->info->dirX;
	data->info->dirX = data->info->dirX * cos(-data->info->rotSpeed)
		- data->info->dirY * sin(-data->info->rotSpeed);
	data->info->dirY = old_dir_x * sin(-data->info->rotSpeed) + data->info->dirY
		* cos(-data->info->rotSpeed);
	old_plane_x = data->info->planeX;
	data->info->planeX = data->info->planeX * cos(-data->info->rotSpeed)
		- data->info->planeY * sin(-data->info->rotSpeed);
	data->info->planeY = old_plane_x * sin(-data->info->rotSpeed)
		+ data->info->planeY * cos(-data->info->rotSpeed);
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
