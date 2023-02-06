#include "../mlx_linux/mlx.h"
#include "../incs/cube.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static void player_direction(t_data *data)
{
	if (data->mapper->player == 'N') {
		data->info->dirX = 0.0;
		data->info->dirY = -1.0;
		data->info->planeX = 0.66;
		data->info->planeY = 0.0;
		data->info->rotSpeed = -0.05;
	}
	else if (data->mapper->player == 'S') {
		data->info->dirX = 0.0;
		data->info->dirY = 1.0;
		data->info->planeX = -0.66;
		data->info->planeY = 0.0;
		data->info->rotSpeed = -0.05;
	}
	else if (data->mapper->player == 'E') {
		data->info->dirX = -1.0;
		data->info->dirY = 0.0;
		data->info->planeX = 0.0;
		data->info->planeY = 0.66;
		data->info->rotSpeed = 0.05;
	}
	else if (data->mapper->player == 'W') {
		data->info->dirX = 1.0;
		data->info->dirY = 0.0;
		data->info->planeX = 0.0;
		data->info->planeY = -0.66;
		data->info->rotSpeed = 0.05;
	}
}

void print_map(char** map, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

int find_greatest_dimension(char** map) {
	int rows = 0;
	while (map[rows] != NULL) {
		rows++;
	}
	rows--;
	int max_rows = rows;
	int cols = 0;
	int max_cols = 0;
	rows = 0;
	while (rows <= max_rows)
	{
		cols = 0;
		while (map[rows][cols] != '\n' && map[rows][cols] != '\0')
		{
			if (cols > max_cols)
				max_cols = cols;
			cols++;
		}
		rows++;
	}
	if (max_rows > max_cols)
		return (max_rows);
	else
		return (max_cols);
}

char **square_map(t_data *data)
{
	int i = 0;
	int j = 0;
    int max_dim = find_greatest_dimension(data->mapper->map);
 	
	char **map = (char **)malloc(max_dim * sizeof(char *));
	while (i < max_dim) {
    	map[i] = (char *)malloc(max_dim * sizeof(char));
    	i++;
  	}
  	i = 0;
  	while (i < max_dim) {
    	j = 0;
    	while (j < max_dim) {
      		map[i][j] = '0';
      		j++;
    	}
    	i++;
  	}
	i = 0;
	j = 0;
	while(data->mapper->map[i] != NULL) {
		j = 0;
		while (data->mapper->map[i][j] != '\n' && data->mapper->map[i][j] != '\0') {
			if (data->mapper->map[i][j] == '1')
				map[i][j] = '1';
			else
				map[i][j] = '0';
			j++;
		}
		i++;
	}
	while(i < max_dim) {
		j = 0;
		while (j < max_dim) {
			map[i][j] = '0';
			j++;
		}
		i++;
	}
	return (map);
}


void	draw(t_data *data)
{
	for (int y = 0; y < WINDOW_H; y++)
	{
		for (int x = 0; x < WINDOW_W; x++)
		{
			data->info->img.data[y * WINDOW_W + x] = data->info->buf[y][x];
		}
	}
	mlx_put_image_to_window(data->info->mlx, data->info->win, data->info->img.img, 0, 0);
}

void	calc(t_data *data)
{
	int	x;
	int y;
	int texNum;

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
		double cameraX = 2 * x / (double)WINDOW_W - 1;
		double rayDirX = data->info->dirX + data->info->planeX * cameraX;
		double rayDirY = data->info->dirY + data->info->planeY * cameraX;
		
		int mapX = (int)data->info->posX;
		int mapY = (int)data->info->posY;

		double sideDistX;
		double sideDistY;
		
		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);
		double perpWallDist;
		
		int stepX;
		int stepY;
		
		int hit = 0;
		int side;

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (data->info->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - data->info->posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (data->info->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - data->info->posY) * deltaDistY;
		}

		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (data->mapper->map[mapY][mapX] - '0' == 1)
                hit = 1;
		}
		if (side == 0)
			perpWallDist = (mapX - data->info->posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - data->info->posY + (1 - stepY) / 2) / rayDirY;

		int lineHeight = (int)(WINDOW_H / perpWallDist);

		int drawStart = -lineHeight / 2 + WINDOW_H / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + WINDOW_H / 2;
		if(drawEnd >= WINDOW_H)
			drawEnd = WINDOW_H - 1;

		if (data->mapper->map[mapY][mapX] == 'N' || data->mapper->map[mapY][mapX] == 'S' || data->mapper->map[mapY][mapX] == 'W' || data->mapper->map[mapY][mapX] == 'E' || data->mapper->map[mapY][mapX] == '0')
			texNum = 0;
		else 
			texNum = 1;

		double wallX;
		if (side == 0)
			wallX = data->info->posY + perpWallDist * rayDirY;
		else
			wallX = data->info->posX + perpWallDist * rayDirX;
		wallX -= floor(wallX);

		int texX = (int)(wallX * (double)TEXTURE_WIDTH);
		if (side == 0 && rayDirX > 0)
			texX = TEXTURE_WIDTH - texX - 1;
		if (side == 1 && rayDirY < 0)
			texX = TEXTURE_WIDTH - texX - 1;

		double step = 1.0 * TEXTURE_HEIGHT / lineHeight;
		double texPos = (drawStart - WINDOW_H / 2 + lineHeight / 2) * step;
		for (int y = drawStart; y < drawEnd; y++)
		{
			int texY = (int)texPos & (TEXTURE_HEIGHT - 1);
			texPos += step;
			int color = data->info->texture[texNum][TEXTURE_HEIGHT * texY + texX];
			if (side == 1)
				color = (color >> 1) & 8355711;
			data->info->buf[y][x] = color;
			data->info->re_buf = 1;
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

void move_forward(t_data *data)
{
		if (data->mapper->map[(int)(data->info->posY)][(int)(data->info->posX + data->info->dirX * data->info->moveSpeed)] != '1')
			data->info->posX += data->info->dirX * data->info->moveSpeed;
		if (data->mapper->map[(int)(data->info->posY + data->info->dirY * data->info->moveSpeed)][(int)(data->info->posX)] != '1')
			data->info->posY += data->info->dirY * data->info->moveSpeed;
}

void move_backward(t_data *data)
{
    if (data->mapper->map[(int)(data->info->posY)][(int)(data->info->posX - data->info->dirX * data->info->moveSpeed)] != '1')
        data->info->posX -= data->info->dirX * data->info->moveSpeed;
    if (data->mapper->map[(int)(data->info->posY - data->info->dirY * data->info->moveSpeed)][(int)(data->info->posX)] != '1')
        data->info->posY -= data->info->dirY * data->info->moveSpeed;
}


void rotate_left(t_data *data)
{

    double oldDirX = data->info->dirX;
    data->info->dirX = data->info->dirX * cos(data->info->rotSpeed) - data->info->dirY * sin(data->info->rotSpeed);
    data->info->dirY = oldDirX * sin(data->info->rotSpeed) + data->info->dirY * cos(data->info->rotSpeed);
    double oldPlaneX = data->info->planeX;
    data->info->planeX = data->info->planeX * cos(data->info->rotSpeed) - data->info->planeY * sin(data->info->rotSpeed);
    data->info->planeY = oldPlaneX * sin(data->info->rotSpeed) + data->info->planeY * cos(data->info->rotSpeed);
}

void rotate_right(t_data *data)
{
    double oldDirX = data->info->dirX;
    data->info->dirX = data->info->dirX * cos(-data->info->rotSpeed) - data->info->dirY * sin(-data->info->rotSpeed);
    data->info->dirY = oldDirX * sin(-data->info->rotSpeed) + data->info->dirY * cos(-data->info->rotSpeed);
    double oldPlaneX = data->info->planeX;
    data->info->planeX = data->info->planeX * cos(-data->info->rotSpeed) - data->info->planeY * sin(-data->info->rotSpeed);
    data->info->planeY = oldPlaneX * sin(-data->info->rotSpeed) + data->info->planeY * cos(-data->info->rotSpeed);
}

int key_press(int key, t_data *data)
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
	img->img = mlx_xpm_file_to_image(data->info->mlx, path, &img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
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

	load_image(data, data->info->texture[0], "textures/eagle.xpm", &img);
	load_image(data, data->info->texture[1], "textures/redbrick.xpm", &img);
	load_image(data, data->info->texture[2], "textures/purplestone.xpm", &img);
	load_image(data, data->info->texture[3], "textures/greystone.xpm", &img);
	load_image(data, data->info->texture[4], "textures/bluestone.xpm", &img);
	load_image(data, data->info->texture[5], "textures/mossy.xpm", &img);
	load_image(data, data->info->texture[6], "textures/wood.xpm", &img);
	load_image(data, data->info->texture[7], "textures/colorstone.xpm", &img);
}

int ft_exit(t_data *data)
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
    //data->mapper->map = square_map(data);
    //print_map(data->mapper->map, find_greatest_dimension(data->mapper->map));

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
		if (!(data->info->texture[i] = (int *)malloc(sizeof(int) * (TEXTURE_HEIGHT * TEXTURE_WIDTH))))
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
	
	data->info->win = mlx_new_window(data->info->mlx, WINDOW_W, WINDOW_H, "mlx");

	data->info->img.img = mlx_new_image(data->info->mlx, WINDOW_W, WINDOW_H);
	data->info->img.data = (int *)mlx_get_data_addr(data->info->img.img, &data->info->img.bpp, &data->info->img.size_l, &data->info->img.endian);

    mlx_hook(data->info->mlx, 33, 1L << 17, &ft_exit, data);
    mlx_hook(data->info->win, 2, 1L << 0, &key_press, data);
	mlx_loop_hook(data->info->mlx, &main_loop, data);


	mlx_loop(data->info->mlx);
}
