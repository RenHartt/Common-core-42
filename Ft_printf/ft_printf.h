/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:12:25 by bgoron            #+#    #+#             */
/*   Updated: 2023/11/11 17:35:01 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *type, ...);
void	ft_putchar(char c);
void	ft_putnbr_base(long long nb, char *base);
void	ft_putstr(char *s);
int		ft_strlen(const char *s);
void	ft_sort(va_list	*args, char *str, size_t i);

#endif
