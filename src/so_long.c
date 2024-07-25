/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 21:28:35 by gabo              #+#    #+#             */
/*   Updated: 2024/07/25 23:02:01 by gsoteldo         ###   ########.fr       */
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

// int key_view(int key, void * param)
// {
// 	t_map *map_copy;

// 	map_copy = (t_map *)param;
// 	ft_printf("Key: %d\n", key);	
// 	return (0);
// }

void start_game(t_map *map)
{
	/*int i;

	i = 0;*/
	ft_printf("Start game\n");
	map->mlx = mlx_init();
	ft_printf("Mlx: %p\n", map->mlx);
	if (!map->mlx)
	{
		printf("error en la mlx\n");
		//free_map(map);
		/*if (map->map && map->map_copy)
		{
			while (map->map[i])
			{
				free(map->map[i]);
				free(map->map_copy[i]);
				i++;
			}
			free(map->map);
			free(map->map_copy);
		}
		if (map->file)
			free(map->file);*/
		return ;
	}
	map->win = mlx_new_window(map->mlx, map->size.height * SIZE, map->size.width * SIZE, "La leyenda de Sombra");
	if (!map->win)
	{
		printf("no crea la ventana\n");
		free_map(map);
		return ;
	}
	load_images(map);
	mlx_hook(map->win, CLOSE_BUTTON, 1L<<0, close_windows, map);
	// mlx_hook(map->win, ESC, 0, close_windows, &map->mlx);
	mlx_key_hook(map->win, movements, map);
	mlx_loop(map->mlx);

	//return ;
}

int main(int argc, char *argv[])
{
	t_map map;
	// char *line;
	// ft_printf("%d", map.n_movements);
	initialize_map(&map);
	if (comprobation(argc, argv) == 0)
		return (0);
	// map = (t_map )ft_calloc(1, sizeof(t_map));
	map.file = ft_strjoin("./maps/", argv[1]);
	
	map.fd = open(map.file, O_RDONLY);

	if (check_map(&map) == 0)
		return (0);
	


	ft_printf("Numero de coleccionables: %d\n", map.n_collectable);
	ft_printf("Numero de salidas: %d\n", map.n_exit);
	ft_printf("Numero de entradas: %d\n", map.n_start);

	lore_begin();


	start_game(&map);

	
	lore_end();
	free_map(&map);
	return 0;
}
