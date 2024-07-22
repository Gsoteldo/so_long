/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:02:43 by gabo              #+#    #+#             */
/*   Updated: 2024/07/22 16:41:07 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void load_sprites(t_map *map)
{
	int width;
	int height;

	width = 50;
	height = 50;

	if (!map->mlx || !map->win || !map)
		print_error(4);		
	map->img.collectable = mlx_xpm_file_to_image(map->mlx, "./images/collectable.xpm", &width, &height);
	map->img.floor = mlx_xpm_file_to_image(map->mlx, "./images/floor.xpm", &width, &height);
	map->img.locked_exit = mlx_xpm_file_to_image(map->mlx, "./images/locked_exit.xpm", &width, &height);
	map->img.player = mlx_xpm_file_to_image(map->mlx, "./images/player.xpm", &width, &height);
	map->img.unlocked_exit = mlx_xpm_file_to_image(map->mlx, "./images/unlocked_exit.xpm", &width, &height);
	map->img.wall = mlx_xpm_file_to_image(map->mlx, "./images/wall.xpm", &width, &height);
	if (!map->img.collectable || !map->img.floor || !map->img.locked_exit || !map->img.player || !map->img.unlocked_exit || !map->img.wall)
	{
		print_error(4);
        // Asegúrate de liberar recursos si hay un error
        mlx_destroy_image(map->mlx, map->img.collectable);
        mlx_destroy_image(map->mlx, map->img.floor);
        mlx_destroy_image(map->mlx, map->img.locked_exit);
        mlx_destroy_image(map->mlx, map->img.player);
        mlx_destroy_image(map->mlx, map->img.unlocked_exit);
        mlx_destroy_image(map->mlx, map->img.wall);
	}
}

void load_images(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!map->mlx || !map->win || !map)
	{
		print_error(4);
	}
		
	ft_memset(&(map->img), 0, sizeof(t_image));
	//map->img = (t_image)ft_calloc(1, sizeof(t_image));
	load_sprites(map);
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '1')
				mlx_put_image_to_window(map->mlx, map->win, map->img.wall, j * 50, i * 50);
			else if (map->map[i][j] == '0')
				mlx_put_image_to_window(map->mlx, map->win, map->img.floor, j * 50, i * 50);
			else if (map->map[i][j] == 'C')
				mlx_put_image_to_window(map->mlx, map->win, map->img.collectable, j * 50, i * 50);
			else if (map->map[i][j] == 'E')
				mlx_put_image_to_window(map->mlx, map->win, map->img.locked_exit, j *50, i * 50);
			else if (map->map[i][j] == 'P')
				mlx_put_image_to_window(map->mlx, map->win, map->img.player, j * 50,  i * 50);
			j++;
		}
		i++;
	}	
}

