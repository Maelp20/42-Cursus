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

void    put_down_forks(t_philo *philo)
{
    if (philo->left_fork->taken)
    {
        philo->left_fork->taken = 0;
        pthread_mutex_unlock(&philo->left_fork->fork_mt);       
    }
    if (philo->right_fork->taken)
    {        
        philo->right_fork->taken = 0;
        pthread_mutex_unlock(&philo->right_fork->fork_mt);
    }
}

void    philo_eat(t_philo *philo)
{
    time_t finish_eating;

    finish_eating = get_time() + philo->rules->mealtime;
    printf("%ld philo %d is eating\n", get_time(), philo->id);
    philo->last_meal = get_time();
    while (get_time() < finish_eating)
    {
        // check if sim finished
        usleep(100);
    }
    philo->nb_meals++;
    put_down_forks(philo);
}

void    take_forks(t_philo *philo)
{
    int equipment;

    equipment = 0;
    if (!philo->left_fork->taken)
    {
        pthread_mutex_lock(&philo->left_fork->fork_mt);
        printf("%ld philo %d has taken a fork\n", get_time(), philo->id);
        philo->left_fork->taken = 1;
        equipment++;
    }
    if (!philo->right_fork->taken)
    {
        pthread_mutex_lock(&philo->right_fork->fork_mt);
        printf("%ld philo %d has taken a fork\n", get_time(), philo->id);
        philo->right_fork->taken = 1;
        equipment++;
    }
    if (equipment == 2)
        philo_eat(philo);
    else if (equipment == 1)
        put_down_forks(philo);
}