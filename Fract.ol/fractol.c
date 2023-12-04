/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 21:46:02 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/04 16:01:49 by bgoron           ###   ########.fr       */
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

int main(void)
{
	unsigned int	color;
	void			*mlx;
	void			*mlx_win;
	t_data			img;
	int x;
	int y;
	double c_var;
	
	y = 0;
	c_var = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, W, H, "Fract.ol");
	img.img = mlx_new_image(mlx, W, H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	

	while (1)
	{
		c_var += 0.005; // only Julia
		y = 0;
		while (y < H)
		{
			x = 0;
			while (x < W)
			{
				color = mandelbrot(x, y);
				my_mlx_pixel_put(&img, x, y, color);
				x++;
			}
			y++;
		}
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	}
	mlx_loop(mlx);
}