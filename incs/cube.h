/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeniaux <lgeniaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:26:35 by hmarconn          #+#    #+#             */
/*   Updated: 2023/02/08 16:26:36 by lgeniaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../libs/mlx_linux/mlx.h"
# include "../libs/libft/libft.h"
# include <ctype.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define NORTH 1
# define SOUTH 2
# define EAST 3
# define WEST 4

# define RED 0
# define GREEN 1
# define BLUE 2

# define K_A 97
# define K_D 100
# define K_S 115
# define K_W 119
# define K_ESC 65307
# define K_LEFT 65361
# define K_RIGHT 65363
# define K_UP 65362
# define K_DOWN 65364

# define WINDOW_W 1920
# define WINDOW_H 1080

# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64

typedef struct s_raycast
{
	int			x;
	int			i;
	int			j;
	int			y;
	int			texture_num;
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		wall_x;
	int			texture_x;
	double		step;
	double		texture_pos;
	int			texture_y;
	int			color;

}				t_raycast;

typedef struct s_map
{
	char		**map;
	char		**walls;
	int			floor[3];
	int			ceiling[3];
	int			floors;
	int			ceilings;
	int			north_wall;
	int			south_wall;
	int			east_wall;
	int			west_wall;
	int			height;
	int			player;
	int			xplayer;
	int			yplayer;
	int			high_point;
}				t_map;

typedef struct s_img
{
	void		*img;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
	int			img_width;
	int			img_height;
}				t_img;

typedef struct s_info
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	void		*mlx;
	void		*win;
	t_img		img;
	int			buf[WINDOW_H][WINDOW_W];
	int			**texture;
	double		move_speed;
	double		rot_speed;
	int			re_buf;

}				t_info;

typedef struct s_data
{
	int			map_exists;
	int			fd;
	int			y;
	char		*doc;
	int			fd_section;
	int			scroller;
	int			i;
	int			index;
	t_map		*mapper;
	char		*buff;
	char		*buffer;
	t_info		*info;
	t_raycast	*raycast;
}				t_data;

/*PARSING*/
void			init_phase(t_data *data);
int				fd_check(char *doc);
int				ft_strlen_parsing(char *str);
int				pa_getlen(t_data *data);
int				to_parse(t_data *data);
int				pa_wallpapers(t_data *data);
int				the_wall_parser(t_data *data);
int				wall_parser_first(t_data *data, int len, int x, int y);
int				pa_walls(t_data *data, int wall);
int				pa_colors(t_data *data);
int				pa_floors(t_data *data);
int				pa_firstfloor(t_data *data, char *tmp);
int				pa_secondfloor(t_data *data, char *tmp);
int				pa_thirdfloor(t_data *data, char *tmp);
int				pa_ceiling(t_data *data);
int				first_ceiling(t_data *data, char *tmp);
int				second_ceiling(t_data *data, char *tmp);
int				third_ceiling(t_data *data, char *tmp);
int				the_map_parser(t_data *data);
int				the_map_filler(t_data *data);
void			the_end(t_data *data, int type);
void			toparse_scroll(t_data *data);
int				pa_floorcolorcheck(t_data *data, char *tmp, int i);
int				pa_ceilingcolorcheck(t_data *data, char *tmp, int i);
int				pa_ceiling_steptwo(t_data	*data, int i);

/* EXECUTION */
int				exec_start(t_data *data);
int				ft_exit(t_data *data);
void			load_texture(t_data *data);
void			load_image(t_data *data, int *texture, char *path, t_img *img);
int				key_press(int key, t_data *data);
void			rotate_left(t_data *data);
void			rotate_right(t_data *data);
void			move_backward(t_data *data);
void			move_forward(t_data *data);
int				main_loop(t_data *data);
void			calc(t_data *data);
void			draw(t_data *data);
int				convert_rgb_int(int *rgb);
void			player_direction(t_data *data);
void			draw(t_data *data);
int				convert_rgb_int(int *rgb);
void			move_forward(t_data *data);
void			move_backward(t_data *data);
void			rotate_left(t_data *data);
void			rotate_right(t_data *data);
int				key_press(int key, t_data *data);
void			load_image(t_data *data, int *texture, char *path, t_img *img);
void			load_texture(t_data *data);
int				ft_exit(t_data *data);
void			buffer_clear(t_data *data, t_raycast *ray);
void			texturing_calc(t_data *data, t_raycast *ray);
void			init_ray(t_data *data, t_raycast *ray);
void			wall_hit(t_data *data, t_raycast *ray);
int				fill_buffer(t_data *data);
int				test_utils(t_data *data, int *points, char *tmp);
int				pa_floors_length(t_data	*data);
void			move_forward(t_data *data);
void			move_backward(t_data *data);
void			move_left(t_data *data);
void			move_right(t_data *data);

#endif