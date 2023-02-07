/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:09:04 by hmarconn          #+#    #+#             */
/*   Updated: 2023/01/30 18:13:15 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cube.h"

void	toparse_scroll(t_data	*data, char	*buffer)
{
	while (buffer[data->scroller] && buffer[data->scroller] != '\0' && \
		(buffer[data->scroller] < 33 || buffer[data->scroller] > 126))
		data->scroller++;
}

int	pa_getlen(t_data	*data, char	*buffer)
{
	int	len;

	len = 0;
	while (buffer[data->scroller] && (buffer[data->scroller] >= 33 && \
		buffer[data->scroller] <= 126))
	{
		len++;
		data->scroller++;
	}
	return (len);
}

void	print_type(int type)
{
	if (type == 0)
		return ;
	if (type == 1)
		printf("Error\nInvalid document\n");
	else if (type == 2)
		printf("Error\nInvalid elements\n");
	else if (type == 3)
		printf("Error\nInvalid Map\n");
	else if (type == 4)
		printf("Error\nMissing informations\n");
	else if (type == 5)
		printf("Error\nMap not found\n");
}

void	the_end(t_data	*data, int type)
{
	int	y;

	y = 0;
	print_type(type);
	if (data->map_exists == 1)
	{
		while (y < data->mapper->high_point)
		{
			if (data->mapper->map[y] != NULL)
				free(data->mapper->map[y]);
			y++;
		}
		free(data->mapper->map);
	}
	y = 0;
	while (y < 4)
	{
		free(data->mapper->walls[y]);
		y++;
	}
    if (type == 6)
    {
        printf("ici");
        y = 0;
        while (y < 8)
        {
            free(data->info->texture[y]);
            y++;
        }
        free(data->info->texture);
        free(data->info);
        free(data->raycast);

//        ft_exit(data);
    }
    printf("test\n");
    exit(18);
}
