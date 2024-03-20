/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptistegoron <baptistegoron@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:42:38 by baptistegor       #+#    #+#             */
/*   Updated: 2024/03/20 05:20:31 by baptistegor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int    check_fork(t_philo *philo)
{
    while (1)
    {
        pthread_mutex_lock(&philo->fork_left->pmt);
        if (philo->fork_left->used_fork == 0)
        {
            pthread_mutex_unlock(&philo->fork_left->pmt);
            break ;
        }
        pthread_mutex_lock(&philo->fork_right->pmt);
        if (philo->fork_right->used_fork == 0 && philo->fork_left->used_fork == 0)
        {
            pthread_mutex_unlock(&philo->fork_right->pmt);
            pthread_mutex_unlock(&philo->fork_left->pmt);
            break ;
        }
        pthread_mutex_unlock(&philo->fork_right->pmt);
        pthread_mutex_unlock(&philo->fork_left->pmt);
        usleep(100);
    }
    return (0);
}

void    *ft_thread(void *d)
{
    t_philo *philo;

    philo = (t_philo *)d;
    if (!philo->id % 2)
        usleep(1000);
    while (1)
    {
        if (check_fork(philo))
            break ;
        pthread_mutex_lock(&philo->fork_left->pmt);
        pthread_mutex_lock(&philo->fork_right->pmt);
        philo->fork_left->used_fork = 1;
        philo->fork_right->used_fork = 1;
        pthread_mutex_unlock(&philo->fork_right->pmt);
        pthread_mutex_unlock(&philo->fork_left->pmt);
        usleep(philo->data.time_to_eat * 1000);
        pthread_mutex_lock(&philo->fork_left->pmt);
        pthread_mutex_lock(&philo->fork_right->pmt);
        philo->fork_left->used_fork = 0;
        philo->fork_right->used_fork = 0;
        pthread_mutex_unlock(&philo->fork_right->pmt);
        pthread_mutex_unlock(&philo->fork_left->pmt);
        pthread_mutex_lock(philo->pmt);
        if (philo->id % 2)
            printf("\033[49;31;1;3m");
        else
            printf("\033[49;32;1;3m");
        printf("Philo[%d] : I eat.\033[0m\n", philo->id);
        pthread_mutex_unlock(philo->pmt);
        usleep(philo->data.time_to_sleep * 1000);
        pthread_mutex_lock(philo->pmt);
        printf("Philo[%d] : I sleep.\n", philo->id);
        pthread_mutex_unlock(philo->pmt);
        pthread_mutex_lock(philo->pmt);
        printf("Philo[%d] : I think.\n", philo->id);
        pthread_mutex_unlock(philo->pmt);
    }
    return (NULL);
}

int main(int ac, char **av)
{
    t_data          data;
    t_fork          *fork;
    t_philo         **philo;
    pthread_t       *thread;
    pthread_mutex_t pmt;
    int             i;
    (void)ac;

    if (ac != 2)
        return (EXIT_FAILURE);
    data = (t_data) {atoi(av[1]), 1000, 500, 500, 0};
    fork = malloc(sizeof(t_fork) * data.nbr_of_philo);
    philo = malloc(sizeof(t_philo *) * data.nbr_of_philo);
    thread = malloc(sizeof(pthread_t) * data.nbr_of_philo);
    memset((void *)&pmt, 0, sizeof(pthread_mutex_t));
    memset((void *)fork, 0, sizeof(t_fork));
    memset((void *)philo, 0, data.nbr_of_philo * sizeof(t_philo *));
    memset((void *)thread, 0, sizeof(pthread_t) * data.nbr_of_philo);
    i = -1;
    while (++i < data.nbr_of_philo)
    {
        philo[i] = malloc(sizeof(t_philo));
        philo[i]->data = data;
        philo[i]->pmt = &pmt;
        philo[i]->id = i;
        philo[i]->fork_left = &fork[(i + (i % 2)) % data.nbr_of_philo];
        philo[i]->fork_right = &fork[(i + 1 - (i % 2)) % data.nbr_of_philo];
        pthread_create(&thread[i], NULL, ft_thread, (void *)philo[i]);
    }
    i = -1;
    while (++i < data.nbr_of_philo)
        pthread_join(thread[i], NULL);
    return (EXIT_SUCCESS);
}