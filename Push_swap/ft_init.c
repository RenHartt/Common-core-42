/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:11:23 by bgoron            #+#    #+#             */
/*   Updated: 2023/12/18 13:33:40 by bgoron           ###   ########.fr       */
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
	t_stack	*current;

	new = malloc(sizeof(t_stack));
	if (!new || !list)
		exit(EXIT_FAILURE);
	new->nbr = nbr;
	new->next = NULL;
	current = list;
	while (current->next)
		current = current->next;
	current->next = new;
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

void	ft_lstprint(t_stack *list)
{
	t_stack	*current;

	current = list;
	while (current)
	{
		printf("%d", current->nbr);
		if (current->next)
			printf(" -> ");
		current = current->next;
	}
	printf("\n");
}
