/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 23:49:20 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/11 17:37:50 by bgoron           ###   ########.fr       */
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

int	error_input(int ac, char **av)
{
	if (ac < 2)
		return (ft_putstr("Too few arguments.\nChoose one :\n \
	-mandelbrot\n \
	-burning_ship\n \
	-julia (need two more arguments between -2 and 2)"));
	else if (ac != 2 && !ft_strcmp("mandelbrot", av[1]))
		return (ft_putstr("Mandelbrot don't need arguments."));
	else if (ac != 2 && !ft_strcmp("burning_ship", av[1]))
		return (ft_putstr("Burning_ship don't need arguments."));
	if (!ft_strcmp("julia", av[1]))
	{
		if (ac != 4)
			return (ft_putstr("Arguments need to be 2."));
		else if (ft_atof(av[2]) > 2 || ft_atof(av[2]) < -2)
			return (ft_putstr("Arguments need to be between -2 and 2."));
		else if (ft_atof(av[3]) > 2 || ft_atof(av[3]) < -2)
			return (ft_putstr("Arguments need to be between -2 and 2."));
	}
	else if (ft_strcmp("mandelbrot", av[1]) && ft_strcmp("burning_ship", av[1]))
		return (ft_putstr("Invalid name !\n\t-mandelbrot\n\t-burning_ship\n \
	-julia (need two more arguments between -2 and 2."));
	return (0);
}
