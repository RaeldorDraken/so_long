# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 10:39:30 by eros-gir          #+#    #+#              #
#    Updated: 2022/05/14 15:56:57 by eros-gir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = ./src/main.c ./src/utilities.c ./src/inputs.c ./src/check_map.c \
./src/get_next_line.c ./src/check_errors.c
SRC2 = ./src/main.o ./src/utilities.o ./src/inputs.o ./src/check_map.o \
./src/get_next_line.o ./src/check_errors.o
SRCB = ./src/main.c ./src/utilities_bonus.c ./src/inputs_bonus.c \
./src/check_map.c ./src/get_next_line.c ./src/check_errors_bonus.c \
./src/utilities2_bonus.c
SRCB2 = ./src/main.o ./src/utilities_bonus.o ./src/inputs_bonus.o \
./src/check_map.o ./src/get_next_line.o ./src/check_errors_bonus.o \
./src/utilities2_bonus.o
HDRS = ./src/utilslib.h ./libft/libft.h ./minilibx/mlx.h

GC = gcc -Wall -Wextra -Werror
AR = ar rcs

MLXDIR = ./minilibx/
LIBFTDIR = ./libft/

OBJS = $(SRC:.c=.o)

OBJSB = $(SRCB:.c=.o)

.c.o :
	$(GC) -o $@ -c $?

all: $(NAME)

$(NAME): $(OBJS) $(HDRS)
	make -C $(LIBFTDIR)
	make -C $(MLXDIR)
	cp $(MLXDIR)/libmlx.dylib .
	$(GC) -o $(NAME) $(OBJS) -L $(MLXDIR) -lmlx -L $(LIBFTDIR) -lft -framework OpenGL -framework AppKit

clean:
	make clean -C libft
	make clean -C minilibx
	/bin/rm -f $(SRC2) $(SRCB2)

fclean: clean
	make fclean -C libft
	/bin/rm -f $(NAME)
	/bin/rm -f libmlx.dylib

re: fclean all

bonus: $(OBJSB) $(HDRS)
	make -C $(LIBFTDIR)
	make -C $(MLXDIR)
	cp $(MLXDIR)/libmlx.dylib .
	$(GC) -o $(NAME) $(OBJSB) -L $(MLXDIR) -lmlx -L $(LIBFTDIR) -lft -framework OpenGL -framework AppKit

