/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_color_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:30:39 by hmarconn          #+#    #+#             */
/*   Updated: 2023/02/04 16:52:16 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cube.h"

int	pa_floorcolorcheck(t_data	*data, char	*tmp, int i)
{
	if (i == 0)
	{
		if (!pa_firstfloor(data, tmp))
			return (0);
	}
	else if (i == 1)
	{
		if (!pa_secondfloor(data, tmp))
			return (0);
	}
	else
	{
		if (!pa_thirdfloor(data, tmp))
			return (0);
	}
	free(tmp);
	tmp = NULL;
	return (1);
}

int	pa_ceilingcolorcheck(t_data	*data, char	*tmp, int i)
{
	if (i == 0)
	{
		if (!first_ceiling(data, tmp))
			return (0);
	}
	else if (i == 1)
	{
		if (!second_ceiling(data, tmp))
			return (0);
	}
	else
	{
		if (!third_ceiling(data, tmp))
			return (0);
	}
	free(tmp);
	tmp = NULL;
	return (1);
}
