/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:26:35 by hmarconn          #+#    #+#             */
/*   Updated: 2023/01/23 17:43:06 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "../mlx_linux/mlx.h"
# include "../libs/libft/libft.h"

# define mapWidth 24
# define mapHeight 24
# define K_A 97
# define K_D 100
# define K_S 115
# define K_W 119
# define K_ESC 65307

# define NORTH	1
# define SOUTH	2
# define EAST	3
# define WEST	4

# define RED 0
# define GREEN 1
# define BLUE 2

# define WINDOW_W 700
# define WINDOW_H 480

#define TEXTURE_WIDTH 64
#define TEXTURE_HEIGHT 64

typedef struct	s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct	s_map
{
	char	**map;
	char	*walls[4];
	int		floor[3];
	int		ceiling[3];
	int		floors;
	int		ceilings;
	int		north_wall;
	int		south_wall;
	int		east_wall;
	int		west_wall;
	int		height;
	int		player;
	int		xplayer;
	int		yplayer;
	int 	map2;
	int		high_point;
}	t_map;

typedef struct	s_info
{
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	void	*mlx;
	void	*win;
	t_img	img;
	int		buf[WINDOW_H][WINDOW_W];
	int		**texture;
	double	moveSpeed;
	double	rotSpeed;
	int		re_buf;


}				t_info;

typedef struct s_data
{
	int		map_exists;
	int		fd;
	int		y;
	char	*doc;
	int		fd_section;
	int		scroller;
	int		i;
	t_map	*mapper;
	char	*buff;
	t_info	*info;
	
}	t_data;

/*PARSING*/
int		pa_wallpapers(t_data	*data, char	*buffer);
int		pa_colors(t_data	*data, char	*buffer);
int		pa_ceiling(t_data	*data, char	*buffer);
int		pa_floors(t_data	*data, char	*buffer);
int		pa_getlen(t_data	*data, char	*buffer);
int		pa_walls(t_data	*data, char	*buffer, int wall);
int		the_wall_parser(t_data	*data);
int		the_map_parser(t_data	*data);
void	the_end(t_data	*data);
int		first_ceiling(t_data *data, char	*tmp);
int		second_ceiling(t_data *data, char	*tmp);
int		third_ceiling(t_data *data, char	*tmp);
int		pa_firstfloor(t_data *data, char	*tmp);
int		pa_secondfloor(t_data *data, char	*tmp);
int		pa_thirdfloor(t_data *data, char	*tmp);
int		the_map_filler(t_data	*data, char	*buffer);
int		ft_strlen_parsing(char	*str);
int		to_parse(t_data	*data, char	*buffer);
int		fd_check(char	*doc);
void	init_phase(t_data	*data);
int		exec_start(t_data *data);

#endif