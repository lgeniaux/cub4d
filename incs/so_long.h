/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:26:30 by hmarconn          #+#    #+#             */
/*   Updated: 2022/04/11 14:39:22 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx/mlx.h"
# include "libft/libft.h"

# define IMG_SIZE 63

typedef struct s_map
{
	char	**map;
	int		height;
	int		length;
	char	exit;
	int		exitnb;
	char	guy;
	int		yguy;
	int		xguy;
	char	collectible;
	int		collected;
	int		to_collect;
	int		moves;
}t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*img_water;
	void	*img_grass;
	void	*img_guy;
	void	*img_collectible;
	void	*img_exit;
	int		img_height;
	int		img_width;
}t_mlx;

typedef struct s_data
{
	t_map	*mapper;
	t_mlx	*mlx;
	int		fd;
	int		len;
	int		i;
	int		j;
	char	*buff;
	char	*doc;
}t_data;

/* BASICS */
int	main(int argc, char	**argv);
int	parsing(t_data *data);
int	gen_tab(t_data *data);
int	exit_game(t_data	*data);
int	exit_abnormal(t_data	*data);

/*GRAPHICS*/
int	push_to_window(t_data *data);
int	push_wall(t_data *data);
int	push_grass(t_data *data);
int	push_guy(t_data *data);
int	push_collectible(t_data *data);
int	push_exit(t_data *data);

/* HOOKS */
int	key_hook(int keycode, t_data	*data);

#endif