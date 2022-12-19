/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:00:58 by mpignet           #+#    #+#             */
/*   Updated: 2022/12/19 17:26:26 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int need_to_stop_program(t_rul *rules)
{
    pthread_mutex_lock(&rules->stop_prog_mt);
    if (rules->stop_program == true)
        return (pthread_mutex_unlock(&rules->stop_prog_mt), 1);
    return (pthread_mutex_unlock(&rules->stop_prog_mt), 0);
}

int philo_death(t_philo *philo)
{
    int time_since_last_meal;

    pthread_mutex_lock(&philo->meals_mt);
    time_since_last_meal = get_time() - philo->last_meal;
    pthread_mutex_unlock(&philo->meals_mt);
    if (time_since_last_meal >= philo->rules->lifespan)
    {
        print_action(philo, "died");
        pthread_mutex_lock(&philo->rules->stop_prog_mt);
        philo->rules->stop_program = true;
        pthread_mutex_unlock(&philo->rules->stop_prog_mt);
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
    pthread_mutex_lock(&philos->rules->stop_prog_mt);
    if (philos->rules->stop_program == true)
        return (pthread_mutex_unlock(&philos->rules->stop_prog_mt), 1);
    pthread_mutex_unlock(&philos->rules->stop_prog_mt);
    while (++i < philos->rules->nb_philo)
    {
        if (philo_death(&philos->philo[i]))
            return(1);
        pthread_mutex_lock(&philos->philo[i].meals_mt);
        if (philos->philo[i].nb_meals == philos->rules->meals_limit)
            max_meals++;
        pthread_mutex_unlock(&philos->philo[i].meals_mt);
    }
    if (max_meals == philos->rules->nb_philo)
    {
        pthread_mutex_lock(&philos->rules->stop_prog_mt);
        philos->rules->stop_program = true;
        pthread_mutex_unlock(&philos->rules->stop_prog_mt);
        return (1);
    }
    return (0);
}

void    *program_check(void *ptr)
{
    t_group *philos;

    philos = (t_group *)ptr;
    if (philos->rules->meals_limit == 0)
    {
        pthread_mutex_lock(&philos->rules->stop_prog_mt);
        philos->rules->stop_program = true;
        pthread_mutex_unlock(&philos->rules->stop_prog_mt);
        return (NULL);
    }
    while (!end_conditions(philos))
        usleep(100);
    return (NULL);
}