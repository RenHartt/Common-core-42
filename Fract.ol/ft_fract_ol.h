/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fract_ol.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 21:46:07 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/10 19:30:33 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define W 900
# define H 900
# define WUP 1
# define WDOWN 2
# define UP 82
# define DOWN 81
# define LEFT 79
# define RIGHT 80
# define ITERP 87
# define ITERM 86
# define PIXELP 46
# define PIXELM 45
# define PIXELR 21
# define ESCAP 41

typedef struct s_fractol {
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
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
	int		color;
	int		red;
	int		green;
	int		blue;
	int		pixel;
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
int				error_input(int ac, char **av);
int				mouse_hook(int keycode, void *fu);
int				key_hook(int keycode, void *fu);
int				wheel_hook(int keycode, void *fu);
int				loop_hook(void *fu);
int				ft_strcmp(char *s1, char *s2);
int				choose_fractal(char **av);
int				destroy(int keycode, void *fu);

#endif