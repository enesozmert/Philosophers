/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:22:28 by eozmert           #+#    #+#             */
/*   Updated: 2022/08/08 14:44:33 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header_bonus.h"

void	start(t_philosopher *phi)
{
	int	i;
	int	num;

	i = 0;
	num = phi[i].state->number_of_philosophers;
	phi->state->start_time = get_time();
	while (i < num)
	{
		phi[i].child_process = fork();
		if (phi[i].child_process < 0)
			exit(printf("error child process\n"));
		if (phi[i].child_process == 0)
			routine(&phi[i]);
		usleep(100);
		i++;
	}
	usleep(1000);
	pthread_create(&phi->kill_thread, NULL, is_kill, (void *)phi);
	pthread_join(phi->kill_thread, NULL);
}

void	*state_check(void *arg)
{
	t_philosopher	*phi;

	phi = (t_philosopher *)arg;
	while (!check_meals(phi))
	{
		if (is_died(*phi) == 1)
		{
			action_handler(phi, "died");
			phi->state->is_died = 1;
			exit(1);
		}
		usleep(100);
	}
	return (NULL);
}

void	*is_kill(void *arg)
{
	int				idx;
	int				res;
	t_philosopher	*phi;

	idx = -1;
	phi = (t_philosopher *)arg;
	while (1)
	{
		waitpid(-1, &res, 0);
		if (res != 0)
		{
			while (++idx < phi->state->number_of_philosophers)
				kill(phi[idx].child_process, SIGKILL);
			break ;
		}
		usleep(100);
	}
	return (NULL);
}

void	end(t_philosopher *phi, t_fork *fork)
{
	sem_close(phi->state->forks);
	sem_close(phi->state->is_fork);
	sem_unlink("./forks");
	sem_unlink("./is_fork");
	pthread_mutex_destroy(&phi->state->print_locker);
	free(fork);
}
