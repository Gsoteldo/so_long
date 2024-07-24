/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:35:57 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/07/24 00:16:57 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void print_error(int message_flag)
{
	ft_putstr_fd(RED "Error:\n" RC, 2);
	if (message_flag == 1)
		ft_putstr_fd("\t[No se encontro mapa]\n\n", 2);
	else if (message_flag == 2)
		ft_putstr_fd("\t[mapa invalido]\n\n", 2);
	else if (message_flag == 3)
		ft_putstr_fd("\t[Mapa imposible de resolver]\n\n", 2);
	else if (message_flag == 4)
		ft_putstr_fd("\t[No se pudieron cargar las imagenes]\n\n", 2);
	else
		ft_putstr_fd("\t[Extension invalida]\n\n", 2);
	exit(0);
}

int close_windows()
{
	exit(0);
}

void initialize_map(t_map *map)
{
	map->size.x = 0;
	map->size.y = 0;
	map->n_collectable = 0;
	map->n_exit = 0;
	map->map = NULL;
	map->map_copy = NULL;
	map->mlx = NULL;
	map->win = NULL;
	ft_memset(&(map->img), 0, sizeof(t_image));
}

void free_map(t_map *map)
{
	int i;

	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		free(map->map_copy[i]);
		i++;
	}
	free(map->map);
	free(map->map_copy);
	free(map->img.collectable);
	free(map->img.floor);
	free(map->img.locked_exit);
	free(map->img.player);
	free(map->img.unlocked_exit);
	free(map->img.wall);
	free(map->mlx);
	free(map->win);
}
