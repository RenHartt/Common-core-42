/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:42:00 by baptistegor       #+#    #+#             */
/*   Updated: 2024/03/22 13:55:11 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

# define FORK_MSG	BLUE"Philo[%d] has taken a fork.\n"RESET
# define EAT_MSG	GREEN"Philo[%d] is eating.\n"RESET
# define SLEEP_MSG	YELLOW"Philo[%d] is sleeping.\n"RESET
# define THINK_MSG	MAGENTA"Philo[%d] is thinking.\n"RESET
# define DEAD_MSG	RED"Philo[%d] died.\n"RESET

# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENTA	"\033[1;35m"
# define RESET		"\033[0m"

# define t_mutex	pthread_mutex_t

typedef struct s_args
{
	int	nb_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nb_must_eat;
}				t_args;

typedef struct s_philo
{
	t_mutex	*fork_left;
	t_mutex	*fork_right;
	t_mutex	*print;
	t_mutex	*last_meal;
	t_mutex	*death;
	int		int_last_meal;
	int		*int_death;
	int		id;
	t_args	*args;
}				t_philo;

typedef enum s_msg
{
	DEAD,
	EAT,
	SLEEP,
	THINK,
	FORK
}				t_msg;

#endif