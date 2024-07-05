/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:36:58 by gabo              #+#    #+#             */
/*   Updated: 2024/07/05 14:03:29 by gabo             ###   ########.fr       */
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


/*

void	map_fill(char **map, t_coords size, t_coords pos)
{
	if (pos.y < 1 || pos.y >= size.y - 1 || pos.x < 1 || pos.x >= size.x - 1 
		|| (map[pos.y][pos.x] != 'P' && map[pos.y][pos.x] != '0' 
		&& map[pos.y][pos.x] != 'C' && map[pos.y][pos.x] != 'E'))
		return ;
	if (map[pos.y][pos.x] == 'P')
		map[pos.y][pos.x] = 'p';
	if (map[pos.y][pos.x] == '0')
		map[pos.y][pos.x] = 'F';
	if (map[pos.y][pos.x] == 'C')
		map[pos.y][pos.x] = 'c';
	if (map[pos.y][pos.x] == 'E')
	{
		map[pos.y][pos.x] = 'e';
		return ;
	}
	map_fill(map, size, (t_coords){pos.x - 1, pos.y});
	map_fill(map, size, (t_coords){pos.x, pos.y - 1});
	map_fill(map, size, (t_coords){pos.x + 1, pos.y});
	map_fill(map, size, (t_coords){pos.x, pos.y + 1});
}

*/

// void	fill(char **tab, t_point size, t_point cur, char to_fill)
// {
// 	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x || tab[cur.y][cur.x] != to_fill)
// 		return;
// 	tab[cur.y][cur.x] = 'F';
// 	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
// 	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
// 	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
// 	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
// }

// void	flood_fill(char **tab, t_point size, t_point begin)
// {
// 	fill(tab, size, begin, tab[begin.y][begin.x]);
// }



fill(t_map *map, t_size size, t_size pos)
{
	if (pos.x < 1 || pos.x >= size.width || pos.y  < 1 || pos.y >= size.height || map->map_copy[pos.x][pos.y] == '1' || map->map_copy[pos.x][pos.y] == 'X')
		return ;
	if (map->map_copy[pos.y][pos.x] == 'P')
		map->map_copy[pos.y][pos.x] = 'p';
	if (map->map_copy[pos.y][pos.x] == '0')
		map->map_copy[pos.y][pos.x] = 'F';
	if (map->map_copy[pos.y][pos.x] == 'C')
		map->map_copy[pos.y][pos.x] = 'c';
	if (map->map_copy[pos.y][pos.x] == 'E')
	{
		map->map_copy[pos.y][pos.x] = 'e';
		return ;
	}
	flood_fill(map, size, (t_size){pos.x - 1, pos.y});
	flood_fill(map, size, (t_size){pos.x + 1, pos.y});
	flood_fill(map, size, (t_size){pos.x, pos.y - 1});
	flood_fill(map, size, (t_size){pos.x, pos.y + 1});


}

void ft_flood_fill(t_map *map, t_size size, t_size pos){
	fill(map, size, (t_size){pos.x, pos.y});
}

int is_valid_map(t_map *map)
{
	int i;

	i++;
	ft_flood_fill(map, map->size, (t_size){map->size.x, map->size.y});
	i = 0;
	while (map->map_copy[i])
	{
		ft_printf("%s\n", map->map_copy[i]);
		i++;
	}
	i = 0;
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
			map->size->x = i;
			map->size->y = ft_strchr(map->map_copy[i], 'P') - map->map_copy[i];
		}
		i++;
	}
	if (map->n_collectable == 0 || map->n_exit != 1 || map->n_start != 1)
	{
		ft_printf("Error en el mapa\n");
		exit(0);
	}
	map->size->height = i;
	map->size->width = ft_strlen(map->map_copy[0]);
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

