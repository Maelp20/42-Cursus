/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:10:33 by mpignet           #+#    #+#             */
/*   Updated: 2022/12/16 18:02:45 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	nbr;
	int	sign;

	nbr = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + *str - 48;
		str++;
	}
	nbr = nbr * sign;
	return (nbr);
}

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
        rules->fork_tab[i].taken = false;
    }
}

void    init_philo(t_philo *philo, t_rul *rules, int i)
{
    philo->id = i + 1;
    philo->rules = rules;
    philo->nb_meals = 0;
    philo->last_meal = philo->rules->start_time;
    if (philo->id == rules->nb_philo)
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
    pthread_mutex_init(&rules->stop_prog_mt, NULL);
    rules->stop_program = false;
    rules->nb_philo = ft_atoi(av[1]);
    rules->lifespan = ft_atoi(av[2]);
    rules->mealtime = ft_atoi(av[3]);
    rules->sleeptime = ft_atoi(av[4]);
    rules->start_time = get_time();
    if (av[5])
        rules->meals_limit = ft_atoi(av[5]);
    else
        rules->meals_limit = -1;
    init_forks(rules);
}