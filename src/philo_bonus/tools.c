/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:34:33 by eozmert           #+#    #+#             */
/*   Updated: 2022/08/08 11:43:18 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header_bonus.h"

int	get_ac(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

void	get_fork_status_left(t_philosopher *phi, int status)
{
	sem_wait(phi->state->is_fork);
	phi->fork.is_left = status;
	usleep(1);
	sem_post(phi->state->is_fork);
}

void	get_fork_status_right(t_philosopher *phi, int status)
{
	sem_wait(phi->state->is_fork);
	phi->fork.is_right = status;
	usleep(1);
	sem_post(phi->state->is_fork);
}

void	is_one_phi(t_philosopher *phi)
{
	if (phi->state->number_of_philosophers > 1)
		return ;
	sem_wait(&phi->state->forks[phi->fork.left]);
	action_handler(phi, "taken left");
	sem_post(&phi->state->forks[phi->fork.left]);
	action_handler(phi, "died");
	phi->state->is_died = 1;
	return ;
}

void	my_usleep(long u_time)
{
	int		i;
	long	now_get_time;

	i = 0;
	now_get_time = get_time();
	usleep(u_time * 927);
	while (get_time() < now_get_time + u_time)
		usleep(u_time * 3);
}
