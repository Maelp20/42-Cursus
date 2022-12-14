/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:10:33 by mpignet           #+#    #+#             */
/*   Updated: 2022/12/14 17:27:26 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    init_forks(t_rul *rules)
{
    int i;
    
    rules->fork_tab = malloc(sizeof(t_fork) * rules->nb_philo);
    if (!rules->fork_tab)
        exit (EXIT_FAILURE);
    i = -1;
    while (++i < rules->nb_philo)
    {
        pthread_mutex_init(&rules->fork_tab[i].fork_mt, NULL);
        rules->fork_tab[i].taken = 0;
    }
}

void    init_philo(t_philo *philo, t_rul *rules, int i)
{
    philo->id = i + 1;
    philo->rules = rules;
    philo->nb_meals = 0;
    philo->last_meal = 0;
    if (philo->id == 1)
    {
        philo->left_fork = &rules->fork_tab[rules->nb_philo -1];
        philo->right_fork = &rules->fork_tab[i + 1];
    }
    else if (philo->id == rules->nb_philo)
    {
        philo->left_fork = &rules->fork_tab[i];
        philo->right_fork = &rules->fork_tab[0];
    }
    else
    {        
        philo->left_fork = &rules->fork_tab[i];
        philo->right_fork = &rules->fork_tab[i + 1];
    }
}

void    parse(t_rul *rules, char **av)
{
    rules->stop_program = 0;
    rules->nb_philo = ft_atoi(av[1]);
    rules->lifespan = ft_atoi(av[2]);
    rules->mealtime = ft_atoi(av[3]);
    rules->sleeptime = ft_atoi(av[4]);
    if (av[5])
        rules->meals_limit = ft_atoi(av[5]);
    else
        rules->meals_limit = -1;
    init_forks(rules);
}