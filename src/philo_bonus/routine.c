/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:23:52 by eozmert           #+#    #+#             */
/*   Updated: 2022/08/08 14:40:23 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header_bonus.h"

void	thinks(t_philosopher *phi)
{
	action_handler(phi, "thinks");
	return ;
}

void	sleeping(t_philosopher *phi)
{
	action_handler(phi, "sleeping");
	my_usleep(phi->state->time_to_sleep);
	return ;
}

void	eating(t_philosopher *phi)
{
	sem_wait(phi->state->forks);
	action_handler(phi, "taken left");
	get_fork_status_left(phi, 0);
	sem_wait(phi->state->forks);
	action_handler(phi, "taken right");
	get_fork_status_right(phi, 0);
	action_handler(phi, "eating");
	my_usleep(phi->state->time_to_eat);
	phi->time_left_meal = get_time();
	sem_post(phi->state->forks);
	action_handler(phi, "untaken left");
	get_fork_status_left(phi, 1);
	sem_post(phi->state->forks);
	action_handler(phi, "untaken right");
	get_fork_status_right(phi, 1);
	return ;
}

void	routine(void *arg)
{
	t_philosopher	*phi;

	phi = (t_philosopher *)arg;
	if ((phi->fork.is_left != 0 || phi->fork.is_right != 0))
		usleep(1000);
	pthread_create(&phi->state->state_thread, NULL, state_check, (void *)phi);
	while (phi->state->is_died != 1)
	{
		eating(phi);
		sleeping(phi);
		thinks(phi);
		phi->count_meals++;
		usleep(1000);
	}
	pthread_join(phi->state->state_thread, NULL);
	exit(1);
}
