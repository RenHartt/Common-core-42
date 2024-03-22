/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:42:38 by baptistegor       #+#    #+#             */
/*   Updated: 2024/03/22 14:07:46 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"


int	get_time(void)
{
	static int		start_time = 0;
	struct timeval	time;

	gettimeofday(&time, NULL);
	if (!start_time)
		start_time = time.tv_sec * 1000 + time.tv_usec / 1000;
	return ((time.tv_sec * 1000 + time.tv_usec / 1000) - start_time);
}

void	my_sleep(int time_to_sleep)
{
	int	start_time;

	start_time = get_time();
	while (get_time() - start_time < time_to_sleep)
		usleep(100);
}

void	print_msg(t_msg msg, int id, t_philo *philo)
{
	static int i = 0;

	pthread_mutex_lock(philo->print);
	if (!i)
	{
		printf("%d ", get_time());
		if (msg == DEAD && !i++)
			printf(DEAD_MSG, id + 1);
		else if (msg == EAT && !i)
			printf(EAT_MSG, id + 1);
		else if (msg == SLEEP && !i)
			printf(SLEEP_MSG, id + 1);
		else if (msg == THINK && !i)
			printf(THINK_MSG, id + 1);
		else if (msg == FORK && !i)
			printf(FORK_MSG, id + 1);	
	}
	pthread_mutex_unlock(philo->print);
}

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->last_meal);
	if (get_time() - philo->int_last_meal >= philo->args->time_to_die)
	{
		pthread_mutex_unlock(philo->last_meal);
		pthread_mutex_lock(philo->death);
		*philo->int_death = 1;
		pthread_mutex_unlock(philo->death);
		print_msg(DEAD, philo->id, philo);
		return (1);
	}
	pthread_mutex_unlock(philo->last_meal);
	return (0);
}

void	*cycle(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2)
		usleep(100);
	while (1)
	{
		pthread_mutex_lock(philo->fork_left);
		print_msg(FORK, philo->id, philo);
		
		pthread_mutex_lock(philo->fork_right);
		print_msg(FORK, philo->id, philo);
		
		pthread_mutex_lock(philo->last_meal);
		philo->int_last_meal = get_time();
		pthread_mutex_unlock(philo->last_meal);
		
		print_msg(EAT, philo->id, philo);
		my_sleep(philo->args->time_to_eat);
		
		pthread_mutex_unlock(philo->fork_right);
		pthread_mutex_unlock(philo->fork_left);
		
		print_msg(SLEEP, philo->id, philo);
		my_sleep(philo->args->time_to_sleep);
		
		print_msg(THINK, philo->id, philo);
		pthread_mutex_lock(philo->death);
		
		if (*philo->int_death)
		{
			pthread_mutex_unlock(philo->death);
			break ;
		}
		pthread_mutex_unlock(philo->death);
	}
	return (NULL);
}

int main(int ac, char **av)
{
	t_args		args;
	t_philo		**philo;
	pthread_t	*thread;
	t_mutex		print;
	t_mutex		death;
	t_mutex		*forks;
	t_mutex		last_meal;
	int			int_death;
	int			i;

	if (ac == 5)
		args = (t_args){atoi(av[1]), atoi(av[2]), atoi(av[3]), atoi(av[4]), 100};
	else if (ac == 6)
		args = (t_args){atoi(av[1]), atoi(av[2]), atoi(av[3]), atoi(av[4]), atoi(av[5])};
	else
		return (EXIT_FAILURE);
	philo = malloc(sizeof(t_philo *) * args.nb_philo);
	thread = malloc(sizeof(pthread_t) * args.nb_philo);
	forks = malloc(sizeof(t_mutex) * args.nb_philo);
	memset((void *)philo, 0, sizeof(t_philo *) * args.nb_philo);
	memset((void *)thread, 0, sizeof(pthread_t) * args.nb_philo);
	memset((void *)&print, 0, sizeof(t_mutex));
	memset((void *)&death, 0, sizeof(t_mutex));
	memset((void *)forks, 0, sizeof(t_mutex) * args.nb_philo);
	memset((void *)&last_meal, 0, sizeof(t_mutex));
	int_death = 0;
	i = -1;
	while (++i < args.nb_philo)
	{
		philo[i] = malloc(sizeof(t_philo));
		philo[i]->last_meal = &last_meal;
		philo[i]->id = i;
		philo[i]->args = &args;
		philo[i]->death = &death;
		philo[i]->int_death = &int_death;
		if (i < args.nb_philo - 1)
		{
			philo[i]->fork_left = &forks[i];
			philo[i]->fork_right = &forks[(i + 1) % args.nb_philo];
		}
		else
		{
			philo[i]->fork_right = &forks[i];
			philo[i]->fork_left = &forks[(i + 1) % args.nb_philo];
		}
		philo[i]->print = &print;
		pthread_create(&thread[i], NULL, cycle, philo[i]);
	}
	while (1)
	{
		i = -1;
		while (++i < args.nb_philo)
		{
			if (is_dead(philo[i]))
				break ;
		}
		if (*philo[0]->int_death)
			break ; 
	}
	i = -1;
	while (++i < args.nb_philo)
		pthread_join(thread[i], NULL);
	i = -1;
	while (++i < args.nb_philo)
		free(philo[i]);
	free(philo);
	free(thread);
	free(forks);
	return (0);
}
