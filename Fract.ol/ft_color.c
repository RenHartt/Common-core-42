/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:12:19 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/06 21:03:20 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	lissage(int i, t_fractol f, int iter)
{
	return \
	(1 + i - log((log(f.z_r * f.z_r + f.z_i * f.z_i)) / log(iter)) / log(2));
}

unsigned int	get_color(int i, t_fractol f)
{
	unsigned int	color;
	double			light;

	light = 2.5;
	color = 0xFF000080;
	color += (unsigned int)(lissage(i, f, f.iter) * light) << 16;
	color += (unsigned int)(lissage(i, f, f.iter) * light) << 8;
	color += (unsigned int)(lissage(i, f, f.iter) * light);
	return (color);
}