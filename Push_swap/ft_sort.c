/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:45:30 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/06 21:53:19 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_sort_three(t_stack **a)
{
	int	i;
	int	j;
	int	k;

	i = (*a)->nbr;
	j = (*a)->next->nbr;
	k = (*a)->next->next->nbr;
	if (i == 1 && j == 3 && k == 2)
	{
		ft_rra(a);
		ft_sa(a);
	}
	else if (i == 3 && j == 2 && k == 1)
	{
		ft_sa(a);
		ft_rra(a);
	}
	else if (i == 2 && j == 1 && k == 3)
		ft_sa(a);
	else if (i == 2 && j == 3 && k == 1)
		ft_rra(a);
	else if (i == 3 && j == 1 && k == 2)
		ft_ra(a);
	else
		return ;
}

void	ft_a_to_b(t_stack **a, t_stack **b)
{
	int	min;
	int	max;
	int	median;

	while (*a)
	{
		min = ft_lstsize(*a) / 2;
		max = ft_lstsize(*a);
		median = ((max - min) / 2) + min;
		while (ft_lstsize(*a) > min)
		{
			if ((*a)->nbr > min)
			{
				ft_pb(a, b);
				if (((*b)->nbr < median) && (ft_lstsize(*b) > 1))
					ft_rb(b);
			}
			else
				ft_ra(a);
		}
	}
}

void	ft_b_to_a(t_stack **a, t_stack **b)
{
	while (*b)
	{
		if (ft_find_index(*b, ft_lstfind_max(*b)) > ft_lstsize(*b) / 2)
		{
			while ((*b)->nbr != ft_lstfind_max(*b))
				ft_rrb(b);
			ft_pa(a, b);
		}
		else
		{
			while ((*b)->nbr != ft_lstfind_max(*b))
				ft_rb(b);
			ft_pa(a, b);
		}
	}
}

void	ft_sort(t_stack **a, t_stack **b)
{
	ft_a_to_b(a, b);
	ft_b_to_a(a, b);
}