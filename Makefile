# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/29 21:28:44 by gabo              #+#    #+#              #
#    Updated: 2024/07/25 23:11:21 by gsoteldo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = ./src/so_long.c \
		./src/check_map.c \
		./src/utils.c \
		./src/window_management.c \
		./src/movement.c \
		./src/lore.c \

OBJ = $(SRC:.c=.o)

#INCLUDE = -I/usr/include -Imlx



CC = gcc #-g3 -fsanitize=address,leak
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

all: $(NAME)


$(NAME): $(OBJ)  
	@make -s -C libft
	@make -s -C mlx
	@cp ./mlx/libmlx_Linux.a .
	@$(CC) $(CFLAGS) $(SRC) $(MLX_FLAGS)  -L libft -lft -o $(NAME)
	@echo "Compilation done"

git:
	git add *
	git commit
	git push

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