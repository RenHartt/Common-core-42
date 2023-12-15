/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:21:07 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/15 14:46:24 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract_ol.h"

void	print_fractal(t_fractol *f)
{
	int					x;
	int					y;
	static unsigned int	lcol[1920];

	y = -1;
	while (++y < H)
	{
		x = -1;
		while (++x < W)
		{
			if (x % f->m->pix == 0 && y % f->m->pix == 0)
			{
				set_values(x, y, f->s->av, f);
				if (f->s->av == 1 || f->s->av == 2)
					f->c->color = mandelbrot_julia(f);
				if (f->s->av == 3)
					f->c->color = burning_ship(f);
				mlx_set_image_pixel(f->mlx, f->img, x, y, f->c->color);
				lcol[x / f->m->pix] = f->c->color;
			}
			else
				mlx_set_image_pixel(f->mlx, f->img, x, y, lcol[x / f->m->pix]);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

int	destroy(int keycode, void *fu)
{
	t_fractol	*f;

	f = (t_fractol *)fu;
	if (keycode == 0)
	{
		mlx_loop_end(f->mlx);
		mlx_destroy_image(f->mlx, f->img);
		mlx_clear_window(f->mlx, f->win);
		mlx_destroy_window(f->mlx, f->win);
		mlx_destroy_display(f->mlx);
		free(f->s);
		free(f->m);
		free(f->c);
		free(f);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
