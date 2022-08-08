/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:23:52 by eozmert           #+#    #+#             */
/*   Updated: 2022/08/04 16:28:12 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

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
	pthread_mutex_lock(&phi->state->forks[phi->fork.left]);
	action_handler(phi, "taken left");
	get_fork_status_left(phi, 0);
	pthread_mutex_lock(&phi->state->forks[phi->fork.right]);
	action_handler(phi, "taken right");
	get_fork_status_right(phi, 0);
	action_handler(phi, "eating");
	my_usleep(phi->state->time_to_eat);
	phi->time_left_meal = get_time();
	pthread_mutex_unlock(&phi->state->forks[phi->fork.left]);
	action_handler(phi, "untaken left");
	get_fork_status_left(phi, 1);
	pthread_mutex_unlock(&phi->state->forks[phi->fork.right]);
	action_handler(phi, "untaken right");
	get_fork_status_right(phi, 1);
	return ;
}

void	*routine(void *arg)
{
	t_philosopher	*phi;

	phi = (t_philosopher *)arg;
	if ((phi->fork.is_left != 0 || phi->fork.is_right != 0))
		usleep(1000);
	while (phi->state->is_died != 1)
	{
		eating(phi);
		sleeping(phi);
		thinks(phi);
		phi->count_meals++;
		usleep(10);
	}
	return (NULL);
}
