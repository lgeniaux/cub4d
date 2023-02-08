/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeniaux <lgeniaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:41:50 by lgeniaux          #+#    #+#             */
/*   Updated: 2023/02/08 14:54:38 by lgeniaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cube.h"

void	buffer_clear(t_data *data, t_raycast *ray)
{
	if (data->info->re_buf == 1)
	{
		while (ray->i < WINDOW_H)
		{
			ray->j = 0;
			while (ray->j < WINDOW_W)
			{
				data->info->buf[ray->i][ray->j] = 0;
				ray->j++;
			}
			ray->i++;
		}
	}
}

void	texturing_calc_2(t_data *data, t_raycast *ray)
{
	if (ray->side == 0)
		ray->wall_x = data->info->posY + ray->perp_wall_dist * ray->ray_dir_y;
	else
		ray->wall_x = data->info->posX + ray->perp_wall_dist * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->texture_x = (int)(ray->wall_x * (double)TEXTURE_WIDTH);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		ray->texture_x = TEXTURE_WIDTH - ray->texture_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		ray->texture_x = TEXTURE_WIDTH - ray->texture_x - 1;
	ray->step = 1.0 * TEXTURE_HEIGHT / ray->line_height;
	ray->texture_pos = (ray->draw_start - WINDOW_H / 2 + ray->line_height / 2)
		* ray->step;
	ray->y = ray->draw_start;
}

void	texturing_calc(t_data *data, t_raycast *ray)
{
	ray->line_height = (int)(WINDOW_H / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + WINDOW_H / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WINDOW_H / 2;
	if (ray->draw_end >= WINDOW_H)
		ray->draw_end = WINDOW_H - 1;
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			ray->texture_num = 0;
		else
			ray->texture_num = 1;
	}
	else
	{
		if (ray->ray_dir_y > 0)
			ray->texture_num = 2;
		else
			ray->texture_num = 3;
	}
	texturing_calc_2(data, ray);
}

void	init_ray(t_data *data, t_raycast *ray)
{
	ray->camera_x = 2 * ray->x / (double)WINDOW_W - 1;
	ray->ray_dir_x = data->info->dirX + data->info->planeX * ray->camera_x;
	ray->ray_dir_y = data->info->dirY + data->info->planeY * ray->camera_x;
	ray->map_x = (int)data->info->posX;
	ray->map_y = (int)data->info->posY;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
}

void	wall_hit(t_data *data, t_raycast *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (data->mapper->map[ray->map_y][ray->map_x] - '0' == 1)
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - data->info->posX + (1 - ray->step_x)
				/ 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - data->info->posY + (1 - ray->step_y)
				/ 2) / ray->ray_dir_y;
}
