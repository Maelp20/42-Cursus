/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:10:33 by mpignet           #+#    #+#             */
/*   Updated: 2022/12/13 16:18:43 by mpignet          ###   ########.fr       */
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
   // printf("philo %d : left fork : %d // right fork : %d\n", philo->id, philo->left_fork->taken, philo->right_fork->taken);
    philo->nb_meals = 0;
    philo->last_meal = 0;
}