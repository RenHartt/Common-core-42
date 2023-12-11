/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:13:09 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/11 16:52:25 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract_ol.h"
#include <stdio.h>

int	key_hook(int keycode, void *fu)
{
	t_fractol	*f;

	f = (t_fractol *)fu;
	if (keycode == RIGHT)
		f->m->movex -= 10 / f->m->zoom;
	if (keycode == LEFT)
		f->m->movex += 10 / f->m->zoom;
	if (keycode == UP)
		f->m->movey -= 10 / f->m->zoom;
	if (keycode == DOWN)
		f->m->movey += 10 / f->m->zoom;
	if (keycode == ITERP)
		f->iter += 10;
	if (keycode == ITERM)
		f->iter -= 10;
	if (keycode == PIXELP)
		f->m->pixel++;
	if (keycode == PIXELM && f->m->pixel > 1)
		f->m->pixel--;
	if (keycode == PIXELR)
		f->m->pixel = 1;
	if (keycode == ESCAP)
		destroy(0, f);
	print_fractal(f);
	return (0);
}

int	wheel_hook(int keycode, void *fu)
{
	int			x;
	int			y;
	t_fractol	*f;

	f = (t_fractol *)fu;
	mlx_mouse_get_pos(f->mlx, &x, &y);
	if (keycode == WUP)
	{
		f->m->movex = ((x / f->m->zoom + f->m->movex) - (x / (f->m->zoom * 1.5)));
		f->m->movey = ((y / f->m->zoom + f->m->movey) - (y / (f->m->zoom * 1.5)));
		f->m->zoom *= 1.5;
		print_fractal(f);
	}
	if (keycode == WDOWN)
	{
		f->m->movex = ((x / f->m->zoom + f->m->movex) - (x / (f->m->zoom / 1.5)));
		f->m->movey = ((y / f->m->zoom + f->m->movey) - (y / (f->m->zoom / 1.5)));
		f->m->zoom /= 1.5;
		print_fractal(f);
	}
	return (0);
}

int	mouse_hook(int keycode, void *fu)
{
	t_fractol	*f;

	f = (t_fractol *)fu;
	if (keycode == 1)
		f->leftclick = !f->leftclick;
	print_fractal(f);
	return (0);
}

int	loop_hook(void *fu)
{
	int			x;
	int			y;
	t_fractol	*f;

	f = (t_fractol *)fu;
	mlx_mouse_get_pos(f->mlx, &x, &y);
	if (f->leftclick == 1)
	{
		f->s->c_r = map_fractal_x(x / f->m->zoom + f->m->movex, -2, 2);
		f->s->c_i = map_fractal_y(y / f->m->zoom + f->m->movey, -2, 2);
		print_fractal(f);
	}
	return (0);
}
