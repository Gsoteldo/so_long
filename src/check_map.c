/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:36:58 by gabo              #+#    #+#             */
/*   Updated: 2024/06/26 19:51:35 by gsoteldo         ###   ########.fr       */
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

void flood_fill(t_map *map, int x, int y, int width, int height)
{
	if (x < 0 || x >= height || y  < 0 || y >= width || map->map_copy[x][y] == '1')
		return ;
	
}


void comprobation_map(t_map *map)
{
	int i;

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
			map->posx_start = i;
			map->posy_start = ft_strchr(map->map_copy[i], 'P') - map->map_copy[i];
		}
		i++;
	}
	if (map->n_collectable < 0 && map->n_exit != 1 && map->n_start != 1)
	{
		ft_printf("Error en el mapa\n");
		exit(0);
	}
	map->height = i;
	map->width = ft_strlen(map->map_copy[0]);
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
	comprobation_map(map);
	if (is_rectangle(map->map_copy) == 0 || surrounded_by_walls(map->map_copy) == 0)
	{
		print_error(2);
		return (0);
	}
	
	
}


// void comprobation_map(t_map *map, char *line)
// {

// 		if (ft_strchr(line, 'C') != 0)
// 			map->n_collectable++;
// 		if (ft_strchr(line, 'E') != 0)
// 			map->n_exit++;
// 		if (ft_strchr(line, 'P') != 0)
// 			map->n_start++;
// 	if (map->n_collectable < 0 && map->n_exit != 1 && map->n_start != 1)
// 	{
// 		ft_printf("Error en el mapa\n");
// 		exit(0);
// 	}
// }


// int check_map(t_map *map) 
// {
// 	t_map *copy;

// 	if (map->fd < 0)
// 	{
// 		print_error(1);
// 		return (0);
// 	}
// 	copy = map;
// 	if (is_rectangle(copy) == 0)
// 	{
// 		print_error(2);
// 		return (0);
// 	}
// 	copy = map;

// 	return (1);
// }


// int is_rectangle(t_map *map) {
// 	t_map *copy;
// 	char *line;
// 	int count;
// 	size_t size;

// 	copy = map;
// 	count = 0;
// 	while (line = get_next_line(copy->fd))
// 	{
// 		comprobation_map(copy, line);
			
// 		if (count == 0)
// 		{
// 			map->length = (ft_strlen(line));
// 		}
// 		size = ft_strlen(line);
// 		if(ft_strchr(line, '\n') == 0)
// 			size = ft_strlen(line) + 1;
// 		count++;
// 		if (map->length != size)
// 		{
// 			ft_printf("%d| %d\n",map->length, ft_strlen(line));
// 			ft_printf("%s\n", line);
// 			ft_printf("No es rectangular\n");
// 			return (0);
// 		}
		
// 	}
// 	ft_printf("Es rectangular\n");
// 	return (1);
// }





	// while ((line = get_next_line(map->fd)))
	// {
	// 	if (ft_strchr(line, 'C') != 0)
	// 		map->n_collectable++;
	// 	ft_printf("%s", line);

	// }

