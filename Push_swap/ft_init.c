/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:11:23 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/03 15:25:23 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*ft_lstnew(int nbr)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nbr = nbr;
	new->next = NULL;
	return (new);
}


void	ft_lstadd_back(t_stack *list, int nbr)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new || !list)
		exit(EXIT_FAILURE);
	new->nbr = nbr;
	new->next = NULL;
	while (list->next)
		list = list->next;
	list->next = new;
}

void	ft_lstadd_front(t_stack *list, int nbr)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new || !list)
		exit(EXIT_FAILURE);
	new->nbr = nbr;
	new->next = list;
	list = new;
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
	free(list);
}
