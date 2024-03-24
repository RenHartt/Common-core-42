/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:55:06 by bgoron            #+#    #+#             */
/*   Updated: 2024/03/16 16:56:02 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

extern int	g_exit_code;

void	prompt_error(char *error, int error_code)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putendl_fd(error, STDERR_FILENO);
	g_exit_code = error_code;
}
