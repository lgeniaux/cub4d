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

//size_t	ft_strlen(const char *s)
//{
//    size_t	i;
//
//    i = 0;
//    while (s[i] != '\0')
//        i++;
//    return (i);
//}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t	i;

    i = 0;
    if (dstsize > 0)
    {
        while (src[i] != '\0' && i < dstsize - 1)
        {
            dst[i] = src[i];
            i++;
        }
    }
    else
        return (ft_strlen(src));
    dst[i] = '\0';
    return (ft_strlen(src));
}

char	*ft_strdup2(const char *s1)
{
    char		*str;
    size_t		len;
    size_t		i;

    i = 0;
    len = ft_strlen(s1);
    str = (char *)malloc(sizeof(char) * (len + 1));
    if (!str)
        return (NULL);
    while (i < len)
    {
        str[i] = s1[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
    char	*str;
    char	*tmp;

    str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!str)
        return (NULL);
    tmp = str;
    while (*s1 != '\0')
        *str++ = *s1++;
    while (*s2 != '\0')
        *str++ = *s2++;
    *str = '\0';
    return (tmp);
}

static size_t	pos_return(char *buf)
{
    size_t	pos;

    pos = 0;
    while (buf[pos] != '\n' && buf[pos] != '\0')
        pos++;
    if (buf[pos] == '\n')
        pos++;
    return (pos);
}

static ssize_t	read_buf(int fd, char *buf)
{
    ssize_t	rd_bytes;

    rd_bytes = read(fd, buf, BUFFER_SIZE);
    if (rd_bytes > 0)
        buf[rd_bytes] = 0;
    else
        buf[0] = 0;
    return (rd_bytes);
}

static int	check_error(int *endline, int rd_bytes)
{
    if (rd_bytes == 0)
        return (0);
    else if (rd_bytes < 0)
    {
        *endline = -1;
        return (0);
    }
    return (1);
}

static char	*get_line(char *buf, int fd, int *endline)
{
    ssize_t	rd_bytes;
    size_t	pos_r;
    char	*line;
    char	*tmp;

    if (ft_strlen(buf) == 0)
    {
        rd_bytes = read_buf(fd, buf);
        if (check_error(endline, rd_bytes) == 0)
            return (NULL);
    }
    pos_r = pos_return(buf);
    if (buf[pos_r - 1] == '\n')
        *endline = 1;
    line = malloc(pos_r + 1);
    if (!line)
        return (NULL);
    ft_strlcpy(line, buf, pos_r + 1);
    tmp = ft_strdup2((buf) + pos_r);
    if (!tmp)
        return (NULL);
    ft_strlcpy(buf, tmp, ft_strlen(tmp) + 1);
    free(tmp);
    return (line);
}

char	*get_next_line(int fd)
{
    static char	buf[BUFFER_SIZE + 1];
    int			endline;
    char		*old;
    char		*line;
    char		*new_line;

    if (fd < 0 || BUFFER_SIZE <= 0 || fd > FD_MAX)
        return (NULL);
    endline = 0;
    line = get_line(buf, fd, &endline);
    if (!line)
        return (NULL);
    while (endline == 0)
    {
        new_line = get_line(buf, fd, &endline);
        if (!new_line && endline != -1)
            return (line);
        if (endline == -1)
            return (free(line), NULL);
        old = line;
        line = ft_strjoin(line, new_line);
        free(new_line);
        free(old);
    }
    return (line);
}

//int	main(void)
//{
//    int		i = 1;
//    int		fd = open("test.txt", O_RDONLY);
//    char 	*str = get_next_line(fd);
//    while (str)
//    {
//        printf("/!\\--> line [%d] > $%s$\n",i++, str);
//        free(str);
//        str = get_next_line(fd);
//    }
//    str = get_next_line(fd);
//    printf("/SHOULD BE NULL\\--> line [%d] > $%s$\n",i, str);
//    free(str);
//}

//static char	*cut_line(char	**tab)
//{
//	char	*line;
//	char	*surplus;
//
//	line = ft_strndup(*tab, '\n');
//	surplus = ft_strndup(ft_strchr(*tab, '\n') + 1, '\0');
//	free (*tab);
//	*tab = surplus;
//	return (line);
//}
//
////char *get_next_line(int fd) {
////    (void)BUFFER_SIZE;
////    char *s = malloc(10000), *c = s;
////    while(read(fd, c, 1) > 0 && *c++ != 'n');
////    if (c > s) {
////        (*c = 0);
////        return s;
////    }
////    free(s);
////    return 0;
////}
//char	*get_next_line(int fd)
//{
//	static t_gnl	gnl;
//	char			*tierce;
//
//	tierce = NULL;
//	if (read(fd, gnl.buff, 0) < 0)
//		return (NULL);
//	if (gnl.file_size == 0 && gnl.stock == NULL)
//		gnl.file_size = 1;
//	while (!ft_strchr(gnl.stock, '\n') && gnl.file_size > 0)
//	{
//		gnl.file_size = read(fd, gnl.buff, BUFFER_SIZE);
//		if (gnl.file_size < 0)
//			return (NULL);
//		if (gnl.file_size == 0)
//			break ;
//		gnl.buff[gnl.file_size] = '\0';
//		gnl.stock = ft_strjoingen(gnl.stock, gnl.buff);
//		if (gnl.stock == NULL)
//			return (NULL);
//	}
//	if (ft_strchr(gnl.stock, '\n'))
//		return (cut_line(&gnl.stock));
//	if (gnl.stock && gnl.stock[0])
//		tierce = ft_strndup(gnl.stock, '\0');
//	free(gnl.stock);
//	gnl.stock = NULL;
//	return (tierce);
//}
