/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:17:21 by hmarconn          #+#    #+#             */
/*   Updated: 2021/11/30 12:37:33 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	struct s_list	*last;

	if (!alst)
		return ;
	if ((*alst) == NULL)
	{
		(*alst) = new;
	}
	else
	{
		last = ft_lstlast(*alst);
		last->next = new;
	}
}
