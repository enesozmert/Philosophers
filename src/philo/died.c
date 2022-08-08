/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   died.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:53:21 by eozmert           #+#    #+#             */
/*   Updated: 2022/08/04 14:54:08 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	is_died(t_philosopher phi)
{
	long	now;

	now = get_time();
	if (get_time() - phi.time_left_meal > phi.state->time_to_die)
	{
		return (1);
	}
	return (0);
}
