/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistegoron <baptistegoron@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:54:17 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/05 22:04:22 by baptistegor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	julia(int x, int y, double c_r, double c_i)
{
	int				i;
	double			tmp;
	unsigned int	color;
	t_fractol		f;

	i = 0;
	f.c_r = c_r;
	f.c_i = c_i;
	f.z_r = map_fractal_x((double)x, -2, 2);
	f.z_i = map_fractal_y((double)y, -2, 2);
	while((f.z_r * f.z_r) + (f.z_i * f.z_i) < 4 && i < 50)
	{
		tmp = f.z_r;
		f.z_r = (f.z_r * f.z_r) - (f.z_i * f.z_i) + f.c_r;
		f.z_i = 2 * tmp * f.z_i + f.c_i;
		i++;
	}
	if (i == 50)
		return (0);
	color = 0x000000020;
	color += (int)map_color(i, 50);
	return (color);
}