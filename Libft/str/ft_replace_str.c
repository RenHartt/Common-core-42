/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:20:01 by bgoron            #+#    #+#             */
/*   Updated: 2024/02/26 17:26:27 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_replace_str(char *old, char *new)
{
	char	*tmp;

	tmp = ft_strdup(old);
	free(old);
	old = ft_strdup(new);
	free(new);
	free(tmp);
	return (old);
}
