/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarconn <hmarconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:57:27 by hmarconn          #+#    #+#             */
/*   Updated: 2023/02/04 19:14:17 by hmarconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# define FD_MAX 10240

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_gnl
{
	ssize_t	file_size;
	char	buff[BUFFER_SIZE + 1];
	char	*stock;
}t_gnl;

char	*ft_strnstr(const char	*haystack, const char	*needle, size_t	len);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
size_t	ft_strlcat(char	*dest, const char	*src, size_t	destsize);
size_t	ft_strlcpy(char	*dest, const char	*src, size_t	destsize);
char	*ft_substr(char const	*s, unsigned int start, size_t	len);
char	*ft_strmapi(char const	*s, char (*f)(unsigned int, char));
int		ft_memcmp(const void	*s1, const void	*s2, size_t	n);
int		ft_strncmp(const char	*s1, const char	*s2, size_t	n);
void	ft_striteri(char	*s, void (f)(unsigned int, char*));
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memchr(const void	*s, int c, size_t	n);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
char	*ft_strtrim(char const	*s1, char const	*set);
void	ft_lstclear(t_list **lst, void (*del)(void*));
char	*ft_strjoin(char const	*s1, char const	*s2);
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	*ft_calloc(size_t	count, size_t	size);
void	*ft_memset(void	*b, int c, size_t len);
char	**ft_split(char const	*s, char c);
char	*ft_strchr(const char	*s, int c);
char	*ft_strrchr(const char	*s, int c);
void	ft_putendl_fd(char	*s, int fd);
void	ft_putstr_fd(char	*s, int fd);
void	ft_bzero(void	*d, size_t	n);
size_t	ft_strlen(const char	*str);
void	ft_putchar_fd(char c, int fd);
char	*ft_strdup(const char	*s1);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char	*str);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_itoa(int n);

char	*get_next_line(int fd);
size_t	ft_strlenbis(const char	*str);
char	*ft_strndup(char	*src, char c);
char	*ft_strjoingen(char	*s1, char *s2);
size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize);
char	*ft_strdup2(const char *s1);
char	*ft_strjoin_gnl(char const *s1, char const *s2);

int		ft_hexax_printf(unsigned int nb, char	*base);
int		ft_putstr_fd_printf(char	*s, int fd);
int		ft_putchar_fd_printf(char c, int fd);
int		ft_printf(const char	*str, ...);
int		ft_putnbr_fd_printf(int n, int fd);
int		ft_unsigned_printf(unsigned int i);
int		ft_pprint_printf(void	*va);

#endif
