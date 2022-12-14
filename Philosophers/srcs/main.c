/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:28:03 by mpignet           #+#    #+#             */
/*   Updated: 2022/12/14 17:29:05 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int philo_death(t_philo *philo)
{
    int time_since_last_meal;

    time_since_last_meal = get_time() - philo->last_meal;
    if (time_since_last_meal >= philo->rules->lifespan)
    {
        printf("%ld philo %d has died\n", get_time(), philo->id);
        return(1);
    }
    return (0);
}

int end_conditions(t_group *philos)
{
    int     i;
    int     max_meals;

    i = -1;
    max_meals = 0;
    while (++i < philos->rules->nb_philo)
    {
        if (philo_death(&philos->philo[i]))
            return(1);
        pthread_mutex_lock(&philos->philo[i].meals_mt);
        if (philos->philo[i].nb_meals == philos->rules->meals_limit)
            max_meals++;
        pthread_mutex_lock(&philos->philo[i].meals_mt);
    }
    if (max_meals == philos->rules->nb_philo)
        return (1);
    return (0);
}

void    *program_check(void *ptr)
{
    t_group *philos;

    philos = (t_group *)ptr;
    if (philos->rules->meals_limit == 0)
    {
        philos->rules->stop_program = 1;
        return (NULL);
    }
    while (1)
    {
        if(end_conditions(philos))
        {
            philos->rules->stop_program = 1;
            return (NULL);
        }
        usleep(100);
    }
    return (NULL);
}

void    philo_sleep(t_philo *philo)
{
    time_t  wake_up_time;

    wake_up_time = get_time() + philo->rules->sleeptime;
    printf("%ld philo %d is sleeping\n", get_time(), philo->id);
    while (get_time() < wake_up_time)
    {
        // check if sim finished
        usleep(100);
    }
}

void    *philo_routine(void *ptr)
{
    t_philo *philo;
    
    philo = (t_philo *)ptr;
    if (philo->id % 2)
        usleep(10);
    while (!philo->rules->stop_program)
    {
        take_forks(philo);
        philo_sleep(philo);
        printf("%ld philo %d is thinking\n", get_time(), philo->id);
    }
    return (ptr);
}

int philosophers(t_rul *rules)
{
    int         i;
    t_group     philos;

    philos.rules = rules;
    philos.philo = malloc (sizeof(t_philo) * rules->nb_philo);
    if (!philos.philo)
        return (1);
    philos.thread_nbrs = malloc (sizeof(pthread_t) * rules->nb_philo);
    if (!philos.thread_nbrs)
        return (1);
    i = -1;
    while (++i < rules->nb_philo)
    {
        init_philo(&philos.philo[i], rules, i);
        pthread_create(&philos.thread_nbrs[i], NULL, philo_routine, &philos.philo[i]);
    }
    pthread_create(&philos.superviser, NULL, program_check, &philos);
    i = -1;
    while (++i < rules->nb_philo)
        pthread_join(philos.thread_nbrs[i], NULL);
    pthread_join(philos.superviser, NULL);
    return (0);
}

int main(int ac, char **av)
{
    t_rul   rules;
    
    printf("begin : %ld\n", get_time());
    if (ac < 5 || ac > 6)
        return (printf("Philo: Wrong number of arguments\n"), 1);
    parse(&rules, av);
    philosophers(&rules);
    return (0);
}