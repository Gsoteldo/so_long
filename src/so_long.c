/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 21:28:35 by gabo              #+#    #+#             */
/*   Updated: 2024/06/25 19:17:06 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../mlx/mlx.h"

int comprobation(int argc, char **argv) {
	if (argc != 2)
	{
		ft_putstr_fd(RED "Error! " RC, 2);
		ft_putstr_fd("Se necesita este formato: \n", 2);
		ft_putstr_fd("\n\t./so_long (nombre_del_archivo).ber\n\n", 2);
		return (0);
	}

	else if (check_extension(argv[1]) == 0)
		return (0);
	else
		return (1);

}



int main(int argc, char *argv[])
{
	void *mlx;
	void *win;
	t_map *map;
	char *line;

	
	if (comprobation(argc, argv) == 0)
		return (0);
	map = (t_map *)ft_calloc(1, sizeof(t_map));
	map->map = ft_strjoin("./maps/", argv[1]);
	
	map->fd = open(map->map, O_RDONLY);

	if (check_map(map) == 0)
		return (0);

	ft_printf("Numero de coleccionables: %d\n", map->n_collectable);
	ft_printf("Numero de salidas: %d\n", map->n_exit);
	ft_printf("Numero de entradas: %d\n", map->n_start);
	





	mlx = mlx_init();
	if (!mlx)
	return (1);
	win = mlx_new_window(mlx, 1200, 1000, "so_long");
	if (!win)
		return (free(mlx), 1);
	mlx_loop(mlx);
	close(map->fd);
	free(map);
	return 0;
}