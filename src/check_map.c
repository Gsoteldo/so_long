/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:36:58 by gabo              #+#    #+#             */
/*   Updated: 2024/07/26 00:58:17 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	surrounded_by_walls(char **map)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	size = 0;
	while (map[i++])
		size++;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i == 0 || i == size - 1 || j == 0
				|| (size_t)j == ft_strlen(map[i]) - 1)
				if (map[i][j] != '1')
					print_error(3);
			j++;
		}
		i++;
	}
	return (1);
}

void	flood_fill(t_map *map, int pos_x, int pos_y)
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

int	is_valid_map(t_map *map)
{
	int	i;
	int	pos_x;
	int	pos_y;

	i = 0;
	pos_x = map->size.x;
	pos_y = map->size.y;
	flood_fill(map, pos_x, pos_y);
	while (map->map_copy[i])
	{
		if ((ft_strchr(map->map_copy[i], 'E') != 0
				|| ft_strchr(map->map_copy[i], 'C') != 0))
			print_error(3);
		i++;
	}
	return (1);
}

void	comprobation_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_copy[i] != NULL)
	{
		j = 0;
		while (map->map_copy[i][j++] != '\0')
		{
			if (map->map_copy[i][j] == 'C')
				map->n_collectable++;
			if (map->map_copy[i][j] == 'E')
				map->n_exit++;
			if (map->map_copy[i][j] == 'P')
			{
				map->n_start++;
				map->size.x = i;
				map->size.y = ft_strchr(map->map_copy[i], 'P') - map->map_copy[i];
			}
		}
		i++;
	}
	if (map->n_collectable == 0 || map->n_exit != 1 || map->n_start != 1)
		print_error(2);
	map->size.width = i;
	map->size.height = ft_strlen(map->map_copy[0]);
}

int	is_rectangle(char **map)
{
	int		i;
	size_t	size;

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

int	check_map(t_map *map)
{
	char	*line;
	char	*aux;
	char	*temp;

	aux = ft_strdup("");
	line = NULL;
	if (map->fd < 0)
		print_error(1);
	line = get_next_line(map->fd);
	while (line != NULL)
	{
		temp = aux;
		aux = ft_strjoin(aux, line);
		free(temp);
		free(line);
		line = get_next_line(map->fd);
	}
	free(line);
	map->map_copy = ft_split(aux, '\n');
	map->map = ft_split(aux, '\n');
	close(map->fd);
	comprobation_map(map);
	free(aux);
	if (is_rectangle(map->map_copy) == 0 || surrounded_by_walls(map->map_copy) == 0)
		print_error(2);
	if (is_valid_map(map) == 0)
		print_error(4);
	return (1);
}
