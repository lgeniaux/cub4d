/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:35:04 by hmarconn          #+#    #+#             */
/*   Updated: 2021/11/29 15:49:00 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	struct s_list	*begin;

	begin = malloc(sizeof(struct s_list));
	if (!begin)
		return (NULL);
	begin->content = content;
	begin->next = NULL;
	return (begin);
}
