/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:28:15 by mpignet           #+#    #+#             */
/*   Updated: 2022/11/30 16:42:42 by mpignet          ###   ########.fr       */
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

# define TIMES_TO_COUNT 21000

# define NC  "\e[0m"
# define YELLOW  "\e[33m"
# define BYELLOW	"\e[1;33m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"

/*			STRUCT			*/

typedef struct s_fork {
	pthread_mutex_t	fork_mt;
	int		        taken_by;
}			t_fork;

typedef struct s_rul {
    int     nb_philo;
    int     lifespan;
    int     mealtime;
    int     sleeptime;
    int     loop_limit;
    t_fork  *fork_tab;
}       t_rul;

typedef struct s_philo {
    int         id;
    t_fork      *left_fork;
    t_fork      *right_fork;
    t_rul       *rules;
    int         nb_meals;
    long int    last_meal;
}       t_philo;

typedef struct s_group {
    t_philo     *philo;
    pthread_t   *thread_nbrs;
}       t_group;

/*			INIT			*/

void    init_philo(t_philo *philo, t_rul *rules, int i);
void    init_forks(t_rul *rules);

/*			UTILS			*/

int     ft_atoi(const char *str);
time_t  get_time(void);

#endif