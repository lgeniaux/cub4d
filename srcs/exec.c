/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeniaux <lgeniaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:48:04 by lgeniaux          #+#    #+#             */
/*   Updated: 2023/02/06 14:59:46 by lgeniaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cube.h"
//#include "../mlx_linux/mlx.h"
//#include <math.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>

static void	north(t_data *data)
{
	data->info->dirX = 0.0;
	data->info->dirY = -1.0;
	data->info->planeX = 0.66;
	data->info->planeY = 0.0;
	data->info->rotSpeed = -0.05;
}

static void	south(t_data *data)
{
	data->info->dirX = 0.0;
	data->info->dirY = 1.0;
	data->info->planeX = -0.66;
	data->info->planeY = 0.0;
	data->info->rotSpeed = 0.05;
}

static void	east(t_data *data)
{
	data->info->dirX = 1.0;
	data->info->dirY = 0.0;
	data->info->planeX = 0.0;
	data->info->planeY = 0.66;
	data->info->rotSpeed = 0.05;
}

static void	west(t_data *data)
{
	data->info->dirX = -1.0;
	data->info->dirY = 0.0;
	data->info->planeX = 0.0;
	data->info->planeY = -0.66;
	data->info->rotSpeed = -0.05;
}

static void	player_direction(t_data *data)
{
	if (data->mapper->player == 'N')
		north(data);
	else if (data->mapper->player == 'S')
		south(data);
	else if (data->mapper->player == 'E')
		east(data);
	else if (data->mapper->player == 'W')
		west(data);
}

int	convert_rgb_int(int *rgb)
{
	int	r;
	int	g;
	int	b;

	r = rgb[0];
	g = rgb[1];
	b = rgb[2];
	return (r << 16 | g << 8 | b);
}

void	draw(t_data *data)
{
	int x;
	int y;

	y = 0;
	while (y < WINDOW_H)
	{
		x = 0;
		while (x < WINDOW_W)
		{
			data->info->img.data[y * WINDOW_W + x] = data->info->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->info->mlx, data->info->win,
		data->info->img.img, 0, 0);
}

void	calc(t_data *data)
{
	int		x;
	int		texture_num;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
		double side_dist_x;
		double side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
		double perp_wall_dist;
		int step_x;
		int step_y;
	int		hit;
		int side;
	int		line_height;
	int		draw_start;
	int		draw_end;
		double wall_x;
	int		texture_x;
	double	step;
	double	texture_pos;
	int		texture_y;
	int		color;

	x = 0;
	if (data->info->re_buf == 1)
	{
		for (int i = 0; i < WINDOW_H; i++)
		{
			for (int j = 0; j < WINDOW_W; j++)
			{
				data->info->buf[i][j] = 0;
			}
		}
	}
	while (x < WINDOW_W)
	{
		camera_x = 2 * x / (double)WINDOW_W - 1;
		ray_dir_x = data->info->dirX + data->info->planeX * camera_x;
		ray_dir_y = data->info->dirY + data->info->planeY * camera_x;
		map_x = (int)data->info->posX;
		map_y = (int)data->info->posY;
		delta_dist_x = fabs(1 / ray_dir_x);
		delta_dist_y = fabs(1 / ray_dir_y);
		hit = 0;
		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (data->info->posX - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - data->info->posX) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (data->info->posY - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - data->info->posY) * delta_dist_y;
		}
		while (hit == 0)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			if (data->mapper->map[map_y][map_x] - '0' == 1)
				hit = 1;
		}
		if (side == 0)
			perp_wall_dist = (map_x - data->info->posX + (1 - step_x) / 2)
				/ ray_dir_x;
		else
			perp_wall_dist = (map_y - data->info->posY + (1 - step_y) / 2)
				/ ray_dir_y;
		line_height = (int)(WINDOW_H / perp_wall_dist);
		draw_start = -line_height / 2 + WINDOW_H / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + WINDOW_H / 2;
		if (draw_end >= WINDOW_H)
			draw_end = WINDOW_H - 1;
		if (side == 0)
			texture_num = ray_dir_x > 0 ? 0 : 1;
		else
			texture_num = ray_dir_y > 0 ? 2 : 3;
		if (side == 0)
			wall_x = data->info->posY + perp_wall_dist * ray_dir_y;
		else
			wall_x = data->info->posX + perp_wall_dist * ray_dir_x;
		wall_x -= floor(wall_x);
		texture_x = (int)(wall_x * (double)TEXTURE_WIDTH);
		if (side == 0 && ray_dir_x > 0)
			texture_x = TEXTURE_WIDTH - texture_x - 1;
		if (side == 1 && ray_dir_y < 0)
			texture_x = TEXTURE_WIDTH - texture_x - 1;
		step = 1.0 * TEXTURE_HEIGHT / line_height;
		texture_pos = (draw_start - WINDOW_H / 2 + line_height / 2) * step;
		for (int y = draw_start; y < draw_end; y++)
		{
			texture_y = (int)texture_pos & (TEXTURE_HEIGHT - 1);
			texture_pos += step;
			color = data->info->texture[texture_num][TEXTURE_HEIGHT * texture_y + texture_x];
			if (side == 1)
				color = (color >> 1) & 8355711;
			data->info->buf[y][x] = color;
			data->info->re_buf = 1;
		}
		double floorXWall, floorYWall;
		if (side == 0 && ray_dir_x > 0)
		{
			floorXWall = map_x;
			floorYWall = map_y + wall_x;
		}
		else if (side == 0 && ray_dir_x < 0)
		{
			floorXWall = map_x + 1.0;
			floorYWall = map_y + wall_x;
		}
		else if (side == 1 && ray_dir_y > 0)
		{
			floorXWall = map_x + wall_x;
			floorYWall = map_y;
		}
		else
		{
			floorXWall = map_x + wall_x;
			floorYWall = map_y + 1.0;
		}
		double distWall, distPlayer, currentDist;
		distWall = perp_wall_dist;
		distPlayer = 0.0;
		if (draw_end < 0)
			draw_end = WINDOW_H;
		for (int y = draw_end + 1; y < WINDOW_H; y++)
		{
			currentDist = WINDOW_H / (2.0 * y - WINDOW_H);
			data->info->buf[y][x] = convert_rgb_int(data->mapper->floor);
			data->info->buf[WINDOW_H
				- y][x] = convert_rgb_int(data->mapper->ceiling);
		}
		x++;
	}
}

int	main_loop(t_data *data)
{
	calc(data);
	draw(data);
	return (0);
}

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
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = data->info->dirX;
	data->info->dirX = data->info->dirX * cos(data->info->rotSpeed)
		- data->info->dirY * sin(data->info->rotSpeed);
	data->info->dirY = oldDirX * sin(data->info->rotSpeed) + data->info->dirY
		* cos(data->info->rotSpeed);
	oldPlaneX = data->info->planeX;
	data->info->planeX = data->info->planeX * cos(data->info->rotSpeed)
		- data->info->planeY * sin(data->info->rotSpeed);
	data->info->planeY = oldPlaneX * sin(data->info->rotSpeed)
		+ data->info->planeY * cos(data->info->rotSpeed);
}

void	rotate_right(t_data *data)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = data->info->dirX;
	data->info->dirX = data->info->dirX * cos(-data->info->rotSpeed)
		- data->info->dirY * sin(-data->info->rotSpeed);
	data->info->dirY = oldDirX * sin(-data->info->rotSpeed) + data->info->dirY
		* cos(-data->info->rotSpeed);
	oldPlaneX = data->info->planeX;
	data->info->planeX = data->info->planeX * cos(-data->info->rotSpeed)
		- data->info->planeY * sin(-data->info->rotSpeed);
	data->info->planeY = oldPlaneX * sin(-data->info->rotSpeed)
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
		exit(0);
	mlx_clear_window(data->info->mlx, data->info->win);
	main_loop(data);
	return (0);
}

void	load_image(t_data *data, int *texture, char *path, t_img *img)
{
	img->img = mlx_xpm_file_to_image(data->info->mlx, path, &img->img_width,
			&img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l,
			&img->endian);
	for (int y = 0; y < img->img_height; y++)
	{
		for (int x = 0; x < img->img_width; x++)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
		}
	}
	mlx_destroy_image(data->info->mlx, img->img);
}

void	load_texture(t_data *data)
{
	t_img	img;

	load_image(data, data->info->texture[0], data->mapper->walls[3], &img);
	load_image(data, data->info->texture[1], data->mapper->walls[2], &img);
	load_image(data, data->info->texture[2], data->mapper->walls[1], &img);
	load_image(data, data->info->texture[3], data->mapper->walls[0], &img);
}

int	ft_exit(t_data *data)
{
	mlx_destroy_window(data->info->mlx, data->info->win);
	exit(0);
}

int	exec_start(t_data *data)
{
	data->info = malloc(sizeof(t_info));
	data->info->mlx = mlx_init();
	data->info->posX = data->mapper->xplayer + 0.55;
	data->info->posY = data->mapper->yplayer + 0.55;
	player_direction(data);
	data->info->re_buf = 0;
	for (int i = 0; i < WINDOW_H; i++)
	{
		for (int j = 0; j < WINDOW_W; j++)
		{
			data->info->buf[i][j] = 0;
		}
	}
	if (!(data->info->texture = (int **)malloc(sizeof(int *) * 8)))
		return (-1);
	for (int i = 0; i < 8; i++)
	{
		if (!(data->info->texture[i] = (int *)malloc(sizeof(int)
					* (TEXTURE_HEIGHT * TEXTURE_WIDTH))))
			return (-1);
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < TEXTURE_HEIGHT * TEXTURE_WIDTH; j++)
		{
			data->info->texture[i][j] = 0;
		}
	}
	load_texture(data);
	data->info->moveSpeed = 0.05;
	data->info->win = mlx_new_window(data->info->mlx, WINDOW_W, WINDOW_H,
			"mlx");
	data->info->img.img = mlx_new_image(data->info->mlx, WINDOW_W, WINDOW_H);
	data->info->img.data = (int *)mlx_get_data_addr(data->info->img.img,
			&data->info->img.bpp, &data->info->img.size_l,
			&data->info->img.endian);
	mlx_hook(data->info->mlx, 33, 1L << 17, &ft_exit, data);
	mlx_hook(data->info->win, 2, 1L << 0, &key_press, data);
	mlx_loop_hook(data->info->mlx, &main_loop, data);
	mlx_loop(data->info->mlx);
}
