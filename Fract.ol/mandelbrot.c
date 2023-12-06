/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistegoron <baptistegoron@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:54:14 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/05 21:21:17 by baptistegor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	mandelbrot(int x, int y)
{
	int				i;
	double			tmp;
	int				iter;
	unsigned int	color;
	t_fractol		f;

	i = 0;
	iter = 150;
	f.c_r = map_fractal_x((double)x, -3, 1) / 1.5;
	f.c_i = map_fractal_y((double)y, -2, 2) / 1.5;
	f.z_r = 0;
	f.z_i = 0;
	while((f.z_r * f.z_r) + (f.z_i * f.z_i) < 9 && i <	iter)
	{
		tmp = f.z_r;
		f.z_r = (f.z_r * f.z_r) - (f.z_i * f.z_i) + f.c_r;
		f.z_i = 2 * tmp * f.z_i + f.c_i;
		i++;
	}
	if (i ==	iter)
		return (0);
	color = 0x000000020;
	color += (int)map_color(i, 50);
	return (color);
}