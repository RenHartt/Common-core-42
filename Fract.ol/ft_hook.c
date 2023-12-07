/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:13:09 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/07 18:42:51 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int button, t_fractol *f)
{
	if (button == 65361) //fleche gauche
		f->movex -= 10 / f->zoom;
	if (button == 65363)//fleche gauche
		f->movex += 10 / f->zoom;
	if (button == 65362) //fleche haut
		f->movey -= 10 / f->zoom;
	if (button == 65364)//fleche bas
		f->movey += 10 / f->zoom;
	if (button == 43) //+
		f->iter += 10;
	if (button == 45)//-
		f->iter -= 10;
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractol *f)
{
	if (button == 1)
		f->leftclick = !f->leftclick;
	if (button == 4)
	{
		f->movex = ((double)(x / f->zoom + f->movex) - (x / (f->zoom * 1.1)));
		f->movey = ((double)(y / f->zoom + f->movey) - (y / (f->zoom * 1.1)));
		f->zoom *= 1.1;
	}
	if (button == 5)
	{
		f->movex = ((double)(x / f->zoom + f->movex) - (x / (f->zoom / 1.1)));
		f->movey = ((double)(y / f->zoom + f->movey) - (y / (f->zoom / 1.1)));
		f->zoom /= 1.1;
	}
	print_fractal(f);
	mlx_put_image_to_window(f->mlx, f->mlx_win, f->m->img, 0, 0);
	return (0);
}

int	loop_hook(t_fractol *f)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (f->leftclick == 1)
	{
		mlx_mouse_get_pos(f->mlx, f->mlx_win, &x, &y);
		f->c_r = map_fractal_x(x / f->zoom + f->movex, -2, 2);
		f->c_i = map_fractal_y(y / f->zoom + f->movey, -2, 2);
		print_fractal(f);
		mlx_put_image_to_window(f->mlx, f->mlx_win, f->m->img, 0, 0);
	}
	return (0);
}
