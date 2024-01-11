/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:11:23 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/11 18:12:24 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_lstadd_back(t_stack **list, int nbr)
{
	t_stack	*new;
	t_stack	*tmp;

	new = ft_calloc(sizeof(t_stack), 1);
	if (!new)
		return ;
	new->nbr = nbr;
	new->next = NULL;
	if (!(*list))
	{
		*list = new;
		return ;
	}
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	ft_lstfree(t_stack *list)
{
	t_stack	*current;
	t_stack	*tmp;

	current = list;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
}
