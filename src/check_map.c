/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:36:58 by gabo              #+#    #+#             */
/*   Updated: 2024/06/26 10:39:45 by gabo             ###   ########.fr       */
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
	else 
		ft_putstr_fd("\t[Extension invalida]\n\n", 2);
}


int check_extension(char *map)
{
	int i;

	i = 0;
	while (map[i] != '\0')
		i++;
	if (map[i - 4] != '.' || map[i - 3] != 'b'  || map[i - 2] != 'e' || map[i - 1] != 'r')
	{
		print_error(0);
		return (0);
	}
	return (1);
}

void comprobation_map(t_map *map, char *line)
{

		if (ft_strchr(line, 'C') != 0)
			map->n_collectable++;
		if (ft_strchr(line, 'E') != 0)
			map->n_exit++;
		if (ft_strchr(line, 'P') != 0)
			map->n_start++;
	if (map->n_collectable < 0 && map->n_exit != 1 && map->n_start != 1)
	{
		ft_printf("Error en el mapa\n");
		exit(0);
	}
}

int is_rectangle(t_map *map) {
	t_map *copy;
	char *line;
	int count;
	size_t size;

	copy = map;
	count = 0;
	while (line = get_next_line(copy->fd))
	{
		comprobation_map(copy, line);
			
		if (count == 0)
		{
			map->length = (ft_strlen(line));
		}
		size = ft_strlen(line);
		if(ft_strchr(line, '\n') == 0)
			size = ft_strlen(line) + 1;
		count++;
		if (map->length != size)
		{
			ft_printf("%d| %d\n",map->length, ft_strlen(line));
			ft_printf("%s\n", line);
			ft_printf("No es rectangular\n");
			return (0);
		}
		
	}
	ft_printf("Es rectangular\n");
	return (1);
}

int check_map(t_map *map) 
{
	t_map *copy;

	if (map->fd < 0)
	{
		print_error(1);
		return (0);
	}
	copy = map;
	if (is_rectangle(copy) == 0)
	{
		print_error(2);
		return (0);
	}
	copy = map;

	return (1);
}



	// while ((line = get_next_line(map->fd)))
	// {
	// 	if (ft_strchr(line, 'C') != 0)
	// 		map->n_collectable++;
	// 	ft_printf("%s", line);

	// }

