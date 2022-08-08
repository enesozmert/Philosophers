/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:14:56 by eozmert           #+#    #+#             */
/*   Updated: 2022/08/04 22:56:49 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	init_state(t_state *state, char **av)
{
	state->id = 0;
	state->number_of_philosophers = ft_atoi(av[1]);
	state->time_to_die = ft_atoi(av[2]);
	state->time_to_eat = ft_atoi(av[3]);
	state->time_to_sleep = ft_atoi(av[4]);
	state->times_total_eat = 0;
	if (get_ac(av) > 5)
		state->times_total_eat = ft_atoi(av[5]);
	state->is_died = 0;
	state->meals = 0;
	state->forks = (pthread_mutex_t *)malloc
		(sizeof(pthread_mutex_t) * state->number_of_philosophers);
	pthread_mutex_init(&state->print_locker, NULL);
	return (1);
}

t_fork	*init_fork(t_philosopher *phi)
{
	int		i;
	t_fork	*fork;

	i = 0;
	fork = (t_fork *)malloc
		(sizeof(t_fork) * phi->state->number_of_philosophers);
	while (i < phi->state->number_of_philosophers)
	{
		fork[i].left = i;
		fork[i].right = i + 1;
		fork[i].is_left = 0;
		fork[i].is_right = 0;
		phi[i].fork = fork[i];
		i++;
	}
	i--;
	fork[i].right = 0;
	phi[i].fork = fork[i];
	return (fork);
}

t_philosopher	*init_philosophers(t_state *state)
{
	int				i;
	t_philosopher	*phi;

	i = 0;
	phi = malloc(sizeof(t_philosopher) * state->number_of_philosophers);
	while (i < state->number_of_philosophers)
	{
		phi[i].id = i + 1;
		phi[i].count_meals = 0;
		phi[i].time_left_meal = get_time();
		phi[i].state = state;
		pthread_mutex_init(&state->forks[i], NULL);
		pthread_mutex_init(&state->is_fork, NULL);
		i++;
	}
	return (phi);
}
