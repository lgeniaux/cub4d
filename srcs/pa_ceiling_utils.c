/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_ceiling_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:02:04 by hmarconn          #+#    #+#             */
/*   Updated: 2023/01/23 12:12:11 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cube.h"

int	first_ceiling(t_data	*data, char	*tmp)
{
	char	*test;

	test = ft_strdup(tmp);
	data->mapper->ceiling[RED] = ft_atoi(test);
	free(test);
	if (data->mapper->ceiling[RED] > 255 || \
		data->mapper->ceiling[RED] < 0)
	{
		free(tmp);
		return (0);
	}
	return (1);
}

int	second_ceiling(t_data	*data, char	*tmp)
{
	char	*test;

	test = ft_strdup(tmp);
	data->mapper->ceiling[GREEN] = ft_atoi(test);
	free(test);
	if (data->mapper->ceiling[GREEN] > 255 || \
		data->mapper->ceiling[GREEN] < 0)
	{
		free(tmp);
		return (0);
	}
	return (1);
}

int	third_ceiling(t_data	*data, char	*tmp)
{
	char	*test;

	test = ft_strdup(tmp);
	data->mapper->ceiling[BLUE] = ft_atoi(test);
	free(test);
	if (data->mapper->ceiling[BLUE] > 255 || \
		data->mapper->ceiling[BLUE] < 0)
	{
		free(tmp);
		return (0);
	}
	return (1);
}
