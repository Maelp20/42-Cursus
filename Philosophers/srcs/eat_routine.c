/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:34:25 by mpignet           #+#    #+#             */
/*   Updated: 2022/12/14 13:35:14 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int    put_down_forks(t_philo *philo)
{
    pthread_mutex_lock(&philo->rules->stop_prog_mt);
    if (philo->rules->stop_program == true)
        return (pthread_mutex_unlock(&philo->rules->stop_prog_mt), 1);
    pthread_mutex_unlock(&philo->rules->stop_prog_mt);
    if (philo->left_fork->taken)
    {
        philo->left_fork->taken = false;
        pthread_mutex_unlock(&philo->left_fork->fork_mt);       
    }
    if (philo->right_fork->taken)
    {        
        philo->right_fork->taken = false;
        pthread_mutex_unlock(&philo->right_fork->fork_mt);
    }
    return (0);
}

int philo_eat(t_philo *philo)
{
    time_t finish_eating;

    finish_eating = get_time() + philo->rules->mealtime;
    printf("%ld philo %d is eating\n", get_time(), philo->id);
    philo->last_meal = get_time();
    while (get_time() < finish_eating)
    {
        pthread_mutex_lock(&philo->rules->stop_prog_mt);
        if (philo->rules->stop_program == true)
            return (pthread_mutex_unlock(&philo->rules->stop_prog_mt), 1);
        pthread_mutex_unlock(&philo->rules->stop_prog_mt);
        usleep(100);
    }
    philo->nb_meals++;
    if (put_down_forks(philo))
        return (1);
    return (0);
}

int take_forks(t_philo *philo)
{
    int equipment;

    equipment = 0;
    pthread_mutex_lock(&philo->rules->stop_prog_mt);
    if (philo->rules->stop_program == true)
        return (pthread_mutex_unlock(&philo->rules->stop_prog_mt), 1);
    pthread_mutex_unlock(&philo->rules->stop_prog_mt);
    if (!philo->left_fork->taken)
    {
        pthread_mutex_lock(&philo->left_fork->fork_mt);
        printf("%ld philo %d has taken a fork\n", get_time(), philo->id);
        philo->left_fork->taken = true;
        equipment++;
    }
    if (!philo->right_fork->taken)
    {
        pthread_mutex_lock(&philo->right_fork->fork_mt);
        printf("%ld philo %d has taken a fork\n", get_time(), philo->id);
        philo->right_fork->taken = true;
        equipment++;
    }
    if (equipment == 2)
    {
        if(philo_eat(philo))
            return (1);
    }
    else if (equipment == 1)
        if (put_down_forks(philo))
            return (1);
    return (0);
}