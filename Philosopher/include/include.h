/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistegoron <baptistegoron@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:42:00 by baptistegor       #+#    #+#             */
/*   Updated: 2024/03/20 04:16:53 by baptistegor      ###   ########.fr       */
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

typedef struct s_data
{
    int     nbr_of_philo;
    int     time_to_die;
    int     time_to_eat;
    int     time_to_sleep;
    int     nbr_of_time_each_philo_must_eat;
}           t_data;

typedef struct s_fork
{
    pthread_mutex_t pmt;
    int             used_fork;
}               t_fork;

typedef struct s_philo
{
    int             id;
    t_data          data;
    pthread_mutex_t *pmt;
    t_fork          *fork_left;
    t_fork          *fork_right;
}               t_philo;



#endif