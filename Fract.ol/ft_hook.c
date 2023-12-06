/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:13:09 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/06 20:50:35 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int button, int x, int y, t_fractol *f)
{
	(void) x;
	(void) y;
	if (button == 1)
		f->leftclick = !f->leftclick;
	/*if (button == 4)
		f->zoom += 1;
	if (button == 5)
		f->zoom -= 1;*/
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
		f->c_r = ((double)x / W - 0.5) * 2;
		f->c_i = ((double)y / H - 0.5) * 2;
	}
	print_fractal(f);
	mlx_put_image_to_window(f->mlx, f->mlx_win, f->m->img, 0, 0);
	return (0);
}
