/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 21:46:02 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/06 20:28:22 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractol	*f;

	f = malloc(sizeof(t_fractol));
	f->m = malloc(sizeof(t_data));
	f->av = choose_fractal(av);
	set_values(0, 0, f->av, f);
	if (ac >= 2)
	{
		f->mlx = mlx_init();
		f->mlx_win = mlx_new_window(f->mlx, W, H, "Fract.ol");
		f->m->img = mlx_new_image(f->mlx, W, H);
		f->m->addr = mlx_get_data_addr \
		(f->m->img, &f->m->bits_per_pixel, &f->m->line_length, &f->m->endian);
		if (ac == 4)
		{
			f->c_r = ft_atof(av[2]);
			f->c_i = ft_atof(av[3]);
		}
		mlx_mouse_hook(f->mlx_win, mouse_hook, f);
		mlx_loop_hook(f->mlx, loop_hook, f);
		mlx_loop(f->mlx);
	}
	return (0);
}
