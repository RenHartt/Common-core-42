/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fract_ol.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 21:46:07 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/11 17:00:08 by bgoron           ###   ########.fr       */
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

typedef struct s_color {
	int		color;
	int		red1;
	int		green1;
	int		blue1;
	int		red2;
	int		green2;
	int		blue2;
}				t_color;

typedef struct s_set {
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	int		av;
}				t_set;

typedef struct s_move {
	double	zoom;
	double	movex;
	double	movey;
	int		pixel;
}				t_move;

typedef struct s_fractol {
	t_color	*c;
	t_set	*s;
	t_move	*m;
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
	int		leftclick;
	int		iter;
}				t_fractol;

int				choose_fractal(char **av);
t_fractol		*init_fractol(int ac, char **av, int iter);
void			set_values(int x, int y, int choice, t_fractol *f);

unsigned int	burning_ship(t_fractol *f);
unsigned int	mandelbrot_julia(t_fractol *f);
unsigned int	get_color(int i, t_fractol *f);

double			map_fractal_x(double a, double minb, double maxb);
double			map_fractal_y(double a, double minb, double maxb);
double			map_color(int i, int max, double minb, double maxb);

void			print_fractal(t_fractol *f);

int				loop_hook(void *fu);
int				key_hook(int keycode, void *fu);
int				mouse_hook(int keycode, void *fu);
int				wheel_hook(int keycode, void *fu);

int				error_input(int ac, char **av);
int				destroy(int keycode, void *fu);

double			ft_atof(char *nbr);
int				ft_strcmp(char *s1, char *s2);
void			*ft_calloc(size_t nmemb, size_t size);

#endif