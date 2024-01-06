/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:02:41 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/06 19:03:11 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

void	ft_print_tab(int *tab)
{
	int	i;

	i = 0;
	while (tab[i])
		printf("%d ", tab[i++]);
	printf("\n");
}

void	ft_print_list(t_stack *a)
{
	while (a)
	{
		ft_putnbr(a->nbr);
		ft_putstr(" ");
		a = a->next;
	}
	ft_putstr("\n");
}
