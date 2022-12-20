/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   eat_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:34:25 by mpignet           #+#    #+#             */
/*   Updated: 2022/12/20 14:39:20 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	put_down_forks(t_philo *philo)
{
	philo->left_fork->taken = false;
	pthread_mutex_unlock(&philo->left_fork->fork_mt);
	philo->right_fork->taken = false;
	pthread_mutex_unlock(&philo->right_fork->fork_mt);
	return (0);
}

int	philo_eat(t_philo *philo)
{
	time_t	finish_eating;

	finish_eating = get_time() + philo->rules->mealtime;
	print_action(philo, "is eating");
	pthread_mutex_lock(&philo->meals_mt);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->meals_mt);
	if (philo->rules->mealtime > 0)
	{	
		while (get_time() < finish_eating)
		{
			if (need_to_stop_program(philo->rules))
				return (put_down_forks(philo), 1);
			usleep(100);
		}
	}
	pthread_mutex_lock(&philo->meals_mt);
	philo->nb_meals++;
	pthread_mutex_unlock(&philo->meals_mt);
	if (put_down_forks(philo))
		return (1);
	return (0);
}

int	take_forks(t_philo *philo, bool *ate)
{
	print_action(philo, "has taken a fork");
	philo->left_fork->taken = true;
	print_action(philo, "has taken a fork");
	philo->right_fork->taken = true;
	if (philo_eat(philo))
	{
		(*ate) = true;
		return (1);
	}
	(*ate) = true;
	return (0);
}

int	try_forks(t_philo *philo, bool *ate, t_fork *f1, t_fork *f2)
{
	if (need_to_stop_program(philo->rules))
		return (1);
	pthread_mutex_lock(&f1->fork_mt);
	if (f1 == f2)
		return (pthread_mutex_unlock(&f1->fork_mt), 1);
	if (f1->taken == false)
	{
		pthread_mutex_lock(&f2->fork_mt);
		if (f2->taken == false)
		{	
			if (take_forks(philo, ate))
				return (1);
		}
		else
		{
			pthread_mutex_unlock(&f1->fork_mt);
			pthread_mutex_unlock(&f2->fork_mt);
		}
	}
	else
		pthread_mutex_unlock(&f1->fork_mt);
	return (0);
}

int	try_eating(t_philo *philo)
{
	bool	ate;

	ate = false;
	if (need_to_stop_program(philo->rules))
		return (1);
	if (philo->id % 2 == 0)
	{
		while (ate == false)
			if (try_forks(philo, &ate, philo->left_fork, philo->right_fork))
				return (1);
	}
	else
	{
		while (ate == false)
			if (try_forks(philo, &ate, philo->right_fork, philo->left_fork))
				return (1);
	}
	return (0);
}
