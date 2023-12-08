/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:11:18 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/08 00:10:23 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract_ol.h"

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
