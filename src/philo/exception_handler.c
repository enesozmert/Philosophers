/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:54:20 by eozmert           #+#    #+#             */
/*   Updated: 2022/08/04 17:03:03 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	exception_handler(char **str)
{
	int			i;
	int			handle_code;
	t_exception	exception[5];

	i = 0;
	handle_code = 0;
	exception[0] = (t_exception){401, "is invalid digit.", arg_check_digit};
	exception[1] = (t_exception){402, "is invalid count.", arg_check_count};
	exception[2] = (t_exception){403, "is invalid number.", arg_check_overflow};
	exception[3] = (t_exception){404, "is invalid digit.", arg_check_negative};
	exception[4] = (t_exception){-1, NULL, NULL};
	while (exception[i].message != NULL)
	{
		handle_code = exception[i].f(str);
		if (handle_code == exception[i].error_code)
		{
			printf("Error %s\n", exception[i].message);
			return (0);
			break ;
		}
		i++;
	}
	return (-1);
}
