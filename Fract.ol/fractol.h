/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistegoron <baptistegoron@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 21:46:07 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/06 12:32:35 by baptistegor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx_macos/mlx.h"
# include <math.h>
# include <stdio.h>

# define W 900
# define H 900

typedef struct	s_fractol {
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
    void			*mlx;
	void			*mlx_win;
}				t_fractol;

unsigned int	mandelbrot(int x, int y);
unsigned int	julia(int x, int y, double c_r, double c_i);
double			map_fractal_x(double a, double minb, double maxb);
double			map_fractal_y(double a, double minb, double maxb);
double			map_color(double i, double max);
int             ft_strcmp(char *s1, char *s2);
double          ft_atof(char *nbr);
double          lissage(int i, t_fractol *f, int m);
unsigned int    get_color(int i, t_fractol *f);
int				mouse_hook(int button, int x, int y, t_fractol *f);

#endif