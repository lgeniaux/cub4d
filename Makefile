#  |  |  ___ \    \  |         |
#  |  |     ) |  |\/ |   _  |  |  /   _ 
# ___ __|  __/   |   |  (   |    <    __/ 
#    _|  _____| _|  _| \__,_| _|\_\ \___|
#                              by jcluzet
################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := cub
CC        := gcc -g3
FLAGS    :=
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      libs/libft/ft_putchar_fd_printf.c \
                          libs/libft/ft_strchr.c \
                          libs/libft/ft_putstr_fd_printf.c \
                          libs/libft/ft_lstiter.c \
                          libs/libft/ft_split.c \
                          libs/libft/ft_strtrim.c \
                          libs/libft/ft_bzero.c \
                          libs/libft/ft_strnstr.c \
                          libs/libft/ft_strmapi.c \
                          libs/libft/ft_isprint.c \
                          libs/libft/ft_atoi.c \
                          libs/libft/ft_strdup.c \
                          libs/libft/ft_lstdelone.c \
                          libs/libft/ft_tolower.c \
                          libs/libft/ft_toupper.c \
                          libs/libft/ft_putnbr_fd_printf.c \
                          libs/libft/ft_substr.c \
                          libs/libft/ft_striteri.c \
                          libs/libft/ft_memchr.c \
                          libs/libft/ft_putnbr_fd.c \
                          libs/libft/ft_strlcpy.c \
                          libs/libft/ft_itoa.c \
                          libs/libft/ft_printf.c \
                          libs/libft/ft_unsigned_printf.c \
                          libs/libft/ft_lstlast.c \
                          libs/libft/ft_memset.c \
                          libs/libft/ft_calloc.c \
                          libs/libft/get_next_line.c \
                          libs/libft/ft_lstsize.c \
                          libs/libft/ft_strlen.c \
                          libs/libft/ft_putchar_fd.c \
                          libs/libft/ft_isascii.c \
                          libs/libft/ft_lstmap.c \
                          libs/libft/ft_strlcat.c \
                          libs/libft/ft_putendl_fd.c \
                          libs/libft/ft_memcmp.c \
                          libs/libft/ft_pprint_printf.c \
                          libs/libft/ft_isdigit.c \
                          libs/libft/ft_strrchr.c \
                          libs/libft/ft_hexax_printf.c \
                          libs/libft/ft_lstnew.c \
                          libs/libft/ft_putstr_fd.c \
                          libs/libft/ft_isalpha.c \
                          libs/libft/ft_lstadd_back.c \
                          libs/libft/ft_strncmp.c \
                          libs/libft/get_next_line_utils.c \
                          libs/libft/ft_isalnum.c \
                          libs/libft/ft_memcpy.c \
                          libs/libft/ft_memmove.c \
                          libs/libft/ft_strjoin.c \
                          libs/libft/ft_lstclear.c \
                          libs/libft/ft_lstadd_front.c \
                          srcs/pa_wall_parser_utils.c \
                          srcs/pa_floor_utils.c \
                          srcs/pa_ceiling_utils.c \
                          srcs/pa_genmap_utils.c \
                          srcs/pa_genmap.c \
                          srcs/parsing.c \
                          srcs/pa_colors_ceiling.c \
                          srcs/pa_wallpapers.c \
                          srcs/pa_colors_floor.c \
                          srcs/pa_utils.c \
                          srcs/exec.c \
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

UNAME		:=	$(shell uname)

ifeq ($(UNAME), Darwin)
$(NAME): ${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@ $(MAKE) -C mlx all >/dev/null 2>&1
			@ cp ./mlx/libmlx.a .
			$(CC) $(CFLAGS) -g3 -Ofast -o $(NAME) -Imlx $(OBJS) -Lmlx -lmlx -lm -framework OpenGL -framework AppKit
			@echo "$(GREEN)$(NAME) created[0m ✔️"
endif

ifeq ($(UNAME), Linux)
$(NAME): ${OBJS}
			@echo "$(GREEN)Linux compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@chmod 777 mlx_linux/configure
			@ $(MAKE) -C mlx_linux all
			$(CC) $(CFLAGS) -g3 -o $(NAME) $(OBJS) -Imlx_linux -Lmlx_linux -lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm
			@echo "$(GREEN)$(NAME) created[0m ✔️"
endif

all:		${NAME}

ifeq ($(UNAME), Darwin)
clean:
			@ ${RM} *.o */*.o */*/*.o
			@ rm -rf $(NAME).dSYM >/dev/null 2>&1
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
endif

ifeq ($(UNAME), Linux)
clean:
			@ ${RM} *.o */*.o */*/*.o
			@ rm -rf $(NAME).dSYM >/dev/null 2>&1
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
endif


ifeq ($(UNAME), Linux)
fclean:		clean
			@ ${RM} ${NAME}
			@ $(MAKE) -C mlx_linux clean 
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
endif

ifeq ($(UNAME), Darwin)
fclean:		clean
			@ ${RM} ${NAME}
			@ rm libmlx.a
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
endif

re:			fclean all

.PHONY:		all clean fclean re


