/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 23:49:20 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/10 19:44:07 by bgoron           ###   ########.fr       */
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
		return (write(1, "Too few arguments.\nChoose one :\n \
	-mandelbrot\n \
	-burning_ship\n \
	-julia (need two more arguments between -2 and 2)", 113));
	else if (ac != 2 && !ft_strcmp("mandelbrot", av[1]))
		return (write(1, "Mandelbrot don't need arguments after it.", 42));
	else if (ac != 2 && !ft_strcmp("burning_ship", av[1]))
		return (write(1, "Burning_ship don't need arguments after it.", 42));
	if (!ft_strcmp("julia", av[1]))
	{
		if (ac != 4)
			return (write(1, "Arguments need to be between -2 and 2.", 45));
		else if (ft_atof(av[2]) > 2 || ft_atof(av[2]) < -2)
			return (write(1, "Arguments need to be between -2 and 2.", 45));
		else if (ft_atof(av[3]) > 2 || ft_atof(av[3]) < -2)
			return (write(1, "Arguments need to be between -2 and 2.", 45));
	}
	return (0);
}
