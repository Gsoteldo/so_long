/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 21:28:35 by gabo              #+#    #+#             */
/*   Updated: 2024/06/27 11:23:35 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../mlx/mlx.h"

static int check_extension(char *map)
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

static int comprobation(int argc, char **argv) {
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
	int i;

	i = 0;
	if (comprobation(argc, argv) == 0)
		return (0);
	map = (t_map *)ft_calloc(1, sizeof(t_map));
	map->file = ft_strjoin("./maps/", argv[1]);
	
	map->fd = open(map->file, O_RDONLY);

	if (check_map(map) == 0)
		return (0);

	ft_printf("Numero de coleccionables: %d\n", map->n_collectable);
	ft_printf("Numero de salidas: %d\n", map->n_exit);
	ft_printf("Numero de entradas: %d\n", map->n_start);
	
	ft_printf("Mapa original: \n");
	while (map->map[i])
	{
		ft_printf("%s\n", map->map[i]);
		i++;
	}
	ft_printf("\n");
	i = 0;
	ft_printf("Mapa comprobacion: \n");
	while (map->map_copy[i])
	{
		ft_printf("%s\n", map->map_copy[i]);
		i++;
	}

	mlx = mlx_init();
	if (!mlx)
	return (1);
	win = mlx_new_window(mlx, 500, 500, "so_long");
	if (!win)
		return (free(mlx), 1);
	mlx_loop(mlx);
	close(map->fd);
	free(map);
	return 0;
}