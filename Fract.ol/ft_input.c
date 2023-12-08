/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 23:49:20 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/08 03:32:05 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract_ol.h"

int	choose_fractal(char **av)
{
	if (!ft_strcmp("mandelbrot", av[1]))
		return (1);
	if (!ft_strcmp("julia", av[1]))
		return (2);
	if (!ft_strcmp("burning_ship", av[1]))
		return (3);
	return (0);
}

void	error_input(void)
{
	write(1, "Wrong argument !\nChoose mandelbrot or burning_ship \
	or julia (need 2 more args for setup)\n", 91);
}
