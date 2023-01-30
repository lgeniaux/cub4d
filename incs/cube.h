/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:26:35 by hmarconn          #+#    #+#             */
/*   Updated: 2023/01/30 18:13:33 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libs/mlx/mlx.h"
# include "../libs/libft/libft.h"

# define NORTH	0
# define SOUTH	1
# define EAST	2
# define WEST	3

# define RED 0
# define GREEN 1
# define BLUE 2

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
	int		high_point;
}	t_map;

// typedef struct s_glib
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	void	*img_water;
// 	void	*img_grass;
// 	void	*img_guy;
// 	void	*img_collectible;
// 	void	*img_exit;
// 	int		img_height;
// 	int		img_width;
// }t_glib;

typedef struct s_data
{
	// t_glib	*glib;
	int		map_exists;
	int		fd;
	int		y;
	char	*doc;
	int		fd_section;
	int		scroller;
	int		i;
	t_map	*mapper;
	char	*buff;
}	t_data;

/*PARSING*/
void	init_phase(t_data	*data);
int		fd_check(char	*doc);
int		ft_strlen_parsing(char	*str);
int		pa_getlen(t_data	*data, char	*buffer);
int		to_parse(t_data	*data, char	*buffer);
int		pa_wallpapers(t_data	*data, char	*buffer);
int		the_wall_parser(t_data	*data);
int		wall_parser_first(t_data	*data, int len, int x, int y);
int		pa_walls(t_data	*data, char	*buffer, int wall);
int		pa_colors(t_data	*data, char	*buffer);
int		pa_floors(t_data	*data, char	*buffer);
int		pa_firstfloor(t_data *data, char	*tmp);
int		pa_secondfloor(t_data *data, char	*tmp);
int		pa_thirdfloor(t_data *data, char	*tmp);
int		pa_ceiling(t_data	*data, char	*buffer);
int		first_ceiling(t_data *data, char	*tmp);
int		second_ceiling(t_data *data, char	*tmp);
int		third_ceiling(t_data *data, char	*tmp);
int		the_map_parser(t_data	*data);
int		the_map_filler(t_data	*data, char	*buffer);
void	the_end(t_data	*data, int type);
void	toparse_scroll(t_data	*data, char	*buffer);

#endif