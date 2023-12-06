/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistegoron <baptistegoron@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 21:46:02 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/05 22:02:31 by baptistegor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(int ac, char **av)
{
	unsigned int	color;
	t_data			img;
	t_fractol		vars;
	int x;
	int y;

	(void)ac;
	(void)av;
	y = 0;
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, W, H, "Fract.ol");
	img.img = mlx_new_image(vars.mlx, W, H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			if (!ft_strcmp("mandelbrot", av[1]))
				color = mandelbrot(x, y);
			if (!ft_strcmp("julia", av[1]))
				color = julia(x, y, ft_atof(av[2]), ft_atof(av[3]));
			my_mlx_pixel_put(&img, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}