/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:34:25 by mpignet           #+#    #+#             */
/*   Updated: 2022/12/16 19:09:53 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int    put_down_forks(t_philo *philo)
{
    // if(need_to_stop_program(philo->rules))
    //     return (1);
    philo->left_fork->taken = false;
    pthread_mutex_unlock(&philo->left_fork->fork_mt);  
    philo->right_fork->taken = false;
    pthread_mutex_unlock(&philo->right_fork->fork_mt);
    return (0);
}

int philo_eat(t_philo *philo)
{
    time_t finish_eating;

    finish_eating = get_time() + philo->rules->mealtime;
    if (print_action(philo, "is eating"))
        return (1);
    philo->last_meal = get_time();
    if (philo->rules->mealtime > 0)
    {        
        while (get_time() < finish_eating)
        {
            if(need_to_stop_program(philo->rules))
                return (put_down_forks(philo), 1);
            usleep(100);
        }
    }
    else
        usleep(100);
    pthread_mutex_lock(&philo->meals_mt);
    philo->nb_meals++;
    pthread_mutex_unlock(&philo->meals_mt);
    if (put_down_forks(philo))
        return (1);
    return (0);
}

int take_forks(t_philo *philo, bool *has_eaten)
{
    // printf("Philo %d tries take fork\n", philo->id);
    if(need_to_stop_program(philo->rules))
        return (1);
    pthread_mutex_lock(&philo->left_fork->fork_mt);
    // printf("left fork taken at adress %p : %d\n", philo->left_fork, philo->left_fork->taken);
    if (philo->left_fork->taken == false)
    {
        pthread_mutex_lock(&philo->right_fork->fork_mt);
        // printf("right fork taken at adress %p : %d\n", philo->right_fork, philo->right_fork->taken);
        if (philo->right_fork->taken == false)
        {
            if (print_action(philo, "has taken  a fork"))
                return (1);
            philo->left_fork->taken = true;
            if(print_action(philo, "has taken  a fork"))
                return (1);
            philo->right_fork->taken = true;
            if(philo_eat(philo))
            {
                (*has_eaten) = true;
                return (1);
            }
            (*has_eaten) = true;
        }
        else
        {
            pthread_mutex_unlock(&philo->left_fork->fork_mt);
            pthread_mutex_unlock(&philo->right_fork->fork_mt);   
        }
    }
    else
        pthread_mutex_unlock(&philo->left_fork->fork_mt);
    return (0);
}

int try_eating(t_philo *philo)
{
    bool has_eaten;

    has_eaten = false;
    if(need_to_stop_program(philo->rules))
        return (1);
    while (has_eaten == false)
        if(take_forks(philo, &has_eaten))
            return (1);
    return (0);
}