/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistegoron <baptistegoron@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:53:43 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/06 12:37:58 by baptistegor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map_fractal_x(double a, double minb, double maxb)
{
	return (minb + a * ((maxb - minb) / W));
}

double	map_fractal_y(double a, double minb, double maxb)
{
	return (minb + a * ((maxb - minb) / H));
}

double	map_color(double i, double max)
{
	return (i * 255 / max);
}

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);	
}

double ft_atof(char *nbr)
{
    double result;
    double fraction;
    int i;

	result = 0.0;
    fraction = 1.0;
    i = 0;
    if (nbr[i] == '-') 
		i++;
    while (nbr[i] >= '0' && nbr[i] <= '9')
        result = result * 10.0 + (nbr[i++] - '0');
    if (nbr[i++] == '.') 
        while (nbr[i] >= '0' && nbr[i] <= '9')
        {
            fraction *= 0.1;
            result = result + (nbr[i++] - '0') * fraction;
        }
    if (nbr[0] == '-')
		return (result * -1);
    return (result);
}

double    lissage(int i, t_fractol *f, int m)
{
    return (1 +  i - log((log(f->z_r * f->z_r + f->z_i * f->z_i))/ log(m) ) / log(2));
}

unsigned int    get_color(int i, t_fractol *f)
{
    unsigned int	color;

    color = 0xFF753BBD;
    color += ((unsigned int)(lissage(i, f, 1000)) + sin(2 * 3.14 / i) * 127 + 128);
    color += ((unsigned int)lissage(i, f, 1000) << 8);
    color += (((unsigned int)lissage(i, f, 25)));
    return (color);
}

int    mouse_hook(int button, int x, int y, t_fractol *f)
{
    (void) f;
    if (button == 1)
    {
        f->c_r = map_fractal_x((double)x, -2, 2);
        f->c_i = map_fractal_y((double)y, -2, 2);
        printf("%d %d\n", x, y);
    }
    if (button == 2)
        printf("clic molette\n");
    if (button == 3)
        printf("clic droit\n");
    if (button == 4)
        printf("scroll up\n");
    if (button == 5)
        printf("scroll down\n");
    return (0);
}