/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:52:13 by eozmert           #+#    #+#             */
/*   Updated: 2022/08/04 14:53:06 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void	print_action_main(t_philosopher *phi, char *action)
{
	long	current_time;

	current_time = get_time() - phi->state->start_time;
	pthread_mutex_lock(&phi->state->print_locker);
	if (!phi->state->is_died)
		printf("stamp-time : %5ld ph-id[%d] => ph-action[%s]\n",
			current_time, phi->id, action);
	pthread_mutex_unlock(&phi->state->print_locker);
}

void	print_action_left(t_philosopher *phi, char *action)
{
	long	current_time;

	current_time = get_time() - phi->state->start_time;
	pthread_mutex_lock(&phi->state->print_locker);
	if (!phi->state->is_died)
		printf("stamp-time : %5ld ph-id[%d] => ph-action[%s] fork-left[%d]\n",
			current_time, phi->id, action, phi->fork.left);
	pthread_mutex_unlock(&phi->state->print_locker);
}

void	print_action_right(t_philosopher *phi, char *action)
{
	long	current_time;

	current_time = get_time() - phi->state->start_time;
	pthread_mutex_lock(&phi->state->print_locker);
	if (!phi->state->is_died)
		printf("stamp-time : %5ld ph-id[%d] => ph-action[%s] fork-right[%d]\n",
			current_time, phi->id, action, phi->fork.right);
	pthread_mutex_unlock(&phi->state->print_locker);
}
