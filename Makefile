# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/29 21:28:44 by gabo              #+#    #+#              #
#    Updated: 2024/06/18 12:59:18 by gabo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = ./src/so_long.c \
		./src/check_map.c \

OBJ = $(SRC:.c=.o)

INCLUDE = -I/usr/include -Imlx


CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
MLX_LIB = /home/gabo/minilibx-linux/libmlx_Linux.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(MLX_LIB)
	@make -C libft
# @make -C mlx
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ) -L libft -lft -o $(NAME) $(INCLUDE)
	@echo "Compilation done"

clean:
	@rm -f $(OBJ)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft

re: fclean all