/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:11:18 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/11 14:21:13 by bgoron           ###   ########.fr       */
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

double	map_color(int i, int max, double minb, double maxb)
{
	int rpt;
	int mod;

	(void)max;
	rpt = 50;
	mod = rpt / 2;
	if (i % rpt > mod - 1)
		return (minb + (maxb - minb) * ((double)(mod - (i % mod)) / mod));
	return (minb + (maxb - minb) * ((double)(i % mod) / mod));
}