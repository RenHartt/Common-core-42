/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:21:07 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/08 03:30:05 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract_ol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*((unsigned int *)dst) = color;
}

void	print_fractal(t_fractol *f)
{
	unsigned int	color;
	int				x;
	int				y;

	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			set_values(x, y, f->av, f);
			if (f->av == 1 || f->av == 2)
				color = mandelbrot_julia(f);
			if (f->av == 3)
				color = burning_ship(f);
			my_mlx_pixel_put((f->m), x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->mlx_win, f->m->img, 0, 0);
}
