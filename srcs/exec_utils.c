/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeniaux <lgeniaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:20:20 by lgeniaux          #+#    #+#             */
/*   Updated: 2023/02/07 16:34:42 by lgeniaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cube.h"

void	load_image(t_data *data, int *texture, char *path, t_img *img)
{
	int	x;
	int	y;

	img->img = mlx_xpm_file_to_image(data->info->mlx, path, &img->img_width,
			&img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l,
			&img->endian);
	y = 0;
	while (y < img->img_height)
	{
		x = 0;
		while (x < img->img_width)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
			x++;
		}
		y++;
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
	int	x;
	int	y;

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
