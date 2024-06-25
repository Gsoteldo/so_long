# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/29 21:28:44 by gabo              #+#    #+#              #
#    Updated: 2024/06/24 18:00:11 by gsoteldo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = ./src/so_long.c \
		./src/check_map.c \

OBJ = $(SRC:.c=.o)

#INCLUDE = -I/usr/include -Imlx



CC = gcc
# CFLAGS = -Wall -Wextra -Werror -MMD
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
#LIB = -L. -lmlx -framework OpenGL -framework AppKit
DEPS = $(addsuffix .d, $(basename $(SRC)))

# MLX_LIB = /home/gabo/minilibx-linux/libmlx_Linux.a

all: $(NAME)


#$(LIB) $(LIBFT) $(MLX_FLAGS) $(CFLAGS) 
-include $(DEPS)
$(NAME): $(OBJ)  
	@make -C libft
	@make -C mlx all
	@cp ./mlx/libmlx_Linux.a .
	@$(CC) $(SRC) $(MLX_FLAGS)  -L libft -lft -o $(NAME)
	@echo "Compilation done"

clean:
	@rm -f $(OBJ)
	@make clean -C libft
	@make clean -C mlx

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft
	@rm -f libmlx_Linux.a
	@rm -f libmlx.a

re: fclean all