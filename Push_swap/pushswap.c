/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 20:33:34 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/17 19:55:30 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(void)
{
	int	tab[10] = {5, 2, 7, 1, 6, 3, 9, 4, 8};
	t_stack	*stacka;
	t_stack	*stackb;
	int		i;

	i = 0;
	stacka = ft_lstnew(tab[i + 1]);
	stackb = ft_lstnew(tab[i]);
	for (i = 1; i < 8; i++)
		ft_lstadd_back(stacka, tab[i + 1]);
	printf("stack a : ");
	ft_lstprint(stacka);
	printf("stack b : ");
	ft_lstprint(stackb);
	ft_sort(&stacka, &stackb);
	printf("stack a : ");
	ft_lstprint(stacka);
	printf("stack b : ");
	ft_lstprint(stackb);
	return (0);
}