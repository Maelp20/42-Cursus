/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:28:15 by mpignet           #+#    #+#             */
/*   Updated: 2022/11/29 18:16:15 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

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

typedef struct s_fork {
	pthread_mutex_t	fork;
	int				taken;
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
    pthread_t   id;
    t_fork      *left_fork;
    t_fork      *right_fork;
    t_rul       *rules;
    int         nb_meals;
}       t_philo;

typedef struct s_group {
    t_philo     *philo;
    pthread_t   *thread_nbrs;
}       t_group;


int     ft_atoi(const char *str);
time_t  get_time(void);

#endif