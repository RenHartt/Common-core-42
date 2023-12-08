/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fract_ol.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 21:46:07 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/08 03:40:29 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACT_OL_H
# define FT_FRACT_OL_H

# include "minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define W 960
# define H 965

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_fractol {
	t_data	*m;
	void	*mlx;
	void	*mlx_win;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	movex;
	double	movey;
	double	zoom;
	int		leftclick;
	int		iter;
	int		av;
}				t_fractol;

t_fractol		*init_fractol(int ac, char **av, int iter);
unsigned int	mandelbrot_julia(t_fractol *f);
unsigned int	burning_ship(t_fractol *f);
unsigned int	get_color(int i, t_fractol *f);
double			map_fractal_x(double a, double minb, double maxb);
double			map_fractal_y(double a, double minb, double maxb);
double			map_color(double i, double max);
double			lissage(int i, t_fractol *f, int m);
double			ft_atof(char *nbr);
void			set_values(int x, int y, int choice, t_fractol *f);
void			print_fractal(t_fractol *f);
void			*ft_calloc(size_t nmemb, size_t size);
void			error_input(void);
int				mouse_hook(int button, int x, int y, t_fractol *f);
int				key_hook(int button, t_fractol *f);
int				loop_hook(t_fractol *f);
int				ft_strcmp(char *s1, char *s2);
int				choose_fractal(char **av);
int				destroy(t_fractol *f);

#endif