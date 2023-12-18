/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 22:00:40 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/18 12:16:59 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_pa(t_stack **a, t_stack **b)
{
	t_stack		*tmp;

	if (!(*b))
		exit(EXIT_FAILURE);
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	printf("pa\n");
}

void	ft_pb(t_stack **a, t_stack **b)
{
	t_stack		*tmp;

	if (!(*a))
		exit(EXIT_FAILURE);
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	printf("pb\n");
}
