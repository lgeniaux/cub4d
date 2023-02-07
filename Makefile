#target name
NAME = Cub3D

#SILENT THE RECIPE
ifndef VERBOSE
.SILENT:
endif

#The Directories, Source, Includes, Objects, Binary and Resources
SRCDIR      := srcs
INCDIR      := includes
BUILDDIR    := obj
NAMEDIR     := ./
RESDIR      := lib
SRCEXT      := c
DEPEXT      := d
OBJEXT      := o

#Flags, Libraries and Includes
CFLAGS      := -Wall -Wextra -Werror -g3 -o3
#CFLAGS      := -Wall -Wextra -Werror -fsanitize=address -g3
# SANITIZE    := -fsanitize=address
# LLDBFLAG    := -g3
LIBFT_PATH  := ./libs/libft/libft.a
LIBX 		:= libmlx.a
LIB         := $(LIBFT_PATH) $(LIBX)
INC         := -I$(INCDIR)
INCDEP      := -I$(INCDIR)

SRCS = ./srcs/parsing.c \
	./srcs/pa_wallpapers.c \
	./srcs/pa_colors_ceiling.c \
	./srcs/pa_colors_floor.c \
	./srcs/pa_utils.c \
	./srcs/pa_genmap.c \
	./srcs/pa_ceiling_utils.c \
	./srcs/pa_floor_utils.c \
	./srcs/pa_genmap_utils.c \
	./srcs/pa_wall_parser_utils.c \
	./srcs/main.c \
	./srcs/wp_utils.c \
	./srcs/parsing_complementaries.c \
	./srcs/pa_color_utils.c \
	./srcs/exec.c \
	./srcs/orientation_handler.c \
	./srcs/movement_handler.c \
	./srcs/exec_utils.c \
	./srcs/exec_utils_2.c \
	
MAKE = make

OBJS = ${SRCS:.c=.o}

CC = gcc

RM = rm -f

HEADER = ./incs/cube.h

all: leslib ${NAME}

git:
	@git add .
	@printf "Message of the commit: " && read msg && git commit -m "$$msg"
	@git push

#$(NAME): ${OBJS} $(HEADER) Makefile
#			@chmod 777 mlx_linux/configure
#			@ $(MAKE) -C mlx_linux all
#			$(CC) $(CFLAGS) $(LIBFT_PATH) -o $(NAME) $(OBJS) -Imlx_linux -Lmlx_linux -lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm
#			/bin/echo -e "\x1b[35m\x1b[34m**********\t\tDONE\t\t**********"

#$(NAME): $(OBJS) $(HEADER) Makefile
#		$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PATH) -o $(NAME)
#		/bin/echo -e "\x1b[35m\x1b[34m**********\t\tDONE\t\t**********"

$(NAME): $(OBJS) $(HEADER) Makefile
		$(CC) $(CFLAGS) $(OBJS) $(LIBX) $(LIBFT_PATH) -o $(NAME) -Ilibs/mlx_linux -Llibs/mlx_linux -lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm
		@echo "\x1b[35m\x1b[34m**********\t\tDONE\t\t**********"

%.o: %.c ${HEADER} Makefile
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

leslib:
		$(MAKE) -C libs/mlx_linux/
		cp libs/mlx_linux/libmlx.a ./
		${MAKE} -C libs/libft/

clean:
		${MAKE} clean -C libs/libft/
		${MAKE} clean -C libs/mlx_linux/
		${RM} ${OBJS}
		@echo "\x1b[35m\x1b[36m**********\t\tCLEANED\t\t**********"

fclean: clean
		${RM} ${NAME}
		${RM} ${LIBX}
		${RM} ${LIBFT}

re: fclean all

.PHONY: all clean fclean re leslib