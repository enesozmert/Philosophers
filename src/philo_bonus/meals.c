/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meals.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:00:32 by eozmert           #+#    #+#             */
/*   Updated: 2022/08/08 11:42:56 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header_bonus.h"

int	check_meals(t_philosopher *phi)
{
	int	i;

	i = 0;
	if (phi->state->times_total_eat != 0)
	{
		while (i < phi->state->number_of_philosophers)
		{
			if (phi[i].count_meals >= phi->state->times_total_eat)
				phi->state->meals++;
			i++;
		}
		if (phi->state->meals >= phi->state->number_of_philosophers)
		{
			phi->state->is_died = 1;
			return (1);
		}
	}
	return (0);
}
