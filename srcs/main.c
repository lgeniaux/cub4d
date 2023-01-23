// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.c                                    :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/01/23 17:24:23 by hmarconn          #+#    #+#             */
// /*   Updated: 2023/01/23 17:24:33 by hmarconn         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../incs/cube.h"

// // static int	main_gnl_fd(t_data	*data, int fd)
// // {
// // 	char	*buff;

// // 	if (fd <= 0)
// // 	{
// // 		printf("Error\nInvalid document\n");
// // 		the_end(data);
// // 		exit (42);
// // 	}
// // 	buff = get_next_line(fd);
// // 	while (buff && data->fd_section == 0)
// // 	{	
// // 		if (!to_parse(data, buff))
// // 		{
// // 			printf("Error\nInvalid elements\n");
// // 			the_end(data);
// // 			return (0);
// // 		}
// // 		printf("ici\n");
// // 		free(buff);
// // 		buff = get_next_line(fd);
// // 	}
// // 	free(buff);
// // 	close(fd);
// // 	return (1);
// // }

// int	main(int argc, char	**argv)
// {
// 	t_data	data;
// 	t_map	mapper;
// 	int		fd;
// 	char	*buff;

// 	data.mapper = &mapper;
// 	if (argc != 2)
// 		return (0);
// 	init_phase(&data);
// 	fd_check(argv[1]);
// 	data.doc = argv[1];
// 	fd = open(argv[1], O_RDONLY);
// 	// if (!main_gnl_fd(&data, fd))
// 	// 	return (0);
// 	printf("test\n");
// 	if (fd <= 0)
// 	{
// 		printf("Error\nInvalid document\n");
// 		the_end(&data);
// 		exit (42);
// 	}
// 	buff = get_next_line(fd);
// 	while (buff && data.fd_section == 0)
// 	{	
// 		if (!to_parse(&data, buff))
// 		{
// 			printf("Error\nInvalid elements\n");
// 			the_end(&data);
// 			return (0);
// 		}
// 		free(buff);
// 		buff = get_next_line(fd);
// 		printf("ici\n");
// 	}
// 	free(buff);
// 	close(fd);
// 	data.map_exists = 1;
// 	if (!the_map_parser(&data))
// 	{
// 		printf("Error\nInvalid Map\n");
// 		the_end(&data);
// 		exit (42);
// 	}
// 	if (data.mapper->floors == 0 || data.mapper->ceilings == 0 || \
// 		data.mapper->north_wall == 0 || data.mapper->south_wall == 0 || \
// 			data.mapper->east_wall == 0 || data.mapper->west_wall == 0 || \
// 				data.mapper->player == 0)
// 	{
// 		printf("Error\nMissing informations\n");
// 		the_end(&data);
// 		return (0);
// 	}
// 	printf("bravo\n");
// 	the_end(&data);
// 	return (0);
// }
