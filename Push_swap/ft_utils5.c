/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:04:03 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/08 15:38:39 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_find_index(t_stack *a, int nbr)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->nbr == nbr)
			return (i);
		a = a->next;
		i++;
	}
	return (0);
}

int	ft_find_final_index(t_stack *a, int nbr)
{
	int	i;

	i = 1;
	while (a)
	{
		if (a->nbr < nbr)
			i++;
		a = a->next;
	}
	return (i);
}

t_stack	*ft_lst_cpy(t_stack *a)
{
	t_stack	*cpy;

	cpy = NULL;
	while (a)
	{
		ft_lstadd_back(&cpy, a->nbr);
		a = a->next;
	}
	return (cpy);
}

void	ft_set_nbr_to_index(t_stack *a)
{
	t_stack	*tmp;

	tmp = ft_lst_cpy(a);
	while (a)
	{
		a->nbr = ft_find_final_index(tmp, a->nbr);
		a = a->next;
	}
	ft_lstfree(tmp);
}
