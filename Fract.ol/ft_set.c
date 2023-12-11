/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:13:56 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/11 19:23:03 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract_ol.h"

void	set_values(int x, int y, int choice, t_fractol *f)
{
	double	s;

	s = (double)W / (double)H;
	if (choice == 1)
	{
		f->s->c_r = map_fract_x(x / f->m->zoom + f->m->movx, -2.5 * s, 1.5 * s);
		f->s->c_i = map_fract_y(y / f->m->zoom + f->m->movy, -2, 2);
		f->s->z_r = 0;
		f->s->z_i = 0;
	}
	else if (choice == 2)
	{
		f->s->z_r = map_fract_x(x / f->m->zoom + f->m->movx, -2 * s, 2 * s);
		f->s->z_i = map_fract_y(y / f->m->zoom + f->m->movy, -2, 2);
	}
	if (choice == 3)
	{
		f->s->c_r = map_fract_x(x / f->m->zoom + f->m->movx, -2.5 * s, 1.5 * s);
		f->s->c_i = map_fract_y(y / f->m->zoom + f->m->movy, -2.5, 1.5);
		f->s->z_r = 0;
		f->s->z_i = 0;
	}
}

t_fractol	*init_fractol(int ac, char **av, int iter)
{
	t_fractol	*f;

	f = ft_calloc(1, sizeof(t_fractol));
	f->s = ft_calloc(1, sizeof(t_set));
	f->m = ft_calloc(1, sizeof(t_move));
	f->c = ft_calloc(1, sizeof(t_color));
	f->iter = iter;
	f->m->zoom = 1;
	f->m->pixel = 1;
	f->leftclick = 0;
	f->rightclick = 0;
	f->s->av = choose_fractal(av);
	set_values(0, 0, f->s->av, f);
	if (ac >= 2)
	{
		if (ac == 4)
		{
			f->s->c_r = ft_atof(av[2]);
			f->s->c_i = ft_atof(av[3]);
		}
		f->mlx = mlx_init();
		f->win = mlx_new_window(f->mlx, W, H, "Fract.ol");
		f->img = mlx_new_image(f->mlx, W, H);
	}
	return (f);
}

unsigned int	mandelbrot_julia(t_fractol *f)
{
	int		i;
	double	tmp;

	i = 0;
	while (((f->s->z_r * f->s->z_r) + (f->s->z_i * f->s->z_i) < 4 \
	&& i < f->iter))
	{
		tmp = f->s->z_r;
		f->s->z_r = (f->s->z_r * f->s->z_r) - (f->s->z_i * f->s->z_i) \
		+ f->s->c_r;
		f->s->z_i = 2 * tmp * f->s->z_i + f->s->c_i;
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
	while (((f->s->z_r * f->s->z_r) + (f->s->z_i * f->s->z_i) < 4 \
	&& i < f->iter))
	{
		tmp = f->s->z_r;
		f->s->z_r = (f->s->z_r * f->s->z_r) - (f->s->z_i * f->s->z_i) \
		+ f->s->c_r;
		f->s->z_i = 2 * fabs(tmp * f->s->z_i) + f->s->c_i;
		i++;
	}
	if (i == f->iter)
		return (0);
	return (get_color(i, f));
}
