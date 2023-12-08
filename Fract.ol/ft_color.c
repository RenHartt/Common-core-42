/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:12:19 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/08 03:31:51 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract_ol.h"

unsigned int	get_color(int i, t_fractol *f)
{
	unsigned int	color;
	unsigned int	comp;

	color = 0xFF000080;
	comp = map_color(i, f->iter);
	color += comp << 16;
	color += comp << 8;
	color += comp;
	return (color);
}
