/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_and_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 22:04:48 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/09 18:44:50 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_rra(t_stack **a)
{
	t_stack		*tmp;
	t_stack		*tmp2;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = *a;
	tmp2 = *a;
	while (tmp->next)
		tmp = tmp->next;
	while (tmp2->next->next)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	tmp->next = *a;
	*a = tmp;
	ft_putstr("rra\n");
}

void	ft_rrb(t_stack **b)
{
	t_stack		*tmp;
	t_stack		*tmp2;

	if (!(*b) || !(*b)->next)
		return ;
	tmp = *b;
	tmp2 = *b;
	while (tmp->next)
		tmp = tmp->next;
	while (tmp2->next->next)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	tmp->next = *b;
	*b = tmp;
	ft_putstr("rrb\n");
}

void	ft_ra(t_stack **a)
{
	t_stack		*tmp;
	t_stack		*tmp2;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = *a;
	tmp2 = *a;
	*a = (*a)->next;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->next = NULL;
	ft_putstr("ra\n");
}

void	ft_rb(t_stack **b)
{
	t_stack		*tmp;
	t_stack		*tmp2;

	if (!(*b) || !(*b)->next)
		return ;
	tmp = *b;
	tmp2 = *b;
	*b = (*b)->next;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->next = NULL;
	ft_putstr("rb\n");
}
