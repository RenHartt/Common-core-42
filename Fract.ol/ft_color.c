/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:12:19 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/07 17:54:24 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	get_color(int i, t_fractol *f)
{
	unsigned int	color;
	double			comp;

	color = 0xFF000080;
	comp = map_color(i, f->iter);
	color += (unsigned int)(comp > 255 ? 255 : comp) << 16;
	color += (unsigned int)(comp) << 8;
	color += (unsigned int)(comp);
	return (color);
}