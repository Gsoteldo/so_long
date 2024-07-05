/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:35:57 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/07/05 12:54:47 by gabo             ###   ########.fr       */
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
	else if (message_flag == 3)
		ft_putstr_fd("\t[Mapa Imposible de resolver]\n\n", 2);
	else 
		ft_putstr_fd("\t[Extension invalida]\n\n", 2);
}