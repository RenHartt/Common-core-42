/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:53:43 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/04 14:06:16 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map_fractal_x(double a, double minb, double maxb)
{
	return (minb + a * ((maxb - minb) / W));
}

double	map_fractal_y(double a, double minb, double maxb)
{
	return (minb + a * ((maxb - minb) / H));
}

double	map_color(double i, double max)
{
	return (i * 255 / max);
}