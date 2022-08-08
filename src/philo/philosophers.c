/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:22:28 by eozmert           #+#    #+#             */
/*   Updated: 2022/08/04 20:14:36 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void	start(t_philosopher *phi)
{
	int	i;
	int	num;

	i = 0;
	num = phi[i].state->number_of_philosophers;
	phi->state->start_time = get_time();
	while (i < num)
	{
		pthread_create(&phi[i].phi_thread, NULL, routine, &phi[i]);
		usleep(100);
		i++;
	}
	usleep(1000);
	pthread_create(&phi->state_thread, NULL, state_check, (void *)phi);
	i = 0;
	while (i < num)
	{
		pthread_join(phi[i].phi_thread, NULL);
		usleep(100);
		i++;
	}
	pthread_join(phi->state_thread, NULL);
}

void	*state_check(void *arg)
{
	int				i;
	t_philosopher	*phi;

	phi = (t_philosopher *)arg;
	i = 0;
	while (!check_meals(phi))
	{
		if (phi[i].state->is_died == 1)
			return (NULL);
		while (i < phi->state->number_of_philosophers)
		{
			if (is_died(phi[i]) == 1)
			{
				action_handler(&phi[i], "died");
				phi[i].state->is_died = 1;
				return (NULL);
			}
			i++;
		}
		i = 0;
		usleep(10);
	}
	return (NULL);
}

void	end(t_philosopher *phi, t_fork *fork)
{
	int	i;

	i = 0;
	while (i < phi->state->number_of_philosophers)
	{
		pthread_mutex_destroy(&phi->state->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&phi->state->print_locker);
	pthread_mutex_destroy(&phi->state->is_fork);
	free(phi->state->forks);
	free(fork);
	free(phi);
}
