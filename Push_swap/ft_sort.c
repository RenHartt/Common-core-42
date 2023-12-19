/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:45:30 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/19 19:28:17 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
				if ((*b)->nbr < median)
					ft_rb(b);
			}
			else
				ft_ra(a);
		}
	}
}

t_move	*current_move(t_stack *a, t_stack *b)
{
	static t_move	*move;
	int				dir;

	move = (t_move *)malloc(sizeof(t_move));
	move->costa = ft_cost_a(a, b->nbr, &dir);
	move->dira = dir;
	move->costb = ft_cost_b(b, &dir);
	move->dirb = dir;
	if (move->dira != move->dirb)
		move->cost = move->costa + move->costb;
	else
	{
		move->cost = move->costb;
		if (move->costa > move->costb)
			move->cost = move->costa;
	}
	return (move);
}

t_move	*ft_find_best_move(t_stack *a, t_stack *b)
{
	static t_move	*move;
	static t_move	*best_move;

	if (!best_move)
		best_move = malloc(sizeof(t_move));
	best_move->cost = 2147483647;
	while (b)
	{
		move = current_move(a, b);
		if (move->cost < best_move->cost)
			best_move = move;
		b = b->next;
	}
	return (best_move);
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

/*void	ft_b_to_a(t_stack **a, t_stack **b)
{
	t_move	*move;

	move = malloc(sizeof(t_move));
	while (*b)
	{
		move = ft_find_best_move((*a), (*b));
		if (move->dira)
		{
			while (move->costa--)
				ft_ra(a);
		}
		else
		{
			while (move->costa--)
				ft_rra(a);
		}
		if (move->dirb)
		{
			while (move->costb--)
				ft_rb(b);
		}
		else
		{
			while (move->costb--)
				ft_rrb(b);
		}
		ft_pa(a, b);
	}
	free(move);
}*/
