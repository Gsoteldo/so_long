/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lore.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 22:08:54 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/07/25 14:31:59 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/so_long.h"

void lore_begin()
{
	ft_printf("\n");
	ft_printf("-------------------------------------------------------------------------------\n");
	ft_printf("\n");
	ft_printf(GREEN"                            La leyenda de Sombra\n" RC);
	ft_printf("\n");
	ft_printf("En el corazón de la noche, Sombra, el ladrón más hábil de la ciudad,\n");
	ft_printf("se infiltró en la misteriosa Casa del Oro. Deslizando su figura entre sombras,\n");
	ft_printf("se adentró en la mansión, donde brillaban monedas doradas bajo la tenue luz\n");
	ft_printf("de la luna. Con cada paso silencioso, la fortuna de Sombra se acercaba más\n");
	ft_printf("y más, prometiendo riquezas inimaginables...\n");
	ft_printf("-------------------------------------------------------------------------------\n");
	ft_printf("\n");
}

void lore_thinks(t_map *map)
{
	ft_printf("\n");
	ft_printf("-------------------------------------------------------------------------------\n");
	ft_printf("\n");
	ft_printf("Al acercarse a la puerta de salida, Sombra se detuvo un instante y pensó:\n");
	ft_printf("\n");
	ft_printf("No puedo irme aún, tengo que terminar lo que empecé, aun faltan %d monedas\n", map->n_collectable);
	ft_printf("\n");
	ft_printf("-------------------------------------------------------------------------------\n");
	ft_printf("\n");

}


void lore_end()
{
	ft_printf("\n");
	ft_printf("-------------------------------------------------------------------------------\n");
	ft_printf("\n");
	ft_printf("Con la bolsa llena de monedas y su corazón latiendo con la emoción\n");
	ft_printf("de la victoria, se encaminó hacia la salida. Con un salto ágil, atravesó\n");
	ft_printf("la puerta y se deslizó en la oscuridad de la noche.\n");
	ft_printf("\n");
	ft_printf("Con todo el dinero conseguido, Sombra planeaba abandonar \n");
	ft_printf("su vida de ladrón para siempre. Utilizaría su botín para construir\n");
	ft_printf("un refugio seguro para los huérfanos de la ciudad, ofreciendo esperanza\n");
	ft_printf("y un futuro mejor a aquellos que, como él, habían vivido en las sombras.\n");
	ft_printf("\n");
	ft_printf(GREEN"                                     FIN\n" RC);
	ft_printf("-------------------------------------------------------------------------------\n");
	ft_printf("\n");
}





// En el corazón de la noche, Sombra, el ladrón más hábil de la ciudad,
// se infiltró en la misteriosa Casa del Oro. Deslizando su figura entre sombras,
// se adentró en la mansión, donde brillaban monedas doradas bajo la tenue luz
// de la luna. Con cada paso silencioso, la fortuna de Sombra se acercaba más
// y más, prometiendo riquezas inimaginables...





// Con la bolsa llena de monedas y su corazón latiendo con la emoción
// de la victoria, se encaminó hacia la salida. Con un salto ágil, atravesó
// la última ventana y se deslizó en la oscuridad de la noche.

// Con todo el dinero conseguido, Sombra planeaba abandonar 
// su vida de ladrón para siempre. Utilizaría su botín para construir
// un refugio seguro para los huérfanos de la ciudad, ofreciendo esperanza
// y un futuro mejor a aquellos que, como él, habían vivido en las sombras.