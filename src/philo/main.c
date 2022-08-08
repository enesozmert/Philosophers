/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:11:27 by eozmert           #+#    #+#             */
/*   Updated: 2022/08/05 15:25:45 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

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
	is_one_phi(phi);
	start(phi);
	end(phi, fork);
	return (0);
}
