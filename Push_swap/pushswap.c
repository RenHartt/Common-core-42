/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 20:33:34 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/06 22:04:49 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_sort_two(t_stack **a)
{
	if ((*a)->nbr > (*a)->next->nbr)
		ft_sa(a);
}

void	ft_sort_choice(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) == 1)
		return ;
	else if (ft_lstsize(*a) == 2)
		ft_sort_two(a);
	else if (ft_lstsize(*a) == 3)
		ft_sort_three(a);
	else
		ft_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*tab;
	int		i;

	i = 1;
	b = NULL;
	tab = NULL;
	if (argc == 2)
		tab = ft_one_arg(argv);
	else if (argc > 2)
		tab = ft_many_arg(argc, argv);
	else
		return (0);
	a = ft_lstnew(tab[0]);
	while (tab[i])
		ft_lstadd_back(a, tab[i++]);
	ft_set_nbr_to_index(a);
	ft_sort_choice(&a, &b);
	ft_lstfree(a);
	free(tab);
	return (0);
}
