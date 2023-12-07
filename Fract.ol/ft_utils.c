/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:53:43 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/07 19:02:39 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i])
		i++;
	return (s1[i] - s2[i]);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;
	size_t	i;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if (nmemb * size / size != nmemb)
		return (NULL);
	tab = malloc (nmemb * size);
	if (tab == NULL)
		return (NULL);
	while (i < size * nmemb)
	{
		*(unsigned char *)(tab + i) = '\0';
		i++;
	}
	return (tab);
}

double	ft_atof(char *nbr)
{
	double	result;
	double	fraction;
	int		i;

	result = 0.0;
	fraction = 1.0;
	i = 0;
	if (nbr[i] == '-')
		i++;
	while (nbr[i] >= '0' && nbr[i] <= '9')
	{
		result *= 10.0 + (nbr[i] - '0');
		i++;
	}
	if (nbr[i++] == '.')
		while (nbr[i] >= '0' && nbr[i] <= '9')
		{
			fraction *= 0.1;
			result += (nbr[i] - '0') * fraction;
			i++;
		}
	if (nbr[0] == '-')
		return (result * -1);
	return (result);
}

int	destroy(t_fractol *f)
{
	mlx_clear_window(f->mlx, f->mlx_win);
	mlx_destroy_image(f->mlx, f->m->img);
	mlx_destroy_window(f->mlx, f->mlx_win);
	mlx_destroy_display(f->mlx);
	mlx_loop_end(f->mlx);
	free(f->m);
	free(f->mlx);
	free(f);
	exit(EXIT_SUCCESS);
	return (0);
}

t_fractol	*init_fractol(int ac, char **av, int iter)
{
	t_fractol	*new;
	
	new = ft_calloc(1, sizeof(t_fractol));
	new->m = ft_calloc(1, sizeof(t_data));
	new->zoom = 1;
	new->av = choose_fractal(av);
	set_values(0, 0, new->av, new);
	if (ac >= 2)
	{
		new->mlx = mlx_init();
		new->mlx_win = mlx_new_window(new->mlx, W, H, "Fract.ol");
		new->m->img = mlx_new_image(new->mlx, W, H);
		new->m->addr = mlx_get_data_addr \
		(new->m->img, &new->m->bits_per_pixel, &new->m->line_length, &new->m->endian);
		if (ac == 4)
		{
			new->c_r = ft_atof(av[2]);
			new->c_i = ft_atof(av[3]);
		}
	}
	new->leftclick = 0;
	new->iter = iter;
	return (new);
}