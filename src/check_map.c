/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:36:58 by gabo              #+#    #+#             */
/*   Updated: 2024/07/22 16:06:59 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int surrounded_by_walls(char **map)
{
	int i;
	int j;
	int size;

	i = 0;
	j = 0;
	size = 0;
	while(map[i++])
		size++;
	i = 0;
	while (map[i])
	{
			j = 0;
		while(map[i][j])
		{
			if (i == 0 || i == size - 1 || j == 0 || j == ft_strlen(map[i]) - 1)
			{
				if (map[i][j] != '1')
				{
					ft_printf("No esta rodeado de paredes\n");
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	ft_printf("Esta rodeado de paredes\n");
	return (1);
}



void flood_fill(t_map *map, int pos_x, int pos_y)
{
	if (pos_x < 0 || pos_x >= map->size.width 
		|| pos_y < 0 || pos_y >= map->size.height
		|| map->map_copy[pos_x][pos_y] == '1'
		|| map->map_copy[pos_x][pos_y] == 'X')
		return ;
		

	map->map_copy[pos_x][pos_y] = 'X';
	flood_fill(map, pos_x + 1, pos_y);
	flood_fill(map, pos_x - 1, pos_y);
	flood_fill(map, pos_x, pos_y + 1);
	flood_fill(map, pos_x, pos_y - 1);

}

int is_valid_map(t_map *map)
{
	int i;
	int pos_x;
	int pos_y;

	i = 0;
	pos_x = map->size.x;
	pos_y = map->size.y;

	flood_fill(map, pos_x, pos_y);
	while (map->map_copy[i])
	{
		if ((ft_strchr(map->map_copy[i], 'E') != 0 || ft_strchr(map->map_copy[i], 'C') != 0))
		{
			ft_printf("Mapa imposible de resolver\n");
			return (0);
		}
		i++;
	}
	return (1);
}


void comprobation_map(t_map *map)
{
	int i;

	map->n_collectable = 0;
	map->n_exit = 0;
	map->n_start = 0;

	i = 0;
	while(map->map_copy[i] != NULL)
	{
		if (ft_strchr(map->map_copy[i], 'C') != 0)
			map->n_collectable++;
		if (ft_strchr(map->map_copy[i], 'E') != 0)
			map->n_exit++;
		if (ft_strchr(map->map_copy[i], 'P') != 0)
		{
			map->n_start++;
			map->size.x = i;
			map->size.y = ft_strchr(map->map_copy[i], 'P') - map->map_copy[i];
		}
		i++;
	}
	ft_printf("Numero de coleccionables: %d\n", map->n_collectable);
	ft_printf("Numero de salidas: %d\n", map->n_exit);
	ft_printf("Numero de entradas: %d\n", map->n_start);
	if (map->n_collectable == 0 || map->n_exit != 1 || map->n_start != 1)
	{
		ft_printf("Error en el mapa\n");
		exit(0);
	}
	map->size.width = i;
	map->size.height = ft_strlen(map->map_copy[0]);
}

int is_rectangle(char **map) {

	int i;
	size_t size;

	i = 1;
	size = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != size)
		{
			ft_printf("No es rectangular\n");
			return (0);
		}
		i++;
	}
	ft_printf("Es rectangular\n");
	return (1);
}

int check_map(t_map *map) 
{
	char *line;
	char *aux;
	
	aux = ft_strdup("");
	if (map->fd < 0)
	{
		print_error(1);
		return (0);
	}

	line = get_next_line(map->fd);
	while (line != NULL)
	{
		aux = ft_strjoin(aux, line);
		line = get_next_line(map->fd);
	}
	map->map_copy = ft_split(aux, '\n');
	map->map = ft_split(aux, '\n');
	comprobation_map(map);
	if (is_rectangle(map->map_copy) == 0 || surrounded_by_walls(map->map_copy) == 0)
	{
		print_error(2);
		return (0);
	}
	if (is_valid_map(map) == 0)
	{
		print_error(3);
		return (0);
	}
}
