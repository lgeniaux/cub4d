# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmarconn <hmarconn@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 16:33:21 by hmarconn          #+#    #+#              #
#    Updated: 2022/11/17 14:59:11 by hmarconn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isalpha.c \
	 ft_isdigit.c \
	 ft_isalnum.c \
	 ft_isascii.c \
	 ft_isprint.c \
	 ft_strlen.c \
	 ft_memset.c \
	 ft_bzero.c \
	 ft_memcpy.c \
	 ft_strlcpy.c \
	 ft_strlcat.c \
	 ft_toupper.c \
	 ft_tolower.c \
	 ft_strchr.c \
	 ft_strrchr.c \
	 ft_strncmp.c \
	 ft_memchr.c \
	 ft_memcmp.c \
	 ft_strnstr.c \
	 ft_atoi.c \
	 ft_calloc.c \
	 ft_memmove.c \
	 ft_strdup.c \
	 ft_split.c \
	 ft_itoa.c \
	 ft_strmapi.c \
	 ft_putchar_fd.c \
	 ft_putstr_fd.c \
	 ft_putendl_fd.c \
	 ft_putnbr_fd.c \
	 ft_striteri.c \
	 ft_substr.c \
	 ft_strtrim.c \
	 ft_strjoin.c \
	 get_next_line.c \
	 get_next_line_utils.c \
	 ft_printf.c \
	 ft_putchar_fd_printf.c \
	 ft_putstr_fd_printf.c \
	 ft_putnbr_fd_printf.c \
	 ft_unsigned_printf.c \
	 ft_hexax_printf.c \
	 ft_pprint_printf.c \
	 ft_lstnew.c \
	 ft_lstadd_front.c \
	 ft_lstsize.c \
	 ft_lstlast.c \
	 ft_lstdelone.c \
	 ft_lstiter.c \
	 ft_lstclear.c \
	 ft_lstadd_back.c \
	 ft_lstmap.c \

OBJS = ${SRCS:.c=.o}

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o: libft.h
	${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

$(NAME): ${OBJS} Makefile
	ar rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM}  ${OBJS}

fclean: clean
	${RM} ${NAME} 

re: fclean all

.PHONY: all clean fclean re bonus
