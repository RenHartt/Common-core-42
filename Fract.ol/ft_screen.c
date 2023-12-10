/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:21:07 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/10 15:03:26 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract_ol.h"

void	print_fractal(t_fractol *f)
{
	int					x;
	int					y;
	static unsigned int	lcolor[1920];

	y = -1;
	while (++y < H)
	{
		x = -1;
		while (++x < W)
		{
			if (x % f->pixel == 0 && y % f->pixel == 0)
			{
				set_values(x, y, f->av, f);
				if (f->av == 1 || f->av == 2)
					f->color = mandelbrot_julia(f);
				if (f->av == 3)
					f->color = burning_ship(f);
				mlx_pixel_put(f->mlx, f->mlx_win, x, y, f->color);
				lcolor[x / f->pixel] = f->color;
			}
			else
				mlx_pixel_put(f->mlx, f->mlx_win, x, y, lcolor[x / f->pixel]);
		}
	}
	mlx_put_image_to_window(f->mlx, f->mlx_win, f->mlx_img, 0, 0);
}
