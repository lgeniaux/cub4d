/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:07:07 by hmarconn          #+#    #+#             */
/*   Updated: 2023/02/04 19:13:41 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*cut_line(char	**tab)
{
	char	*line;
	char	*surplus;

	line = ft_strndup(*tab, '\n');
	surplus = ft_strndup(ft_strchr(*tab, '\n') + 1, '\0');
	free (*tab);
	*tab = surplus;
	return (line);
}

char *get_next_line(int fd) {
    (void)BUFFER_SIZE;
    char *s = malloc(10000), *c = s;
    while(read(fd, c, 1) > 0 && *c++ != 'n');
    if (c > s) {
        (*c = 0);
        return s;
    }
    free(s);
    return 0;
}
char	*get_next_line2(int fd)
{
	static t_gnl	gnl;
	char			*tierce;

	tierce = NULL;
	if (read(fd, gnl.buff, 0) < 0)
		return (NULL);
	if (gnl.file_size == 0 && gnl.stock == NULL)
		gnl.file_size = 1;
	while (!ft_strchr(gnl.stock, '\n') && gnl.file_size > 0)
	{
		gnl.file_size = read(fd, gnl.buff, BUFFER_SIZE);
		if (gnl.file_size < 0)
			return (NULL);
		if (gnl.file_size == 0)
			break ;
		gnl.buff[gnl.file_size] = '\0';
		gnl.stock = ft_strjoingen(gnl.stock, gnl.buff);
		if (gnl.stock == NULL)
			return (NULL);
	}
	if (ft_strchr(gnl.stock, '\n'))
		return (cut_line(&gnl.stock));
	if (gnl.stock && gnl.stock[0])
		tierce = ft_strndup(gnl.stock, '\0');
	free(gnl.stock);
	gnl.stock = NULL;
	return (tierce);
}
