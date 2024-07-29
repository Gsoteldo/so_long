/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lore.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 22:08:54 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/07/26 01:12:14 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	lore_begin(void)
{
	ft_printf("\n");
	ft_printf("-------------------------------------------------------------");
	ft_printf("------------------\n");
	ft_printf("\n");
	ft_printf(GREEN"                            La leyenda de Sombra\n" RC);
	ft_printf("\nEn el corazón de la noche, Sombra, el ladrón más hábil ");
	ft_printf("de la ciudad,\nse infiltró en la misteriosa Casa del Oro. ");
	ft_printf("Deslizando su figura entre sombras,\nse adentró en la ");
	ft_printf("mansión, donde brillaban monedas doradas bajo la tenue luz\n");
	ft_printf("de la luna. Con cada paso silencioso, la fortuna de Sombra ");
	ft_printf("se acercaba más\ny más, prometiendo riquezas inimaginables...");
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("-------------------------------------------------------------");
	ft_printf("------------------\n");
	ft_printf("\n");
}

void	lore_thinks(t_map *map)
{
	ft_printf("\n");
	ft_printf("-------------------------------------------------------------");
	ft_printf("------------------\n");
	ft_printf("\n");
	ft_printf("Al acercarse a la puerta de salida, Sombra se detuvo un ");
	ft_printf("instante y pensó:\n");
	ft_printf("\n");
	ft_printf("\"No puedo irme aún, tengo que terminar lo que empecé, ");
	ft_printf("aun faltan %d monedas\"\n", map->n_collectable);
	ft_printf("\n");
	ft_printf("-------------------------------------------------------------");
	ft_printf("------------------\n");
	ft_printf("\n");
}

void	lore_end(void)
{
	ft_printf("\n");
	ft_printf("-------------------------------------------------------------");
	ft_printf("------------------\n");
	ft_printf("\n");
	ft_printf("Con la bolsa llena de monedas y su corazón latiendo con la ");
	ft_printf("emoción\nde la victoria, se encaminó hacia la salida. ");
	ft_printf("Con un salto ágil, atravesó\nla puerta y se deslizó en la ");
	ft_printf("oscuridad de la noche.\n");
	ft_printf("\n");
	ft_printf("Con todo el dinero conseguido, Sombra planeaba abandonar \n");
	ft_printf("su vida de ladrón para siempre. Utilizaría su botín para ");
	ft_printf("construir\nun refugio seguro para los huérfanos de la ciudad,");
	ft_printf(" ofreciendo esperanza\n y un futuro mejor a aquellos que, ");
	ft_printf("como él, habían vivido en las sombras.\n");
	ft_printf("\n");
	ft_printf(GREEN"                                     FIN\n" RC);
	ft_printf("-------------------------------------------------------------");
	ft_printf("------------------\n");
	ft_printf("\n");
}
