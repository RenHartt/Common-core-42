/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:59:56 by bgoron            #+#    #+#             */
/*   Updated: 2023/11/12 15:14:18 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int i = -56345;
	int j = 354;
	char c = 'X';
	char *s = "ZZZ";
	int *p = NULL;
	ft_printf("%c hel%%lo %s hel%lo %p hel%%lo %d hel%lo %i hel%%lo %u hel%lo %x hel%%lo %X", c, s, p, i, i, j, j, j);
}