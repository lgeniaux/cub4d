/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:24:23 by hmarconn          #+#    #+#             */
/*   Updated: 2023/01/23 17:24:33 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cube.h"

int	fd_check(char *doc)
{
	int	len;

	if (!doc)
		return (0);
	len = ft_strlen(doc);
	if (doc[len - 1] != 'b' || doc[len - 2] != 'u' || doc[len - 3] != 'c'
		|| doc[len - 4] != '.')
	{
		ft_printf("ERROR\nTHE MAP IS NOT .CUB\n");
		return (0);
	}
	return (1);
}

int	read_fd(t_data *data, int fd)
{
	int i;

	i = 0;
	data->buffer = get_next_line(fd);
	while (data->buffer && data->fd_section == 0)
	{
		if (!to_parse(data))
		{
			the_end(data, 2);
			return (0);
		}
		i++;
		free(data->buffer);
		data->buffer = get_next_line(fd);
	}
	free(data->buffer);
	data->buffer = NULL;
	close(fd);
	data->y = 0;
	return (1);
}

int	secondhand_main(t_data *data, char *doc)
{
	int	fd;

	data->buffer = NULL;
	if (!fd_check(doc))
		return (0);
	data->doc = doc;
	fd = open(doc, O_RDONLY);
	if (fd <= 0)
	{
		the_end(data, 1);
		exit(42);
	}
	if (!read_fd(data, fd))
		return (0);
	if (data->fd_section == 0)
	{
		the_end(data, 5);
		return (0);
	}
	return (1);
}

static int	elements_verification(t_data *data)
{
	if (data->mapper->floors == 0 || data->mapper->ceilings == 0
		|| data->mapper->north_wall == 0 || data->mapper->south_wall == 0
		|| data->mapper->east_wall == 0 || data->mapper->west_wall == 0
		|| data->mapper->player == 0)
	{
		the_end(data, 4);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	mapper;

	data.mapper = &mapper;
	if (argc != 2)
		return (0);
	data.index = 0;
	init_phase(&data);
	if (!secondhand_main(&data, argv[1]))
		the_end(&data, 0);
	if (!the_map_parser(&data))
	{
		printf("test\n");
		the_end(&data, 3);
		exit(42);
	}
	if (!elements_verification(&data))
		the_end(&data, 0);
	exec_start(&data);
	the_end(&data, 6);
	return (0);
}
