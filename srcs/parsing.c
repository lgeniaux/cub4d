/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:26:03 by hmarconn          #+#    #+#             */
/*   Updated: 2023/01/23 18:25:35 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cube.h"

#include "../incs/cube.h"

int	pa_colors(t_data	*data, char	*buffer)
{
	if (buffer[data->scroller] == 'F')
	{
		data->scroller++;
		if (!pa_floors(data, buffer))
			return (0);
	}
	else if (buffer[data->scroller] == 'C')
	{
		data->scroller++;
		if (!pa_ceiling(data, buffer))
			return (0);
	}
	return (1);
}

int	fd_check(char	*doc)
{
	int	len;

	if (!doc)
		exit(0);
	len = ft_strlen(doc);
	if (doc[len - 1] != 'b' || doc[len - 2] != 'u' || doc[len - 3] != 'c' || \
		doc[len - 4] != '.')
	{
		ft_printf("ERROR\nTHE MAP IS NOT .CUB\n");
		return (0);
	}
	return (1);
}

void	init_phase(t_data	*data)
{
	data->mapper->ceilings = 0;
	data->mapper->floors = 0;
	data->mapper->north_wall = 0;
	data->mapper->south_wall = 0;
	data->mapper->east_wall = 0;
	data->mapper->west_wall = 0;
	data->fd_section = 0;
	data->i = 0;
	data->y = 0;
	data->mapper->player = 0;
	data->mapper->high_point = 0;
	data->map_exists = 0;
}

int	to_parse(t_data	*data, char	*buffer)
{
	data->scroller = 0;
	data->i++;
	while (buffer[data->scroller] != '\0')
	{
		if (data->fd_section == 0)
		{
			while (buffer[data->scroller] && buffer[data->scroller] != '\0' && \
				(buffer[data->scroller] < 33 || buffer[data->scroller] > 126))
				data->scroller++;
			while (buffer[data->scroller] && (buffer[data->scroller] >= 33 && \
				buffer[data->scroller] <= 126) && data->fd_section == 0)
			{
				if (buffer[data->scroller] == 'N' || buffer[data->scroller] \
					== 'S' \
					|| buffer[data->scroller] == 'E' || \
						buffer[data->scroller] == 'W')
				{
					if (!pa_wallpapers(data, buffer))
						return (0);
				}
				else if (buffer[data->scroller] == 'F' || \
					buffer[data->scroller] == 'C')
				{
					if (!pa_colors(data, buffer))
						return (0);
				}
				else if (buffer[data->scroller] >= '0' && \
					buffer[data->scroller] <= '9')
				{
					data->fd_section = 1;
					return (1);
				}
				else if (buffer[data->scroller] >= 33 && \
					buffer[data->scroller] <= 126)
					return (0);
			}
		}
	}
	return (1);
}

void	the_tester(t_data	*data)
{
	int	y;

	y = 0;
	printf("F :%d %d %d\nC :%d %d %d\n", data->mapper->floor[0], \
		data->mapper->floor[1], data->mapper->floor[2], \
			data->mapper->ceiling[0], data->mapper->ceiling[1], \
				data->mapper->ceiling[2]);
	printf("%d\n", data->mapper->height);
	while (y < data->mapper->high_point)
	{
		printf("%s\n", data->mapper->map[y]);
		y++;
	}
}

int	main(int argc, char	**argv)
{
	t_data	data;
	t_map	mapper;
	int		fd;
	char	*buff;

	data.mapper = &mapper;
	if (argc != 2)
		return (0);
	init_phase(&data);
	fd_check(argv[1]);
	data.doc = argv[1];
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
	{
		printf("Error\nInvalid document\n");
		the_end(&data);
		exit (42);
	}
	buff = get_next_line(fd);
	while (buff && data.fd_section == 0)
	{	
		if (!to_parse(&data, buff))
		{
			printf("Error\nInvalid elements\n");
			the_end(&data);
			return (0);
		}
		free(buff);
		buff = get_next_line(fd);
	}
	free(buff);
	close(fd);
	data.map_exists = 1;
	if (!the_map_parser(&data))
	{
		printf("Error\nInvalid Map\n");
		the_end(&data);
		exit (42);
	}
	if (data.mapper->floors == 0 || data.mapper->ceilings == 0 || \
		data.mapper->north_wall == 0 || data.mapper->south_wall == 0 || \
			data.mapper->east_wall == 0 || data.mapper->west_wall == 0 || \
				data.mapper->player == 0)
	{
		printf("Error\nMissing informations\n");
		the_end(&data);
		return (0);
	}
	printf("bravo\n");
	the_end(&data);
	return (0);
}
