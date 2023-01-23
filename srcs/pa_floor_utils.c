/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_floor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:50:54 by hmarconn          #+#    #+#             */
/*   Updated: 2023/01/23 16:27:59 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cube.h"

int	pa_firstfloor(t_data	*data, char	*tmp)
{
	char	*test;

	test = ft_strdup(tmp);
	data->mapper->floor[RED] = ft_atoi(test);
	free(test);
	if (data->mapper->floor[RED] > 255 || data->mapper->floor[RED] < 0)
	{
		free(tmp);
		return (0);
	}
	return (1);
}

int	pa_secondfloor(t_data	*data, char	*tmp)
{
	char	*test;

	test = ft_strdup(tmp);
	data->mapper->floor[GREEN] = ft_atoi(test);
	free(test);
	if (data->mapper->floor[GREEN] > 255 || \
		data->mapper->floor[GREEN] < 0)
	{
		free(tmp);
		return (0);
	}
	return (1);
}

int	pa_thirdfloor(t_data	*data, char	*tmp)
{
	char	*test;

	test = ft_strdup(tmp);
	data->mapper->floor[BLUE] = ft_atoi(test);
	free(test);
	if (data->mapper->floor[BLUE] > 255 || \
		data->mapper->floor[BLUE] < 0)
	{
		free(tmp);
		return (0);
	}
	return (1);
}
