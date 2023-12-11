/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:12:19 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/11 17:02:27 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract_ol.h"

unsigned int	get_color(int i, t_fractol *f)
{
	int	begincolor;
	int	endcolor;
	int	gradient;

	begincolor = 0xFF000080;
	f->c->red1 = (begincolor >> 16) & 255;
	f->c->green1 = (begincolor >> 8) & 255;
	f->c->blue1 = begincolor & 255;
	endcolor = 0xFF880000;
	f->c->red2 = (endcolor >> 16) & 255;
	f->c->green2 = (endcolor >> 8) & 255;
	f->c->blue2 = endcolor & 255;
	gradient = 0xFF000000;
	gradient += (int) map_color(i, f->iter, f->c->red1, f->c->red2) << 16;
	gradient += (int) map_color(i, f->iter, f->c->green1, f->c->green2) << 8;
	gradient += (int) map_color(i, f->iter, f->c->blue1, f->c->blue2);
	return (gradient);
}
