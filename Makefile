#Compiler and Linker
# DEBUG=1

# ifeq ($(DEBUG), 0) # for final compilation
# CC = gcc $(CFLAGS)
# MAKELIB = @make DEBUG=0 -C./libs/libft/
# endif
# ifeq ($(DEBUG), 1)  # for sanitize test
# CC = gcc $(SANITIZE) $(LLDBFLAG)
# MAKELIB = @make DEBUG=1 -C./libs/libft/
# endif
# ifeq ($(DEBUG), 2) # for LEAKS test
# CC = gcc $(LLDBFLAG)
# MAKELIB = @make DEBUG=2 -C./libs/libft/
# endif

#target name
NAME = cub3D

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
CFLAGS      := -Wall -Wextra -Werror
#CFLAGS      := -Wall -Wextra -Werror -fsanitize=address -g3
# SANITIZE    := -fsanitize=address
# LLDBFLAG    := -g3
LIBFT_PATH  := ./libs/libft/libft.a
LIBX 		:= libmlx.dylib
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
	./srcs/parsing_complementaries.c

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

$(NAME): $(OBJS) $(HEADER) Makefile
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PATH) -o $(NAME)
		@echo "\x1b[35m\x1b[34m**********\t\tDONE\t\t**********"

# $(NAME): $(OBJS) $(HEADER) Makefile
# 		$(CC) $(CFLAGS) $(LIBX) $(LIBFT_PATH) $(OBJS) -o $(NAME)
# 		@echo "\x1b[35m\x1b[34m**********\t\tDONE\t\t**********"

%.o: %.c ${HEADER} Makefile
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o} 

leslib:
		${MAKE} -C libs/libft/

# leslib:
# 		$(MAKE) -C libs/mlx/ 
# 		cp libs/mlx/libmlx.dylib ./
# 		${MAKE} -C libs/libft/

clean:
		${MAKE} clean -C libs/libft/
		${RM} ${OBJS}
		@echo "\x1b[35m\x1b[36m**********\t\tCLEANED\t\t**********"

# clean:
# 		${MAKE} clean -C libs/libft/
# 		${MAKE} clean -C libs/mlx/	
# 		${RM} ${OBJS}
# 		@echo "\x1b[35m\x1b[36m**********\t\tCLEANED\t\t**********"

fclean: clean
		${RM} ${NAME}
		${RM} ${LIBFT}

# fclean: clean
# 		${RM} ${NAME}
# 		${RM} ${LIBX}
# 		${RM} ${LIBFT}

re: fclean all

.PHONY: all clean fclean re leslib