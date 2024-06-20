/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 21:28:35 by gabo              #+#    #+#             */
/*   Updated: 2024/06/18 23:09:09 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "mlx.h"




int main(int argc, char *argv[])
{
	//void *mlx;
	char *map;

	if (argc != 2)
	{
		ft_putstr_fd(RED "Error! " RC, 2);
		ft_putstr_fd("Se necesita este formato: \n", 2);
		ft_putstr_fd("\n\t./so_long (nombre_del_archivo).ber\n\n", 2);
		return (0);
	}

	if (check_extension(argv[1]) == 0)
		return (0);
	
	map = ft_strjoin("./maps/", argv[1]);
	
	int fd = open(map, O_RDONLY);
	char *a;

	while ((a = get_next_line(fd)))
	{
		ft_printf("%s", a);
	}




	close(fd);
	// mlx = mlx_init();
	// mlx = mlx_new_window(mlx, 1920, 1080, "so_long");
	// mlx_loop(mlx);
	return (0);
}