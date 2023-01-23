/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:58:40 by hmarconn          #+#    #+#             */
/*   Updated: 2021/12/01 11:33:25 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	struct s_list	*lstnew;
	struct s_list	*temp;

	if (!f)
		return (NULL);
	while (lst->next != NULL)
	{
		temp = lst->next;
		lstnew = malloc(sizeof(*lst));
		if (!lstnew)
		{
			ft_lstclear(&lstnew, *del);
			return (NULL);
		}
		lstnew = f(lst->content);
		lstnew = lstnew->next;
		lst = temp;
	}
	return (lstnew);
}
