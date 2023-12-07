/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:21:07 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/07 14:30:37 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
			color = mandelbrot_julia(*f);
			my_mlx_pixel_put((f->m), x, y, color);
			x++;
		}
		y++;
	}
}
