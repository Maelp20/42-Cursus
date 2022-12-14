/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:28:15 by mpignet           #+#    #+#             */
/*   Updated: 2022/12/14 17:27:02 by mpignet          ###   ########.fr       */
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
	int		        taken;
}			t_fork;

typedef struct s_rul {
    int     nb_philo;
    int     lifespan;
    int     mealtime;
    int     sleeptime;
    int     meals_limit;
    int     stop_program;
    t_fork  *fork_tab;
}       t_rul;

typedef struct s_philo {
    int             id;
    t_fork          *left_fork;
    t_fork          *right_fork;
    t_rul           *rules;
    pthread_mutex_t meals_mt;
    int             nb_meals;
    long int        last_meal;
}       t_philo;

typedef struct s_group {
    t_philo     *philo;
    pthread_t   *thread_nbrs;
    pthread_t   superviser;
    t_rul       *rules;
}       t_group;

/*			INIT			*/

void    parse(t_rul *rules, char **av);
void    init_philo(t_philo *philo, t_rul *rules, int i);

/*			UTILS			*/

int     ft_atoi(const char *str);
time_t  get_time(void);

/*			ROUTINES		*/

void    take_forks(t_philo *philo);

#endif