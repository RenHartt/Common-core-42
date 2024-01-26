/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:13:29 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/26 21:27:34 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_usage(void)
{
	ft_putstr_fd("Usage: ./pipex infile cmd ... cmd outfile\n", 2);
	ft_putstr_fd("or\n", 2);
	ft_putstr_fd("Usage: ./pipex here_doc LIMITER cmd ... cmd outfile\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_usage_here_doc(void)
{
	ft_putstr_fd("Usage: ./pipex here_doc LIMITER cmd ... cmd outfile\n", 2);
	exit(EXIT_FAILURE);
}
