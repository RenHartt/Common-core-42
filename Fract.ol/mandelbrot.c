/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:54:14 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/04 15:17:38 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	mandelbrot(int x, int y)
{
	int				i;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			tmp;
	unsigned int	color;

	i = 0;
	c_r = map_fractal_x((double)x, -3, 1) / 1.5;
	c_i = map_fractal_y((double)y, -2, 2) / 1.5;
	z_r = 0;
	z_i = 0;
	while((z_r * z_r) + (z_i * z_i) < 9 && i < 50)
	{
		tmp = z_r;
		z_r = (z_r * z_r) - (z_i * z_i) + c_r;
		z_i = 2 * tmp * z_i + c_i;
		i++;
	}
	if (i == 50)
		return (0);
	color = 0x000000020;
	//color += ((int) map_color(i, iter) << 16);
	//color += ((int) map_color(i, iter) % 255 << 8);
	color += (int)map_color(i, 50);
	return (color);
}