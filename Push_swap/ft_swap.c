/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 20:43:00 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/17 18:38:19 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_sa(t_stack **a)
{
	t_stack		*tmp;

	if (!(*a) || !(*a)->next)
		exit(EXIT_FAILURE);
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	printf("sa\n");
}

void	ft_sb(t_stack **b)
{
	t_stack		*tmp;

	if (!(*b) || !(*b)->next)
		exit(EXIT_FAILURE);
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	printf("sb\n");
}

void	ft_ss(t_stack **a, t_stack **b)
{
	ft_sa(a);
	ft_sb(b);
	printf("ss\n");
}
