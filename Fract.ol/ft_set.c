/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:13:56 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/10 19:30:20 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract_ol.h"

void	set_values(int x, int y, int choice, t_fractol *f)
{
	if (choice == 1)
	{
		f->c_r = map_fractal_x(x / f->zoom + f->movex, -2.5, 1.5);
		f->c_i = map_fractal_y(y / f->zoom + f->movey, -2, 2);
		f->z_r = 0;
		f->z_i = 0;
	}
	else if (choice == 2)
	{
		f->z_r = map_fractal_x(x / f->zoom + f->movex, -2, 2);
		f->z_i = map_fractal_y(y / f->zoom + f->movey, -2, 2);
	}
	if (choice == 3)
	{
		f->c_r = map_fractal_x(x / f->zoom + f->movex, -2.5, 1.5);
		f->c_i = map_fractal_y(y / f->zoom + f->movey, -2.5, 1.5);
		f->z_r = 0;
		f->z_i = 0;
	}
}

t_fractol	*init_fractol(int ac, char **av, int iter)
{
	t_fractol	*f;

	f = ft_calloc(1, sizeof(t_fractol));
	f->zoom = 1;
	f->pixel = 1;
	f->av = choose_fractal(av);
	set_values(0, 0, f->av, f);
	if (ac >= 2)
	{
		if (ac == 4)
		{
			f->c_r = ft_atof(av[2]);
			f->c_i = ft_atof(av[3]);
		}
		f->mlx = mlx_init();
		f->mlx_win = mlx_new_window(f->mlx, W, H, "Fract.ol");
		f->mlx_img = mlx_new_image(f->mlx, W, H);
	}
	f->leftclick = 0;
	f->iter = iter;
	return (f);
}

unsigned int	mandelbrot_julia(t_fractol *f)
{
	int		i;
	double	tmp;

	i = 0;
	while (((f->z_r * f->z_r) + (f->z_i * f->z_i) < 4 && i < f->iter))
	{
		tmp = f->z_r;
		f->z_r = (f->z_r * f->z_r) - (f->z_i * f->z_i) + f->c_r;
		f->z_i = 2 * tmp * f->z_i + f->c_i;
		i++;
	}
	if (i == f->iter)
		return (0);
	return (get_color(i, f));
}

unsigned int	burning_ship(t_fractol *f)
{
	int		i;
	double	tmp;

	i = 0;
	while (((f->z_r * f->z_r) + (f->z_i * f->z_i) < 4 && i < f->iter))
	{
		tmp = f->z_r;
		f->z_r = (f->z_r * f->z_r) - (f->z_i * f->z_i) + f->c_r;
		f->z_i = 2 * fabs(tmp * f->z_i) + f->c_i;
		i++;
	}
	if (i == f->iter)
		return (0);
	return (get_color(i, f));
}

int	destroy(int keycode, void *fu)
{
	t_fractol	*f;

	f = (t_fractol *)fu;
	if (keycode == 0)
	{
		mlx_loop_end(f->mlx);
		mlx_destroy_image(f->mlx, f->mlx_img);
		mlx_destroy_window(f->mlx, f->mlx_win);
		mlx_destroy_display(f->mlx);
		free(f);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
