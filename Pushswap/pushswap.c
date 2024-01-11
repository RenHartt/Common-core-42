/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 20:33:34 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/11 15:08:58 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_sort_choice(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) == 1)
		return ;
	else if (ft_lstsize(*a) == 2)
		ft_sort_two(a);
	else if (ft_lstsize(*a) == 3)
		ft_sort_three(a);
	else if (ft_lstsize(*a) >= 350)
		ft_sort_big(a, b);
	else
		ft_sort_small(a, b);
}

int	ft_is_sorted(t_stack *a)
{
	while (a->next)
	{
		if (a->nbr > a->next->nbr)
			return (0);
		a = a->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	if (argc <= 1)
		return (0);
	i = 1;
	b = NULL;
	a = ft_args(argv);
	if (!a || ft_is_sorted(a))
	{
		ft_lstfree(a);
		return (0);
	}
	ft_set_nbr_to_index(a);
	ft_sort_choice(&a, &b);
	ft_lstfree(a);
	return (0);
}
