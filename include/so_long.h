/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 21:42:46 by gabo              #+#    #+#             */
/*   Updated: 2024/07/24 00:17:46 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libft/libft.h"
#include "../mlx/mlx.h"

#define RC "\x1b[0m"
#define RED "\x1b[31m"

#define ESC 65307
#define CLOSE_BUTTON 17 
#define W_KEY 119
#define A_KEY 97
#define S_KEY 115
#define D_KEY 100
#define UP_KEY 65362
#define DOWN_KEY 65364
#define LEFT_KEY 65361
#define RIGHT_KEY 65363
#define SIZE 80


typedef struct s_size
{
	int x;
	int y;
	int width;
	int height;
}				t_size;

typedef struct s_image
{
	void	*collectable;
	void	*floor;
	void	*locked_exit;
	void	*player;
	void	*unlocked_exit;
	void	*wall;
}				t_image;

typedef struct s_map
{
	void *mlx;
	void *win;
	int		fd;
	char 	*file;
	char	**map;
	char	**map_copy;
	int 	n_collectable;
	int		n_exit;
	int		n_start;
	t_size	size;
	t_image img;
}				t_map;


int check_map(t_map *map);

void print_error(int message_flag);
void initialize_map(t_map *map);
void free_map(t_map *map);
int close_windows();

void load_images(t_map *map);

int movements(int key, t_map *map);


#endif