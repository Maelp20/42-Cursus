/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:28:15 by mpignet           #+#    #+#             */
/*   Updated: 2022/12/20 14:58:16 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*			INCLUDE			*/

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>

# define TIMES_TO_COUNT 21000

# define NC  "\e[0m"
# define YELLOW  "\e[33m"
# define BYELLOW	"\e[1;33m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"

/*			STRUCT			*/

typedef struct s_fork {
	pthread_mutex_t	fork_mt;
	bool			taken;
}			t_fork;

typedef struct s_rul {
	int				nb_philo;
	int				lifespan;
	int				mealtime;
	int				sleeptime;
	int				meals_limit;
	pthread_mutex_t	print_mt;
	pthread_mutex_t	stop_prog_mt;
	bool			stop_program;
	t_fork			*fork_tab;
	time_t			start_time;
}		t_rul;

typedef struct s_philo {
	int				id;
	t_fork			*left_fork;
	t_fork			*right_fork;
	t_rul			*rules;
	pthread_mutex_t	meals_mt;
	int				nb_meals;
	time_t			last_meal;
}		t_philo;

typedef struct s_group {
	t_philo		*philo;
	pthread_t	*ph_ids;
	pthread_t	supervisor;
	t_rul		*rules;
}		t_group;

/*			INIT			*/

int		parse(t_rul *rules, char **av);
int		init_philo(t_philo *philo, t_rul *rules, int i);

/*			UTILS			*/

int		clean_all(t_rul *rules, t_group *philos);
int		print_action(t_philo *philo, char *msg);
time_t	get_time(void);
int		ft_usleep(t_rul *rules, time_t time);
void	ft_put_error(char *s);

/*		    ROUTINES		*/

int		try_eating(t_philo *philo);

/*		  SUPERVISOR     	*/

void	*program_check(void *ptr);
int		need_to_stop_program(t_rul *rules);

#endif