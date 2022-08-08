/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:40:34 by eozmert           #+#    #+#             */
/*   Updated: 2022/08/08 14:40:37 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header_bonus.h"

int	main(int ac, char **av)
{
	t_state			state;
	t_philosopher	*phi;
	t_fork			*fork;

	(void)ac;
	if (!exception_handler(av))
		return (0);
	init_state(&state, av);
	phi = init_philosophers(&state);
	fork = init_fork(phi);
	init_sem(&state);
	is_one_phi(phi);
	start(phi);
	end(phi, fork);
	return (0);
}
