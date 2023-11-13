/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:12:25 by bgoron            #+#    #+#             */
/*   Updated: 2023/11/13 16:38:23 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int			ft_printf(const char *type, ...);
int			ft_putchar(char c);
int			ft_putnbr_base(long long nb, char *base);
int			ft_putstr(char *s);
unsigned long long	ft_strlen(char *s);
int			ft_sort(va_list	*args, char *str, size_t i);
int			ft_isinset(char c,char *set);
int			ft_putnbr(int nb);
long long	ft_pointer(long long unsigned nb,char *base);

#endif
