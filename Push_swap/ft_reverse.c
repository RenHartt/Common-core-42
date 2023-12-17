/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 22:04:48 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/17 18:37:46 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_rra(t_stack **a)
{
	t_stack		*tmp;
	t_stack		*tmp2;

	if (!(*a) || !(*a)->next)
		exit(EXIT_FAILURE);
	tmp = *a;
	tmp2 = *a;
	while (tmp->next)
		tmp = tmp->next;
	while (tmp2->next->next)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	tmp->next = *a;
	*a = tmp;
	printf("rra\n");
}

void	ft_rrb(t_stack **b)
{
	t_stack		*tmp;
	t_stack		*tmp2;

	if (!(*b) || !(*b)->next)
		exit(EXIT_FAILURE);
	tmp = *b;
	tmp2 = *b;
	while (tmp->next)
		tmp = tmp->next;
	while (tmp2->next->next)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	tmp->next = *b;
	*b = tmp;
	printf("rrb\n");
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_rra(a);
	ft_rrb(b);
	printf("rrr\n");
}
