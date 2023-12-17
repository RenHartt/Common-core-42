/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 22:01:42 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/17 18:38:35 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_ra(t_stack **a)
{
	t_stack		*tmp;
	t_stack		*tmp2;

	if (!(*a) || !(*a)->next)
		exit(EXIT_FAILURE);
	tmp = *a;
	tmp2 = *a;
	*a = (*a)->next;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->next = NULL;
	printf("ra\n");
}

void	ft_rb(t_stack **b)
{
	t_stack		*tmp;
	t_stack		*tmp2;

	if (!(*b) || !(*b)->next)
		exit(EXIT_FAILURE);
	tmp = *b;
	tmp2 = *b;
	*b = (*b)->next;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->next = NULL;
	printf("rb\n");
}

void	ft_rr(t_stack **a, t_stack **b)
{
	ft_ra(a);
	ft_rb(b);
	printf("rr\n");
}
