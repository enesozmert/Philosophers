/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:08:38 by eozmert           #+#    #+#             */
/*   Updated: 2022/08/04 22:56:24 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"

typedef struct s_state
{
	int				id;
	pthread_mutex_t	*forks;
	pthread_mutex_t	is_fork;
	pthread_mutex_t	print_locker;
	int				number_of_philosophers;
	int				start_time;
	int				time_to_die;
	int				time_to_eat;
	int				times_total_eat;
	int				time_to_sleep;
	int				is_died;
	int				meals;
}	t_state;

typedef struct s_fork
{
	int	id;
	int	left;
	int	right;
	int	is_left;
	int	is_right;
}	t_fork;

typedef struct s_philosopher
{
	int			id;
	pthread_t	phi_thread;
	pthread_t	state_thread;
	t_fork		fork;
	t_state		*state;
	long		time_left_meal;
	int			count_meals;
	int			is_hunger;
}	t_philosopher;

typedef struct s_action
{
	char	*write_color;
	char	*message;
	char	*name;
}	t_action;

typedef struct s_exception
{
	int		error_code;
	char	*message;
	int		(*f)(char **);
}	t_exception;

void			start(t_philosopher *phi);
void			end(t_philosopher *phi, t_fork *fork);
void			*state_check(void *arg);
void			*routine(void *arg);
void			eating(t_philosopher *phi);
void			sleeping(t_philosopher *phi);
void			thinks(t_philosopher *phi);
t_philosopher	*init_philosophers(t_state *state);
int				init_state(t_state *state, char **av);
t_fork			*init_fork(t_philosopher *phi);
int				get_ac(char **av);
void			my_usleep(long u_time);
void			get_fork_status_left(t_philosopher *phi, int status);
void			get_fork_status_right(t_philosopher *phi, int status);
void			is_one_phi(t_philosopher *phi);
long			get_time(void);
int				is_died(t_philosopher phi);
int				check_meals(t_philosopher *phi);
void			action_handler(t_philosopher *phi, char *message);
void			print_action_main(t_philosopher *phi, char *action);
void			print_action_left(t_philosopher *phi, char *action);
void			print_action_right(t_philosopher *phi, char *action);
int				ft_atoi(const char *str);
long			ft_atoi_long(const char *str);
int				ft_strcmp(char *s1, char *s2);
int				exception_handler(char **str);
int				arg_check_digit(char **str);
int				arg_check_count(char **str);
int				arg_check_overflow(char **str);
int				arg_check_negative(char **str);
#endif
