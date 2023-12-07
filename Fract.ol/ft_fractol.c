/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 21:46:02 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/07 23:06:10 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractol	*f;

	f = init_fractol(ac, av, 50);
	if (ac >= 2)
	{
		print_fractal(f);
		mlx_key_hook(f->mlx_win, key_hook, f);
		mlx_mouse_hook(f->mlx_win, mouse_hook, f);
		mlx_loop_hook(f->mlx, loop_hook, f);
		mlx_hook(f->mlx_win, 17, (1L<<5), destroy, f);
		mlx_loop(f->mlx);
	}
	return (0);
}
