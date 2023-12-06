/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:13:56 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/06 20:57:01 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	choose_fractal(char **av)
{
	printf("%s\n", av[1]);
	if (!ft_strcmp("mandelbrot", av[1]))
		return (0);
	if (!ft_strcmp("julia", av[1]))
		return (1);
	return (0);
}

void	set_values(int x, int y, int choice, t_fractol *f)
{
	if (!choice)
	{
		f->c_r = map_fractal_x((double)x, -2.5, 1.5);
		f->c_i = map_fractal_y((double)y, -2, 2);
		f->z_r = 0;
		f->z_i = 0;
	}
	else
	{
		f->z_r = map_fractal_x((double)x, -2, 2);
		f->z_i = map_fractal_y((double)y, -2, 2);
	}
}

unsigned int	mandelbrot_julia(t_fractol f)
{
	int				i;
	double			tmp;
	unsigned int	color;

	i = 0;
	f.iter = 50;
	while (((f.z_r * f.z_r) + (f.z_i * f.z_i) < 9 && i < f.iter))
	{
		tmp = f.z_r;
		f.z_r = (f.z_r * f.z_r) - (f.z_i * f.z_i) + f.c_r;
		f.z_i = 2 * tmp * f.z_i + f.c_i;
		i++;
	}
	if (i == f.iter)
		return (0);
	color = 0xFF000020;
	return (get_color(i, f));
}
