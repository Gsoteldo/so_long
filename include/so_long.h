/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 21:42:46 by gabo              #+#    #+#             */
/*   Updated: 2024/06/27 00:16:03 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libft/libft.h"
#include "../mlx/mlx.h"

#define RC "\x1b[0m"
#define RED "\x1b[31m"

typedef struct
{
	int		fd;
	char 	*file;
	char	**map;
	char	**map_copy;
	int 	n_collectable;
	int		n_exit;
	int		n_start;
	int 	width;
	int 	height;
	int 	posx_start;
	int 	posy_start;
}				t_map;

int check_map(t_map *map);

void print_error(int message_flag);



#endif