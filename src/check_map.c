/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:36:58 by gabo              #+#    #+#             */
/*   Updated: 2024/06/19 19:45:31 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void print_error(int message_flag)
{
	ft_putstr_fd(RED "Error:\n" RC, 2);
	if (message_flag == 1)
		ft_putstr_fd("\t[No se encontro mapa]\n\n", 2);
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

int check_map() 
{
	
}



