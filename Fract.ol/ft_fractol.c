/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 21:46:02 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/11 17:30:41 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fract_ol.h"

int	main(int ac, char **av)
{
	t_fractol	*f;
	int			error;

	error = error_input(ac, av);
	if (!error)
	{
		f = init_fractol(ac, av, 100);
		print_fractal(f);
		mlx_on_event(f->mlx, f->win, 0, &key_hook, f);
		mlx_on_event(f->mlx, f->win, 2, &mouse_hook, f);
		mlx_on_event(f->mlx, f->win, 4, &wheel_hook, f);
		mlx_on_event(f->mlx, f->win, 5, &destroy, f);
		mlx_loop_hook(f->mlx, &loop_hook, f);
		mlx_loop(f->mlx);
	}
	return (0);
}
