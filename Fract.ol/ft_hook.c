/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:13:09 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/10 17:10:12 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract_ol.h"
#include <stdio.h>

int	key_hook(int keycode, void *fu)
{
	t_fractol	*f;

	f = (t_fractol *)fu;
	if (keycode == RIGHT)
		f->movex -= 10 / f->zoom;
	if (keycode == LEFT)
		f->movex += 10 / f->zoom;
	if (keycode == UP)
		f->movey -= 10 / f->zoom;
	if (keycode == DOWN)
		f->movey += 10 / f->zoom;
	if (keycode == ITERP)
		f->iter += 10;
	if (keycode == ITERM)
		f->iter -= 10;
	if (keycode == PIXELP)
		f->pixel++;
	if (keycode == PIXELM && f->pixel > 1)
		f->pixel--;
	if (keycode == PIXELR)
		f->pixel = 1;
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
		f->movex = ((x / f->zoom + f->movex) - (x / (f->zoom * 1.1)));
		f->movey = ((y / f->zoom + f->movey) - (y / (f->zoom * 1.1)));
		f->zoom *= 1.1;
		f->iter += 2;
		print_fractal(f);
	}
	if (keycode == WDOWN)
	{
		f->movex = ((x / f->zoom + f->movex) - (x / (f->zoom / 1.1)));
		f->movey = ((y / f->zoom + f->movey) - (y / (f->zoom / 1.1)));
		f->zoom /= 1.1;
		f->iter -= 2;
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
		f->c_r = map_fractal_x(x / f->zoom + f->movex, -2, 2);
		f->c_i = map_fractal_y(y / f->zoom + f->movey, -2, 2);
		print_fractal(f);
	}
	return (0);
}
