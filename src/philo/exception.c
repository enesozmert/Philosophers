/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:57:59 by eozmert           #+#    #+#             */
/*   Updated: 2022/08/04 17:04:57 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	arg_check_digit(char **str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if ((str[i][j] < '0' || str[i][j] > '9') && str[i][j] != ' ')
				return (401);
			j++;
		}
		i++;
	}
	return (0);
}

int	arg_check_count(char **str)
{
	int	ac;

	ac = 1;
	while (str[ac])
	ac++;
	if (ac < 5 || ac > 6)
		return (402);
	return (0);
}

int	arg_check_overflow(char **str)
{
	int		i;
	long	num;

	i = 1;
	num = 0;
	while (str[i])
	{
		num = ft_atoi_long(str[i]);
		if (num <= 0 || num > 2147483647)
			return (403);
		i++;
	}
	return (0);
}

int	arg_check_negative(char **str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '-')
				return (404);
			j++;
		}
		i++;
	}
	return (0);
}
