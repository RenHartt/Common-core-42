/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:45:30 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/11 16:26:30 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_nbr_byte(int nbr)
{
	int	byte;

	byte = 31;
	while (!((nbr >> byte) & 1) && (byte >= 0))
		byte--;
	return (byte);
}

void	ft_sort_big(t_stack **a, t_stack **b)
{
	int	lst_size;
	int	byte;

	lst_size = 0;
	byte = 0;
	while (byte <= ft_nbr_byte(ft_lstfind_max(*a)))
	{
		lst_size = ft_lstsize(*a);
		while (lst_size--)
		{
			if (((*a)->nbr >> byte) & 1)
				ft_ra(a);
			else
				ft_pb(a, b);
		}
		while (*b)
			ft_pa(a, b);
		byte++;
	}
}
