/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:11:18 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/06 20:20:35 by bgoron           ###   ########.fr       */
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
