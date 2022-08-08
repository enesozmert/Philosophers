/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:47:10 by eozmert           #+#    #+#             */
/*   Updated: 2022/08/08 14:45:08 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header_bonus.h"

static	t_action	*action_handler_data(t_action *action)
{
	action[0] = (t_action){KGRN, "eating", "p"};
	action[1] = (t_action){KYEL, "sleeping", "p"};
	action[2] = (t_action){KWHT, "thinks", "p"};
	action[3] = (t_action){KBLU, "taken left", "l"};
	action[4] = (t_action){KBLU, "untaken left", "l"};
	action[5] = (t_action){KMAG, "taken right", "r"};
	action[6] = (t_action){KMAG, "untaken right", "r"};
	action[7] = (t_action){KRED, "died", "p"};
	action[8] = (t_action){NULL, NULL, NULL};
	return (action);
}

void	action_handler(t_philosopher *phi, char *message)
{
	int			i;
	t_action	action[9];

	i = 0;
	action_handler_data(action);
	while (action[i].message != NULL)
	{
		if (ft_strcmp(action[i].message, message) == 0)
		{
			printf("%s", action[i].write_color);
			if (action[i].name[0] == 'l')
				print_action_left(phi, action[i].message);
			else if (action[i].name[0] == 'r')
				print_action_right(phi, action[i].message);
			else if (action[i].name[0] == 'p')
				print_action_main(phi, action[i].message);
			printf("%s", KNRM);
		}
		i++;
	}
	printf("%s", KNRM);
}
