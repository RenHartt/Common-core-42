/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 21:46:07 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/07 12:22:42 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define W 900
# define H 900

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_fractol {
	void	*mlx;
	void	*mlx_win;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	zoom;
	int		iter;
	t_data	*m;
	int		av;
	int		leftclick;
	double	movex;
	double	movey;
}				t_fractol;

unsigned int	mandelbrot_julia(t_fractol f);
unsigned int	get_color(int i, t_fractol f);
double			map_fractal_x(double a, double minb, double maxb);
double			map_fractal_y(double a, double minb, double maxb);
double			map_color(double i, double max);
double			ft_atof(char *nbr);
double			lissage(int i, t_fractol f, int m);
int				ft_strcmp(char *s1, char *s2);
int				loop_hook(t_fractol *f);
void			print_fractal(t_fractol *f);
int				choose_fractal(char **av);
void			set_values(int x, int y, int choice, t_fractol *f);
int				mouse_hook(int button, int x, int y, t_fractol *f);
int				key_hook(int button, t_fractol *f);

#endif