/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeniaux <lgeniaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:48:04 by lgeniaux          #+#    #+#             */
/*   Updated: 2023/02/07 16:21:52 by lgeniaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cube.h"

void	calc_ray(t_data *data, t_raycast *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (data->info->posX - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - data->info->posX)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (data->info->posY - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - data->info->posY)
			* ray->delta_dist_y;
	}
}

void	draw_wall_floor_ceiling(t_data *data, t_raycast *ray)
{
	while (ray->y < ray->draw_end)
	{
		ray->texture_y = (int)ray->texture_pos & (TEXTURE_HEIGHT - 1);
		ray->texture_pos += ray->step;
		ray->color = data->info->texture[ray->texture_num][TEXTURE_HEIGHT
			* ray->texture_y + ray->texture_x];
		if (ray->side == 1)
			ray->color = (ray->color >> 1) & 8355711;
		data->info->buf[ray->y][ray->x] = ray->color;
		data->info->re_buf = 1;
		ray->y++;
	}
	if (ray->draw_end < 0)
		ray->draw_end = WINDOW_H;
	ray->y = ray->draw_end + 1;
	while (ray->y < WINDOW_H)
	{
		data->info->buf[ray->y][ray->x] = convert_rgb_int(data->mapper->floor);
		data->info->buf[WINDOW_H
			- ray->y][ray->x] = convert_rgb_int(data->mapper->ceiling);
		ray->y++;
	}
}

void	calc(t_data *data)
{
	t_raycast	*ray;

	ray = malloc(sizeof(t_raycast));
	if (!ray)
		return ;
	ray->x = 0;
	ray->i = 0;
	buffer_clear(data, ray);
	while (ray->x < WINDOW_W)
	{
		init_ray(data, ray);
		calc_ray(data, ray);
		wall_hit(data, ray);
		texturing_calc(data, ray);
		draw_wall_floor_ceiling(data, ray);
		ray->x++;
	}
}

int	main_loop(t_data *data)
{
	calc(data);
	draw(data);
	return (0);
}

int	exec_start(t_data *data)
{
	int	i;
	int	j;

	data->info = malloc(sizeof(t_info));
	data->info->mlx = mlx_init();
	data->info->posX = data->mapper->xplayer + 0.55;
	data->info->posY = data->mapper->yplayer + 0.55;
	player_direction(data);
	data->info->re_buf = 0;
	i = 0;
	while (i < WINDOW_H)
	{
		j = 0;
		while (j < WINDOW_W)
		{
			data->info->buf[i][j] = 0;
			j++;
		}
		i++;
	}
	data->info->texture = (int **)malloc(sizeof(int *) * 8);
	if (!data->info->texture)
		return (-1);
	i = 0;
	while (i < 8)
	{
		data->info->texture[i] = (int *)malloc(sizeof(int) * (TEXTURE_HEIGHT
					* TEXTURE_WIDTH));
		if (!data->info->texture[i])
			return (-1);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < TEXTURE_HEIGHT * TEXTURE_WIDTH)
		{
			data->info->texture[i][j] = 0;
			j++;
		}
		i++;
	}
	load_texture(data);
	data->info->moveSpeed = 0.05;
	data->info->win = mlx_new_window(data->info->mlx, WINDOW_W, WINDOW_H,
			"mlx");
	data->info->img.img = mlx_new_image(data->info->mlx, WINDOW_W, WINDOW_H);
	data->info->img.data = (int *)mlx_get_data_addr(data->info->img.img,
			&data->info->img.bpp,
			&data->info->img.size_l,
			&data->info->img.endian);
	mlx_hook(data->info->mlx, 33, 1L << 17, &ft_exit, data);
	mlx_hook(data->info->win, 2, 1L << 0, &key_press, data);
	mlx_loop_hook(data->info->mlx, &main_loop, data);
	mlx_loop(data->info->mlx);
	return (0);
}
