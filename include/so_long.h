/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 21:42:46 by gabo              #+#    #+#             */
/*   Updated: 2024/06/25 20:31:12 by gsoteldo         ###   ########.fr       */
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
	char	*map;
	int 	n_collectable;
	int		n_exit;
	int		n_start;
	size_t		length;
}				t_map;


//int check_map(char *map);
int check_extension(char *map);
int check_map(t_map *map) ;



#endif