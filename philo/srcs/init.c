/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:10:33 by mpignet           #+#    #+#             */
/*   Updated: 2022/12/20 14:53:34 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_int(const char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] < '0' || str[i] > '9')
			return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	nbr;
	int	sign;

	nbr = 0;
	sign = 1;
	if (ft_check_int(str))
		return (-2);
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + *str - 48;
		str++;
	}
	if (nbr < 0)
		return (-2);
	nbr = nbr * sign;
	return (nbr);
}

int	init_forks(t_rul *rules)
{
	int	i;

	rules->fork_tab = malloc(sizeof(t_fork) * rules->nb_philo);
	if (!rules->fork_tab)
		return (ft_put_error("philo: malloc failed\n"), 1);
	i = -1;
	while (++i < rules->nb_philo)
	{
		if (pthread_mutex_init(&rules->fork_tab[i].fork_mt, NULL))
			return (perror("philo"), 1);
		rules->fork_tab[i].taken = false;
	}
	return (0);
}

int	init_philo(t_philo *philo, t_rul *rules, int i)
{
	philo->id = i + 1;
	philo->rules = rules;
	philo->nb_meals = 0;
	philo->last_meal = philo->rules->start_time;
	if (pthread_mutex_init(&philo->meals_mt, NULL))
		return (perror("philo"), 1);
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
	return (0);
}

int	parse(t_rul *rules, char **av)
{
	pthread_mutex_init(&rules->stop_prog_mt, NULL);
	pthread_mutex_init(&rules->print_mt, NULL);
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
	if (rules->nb_philo < 1 || rules->lifespan == -2
		|| rules->mealtime == -2 || rules->sleeptime == -2
		|| rules->meals_limit == -2)
		return (ft_put_error("philo: wrong argument\n"), 1);
	else if (rules->nb_philo > 200)
		return (ft_put_error("max nb of philosophers : 200"), 1);
	if (rules->meals_limit == 0)
		return (ft_put_error("each philo must be able to eat 1 time"), 1);
	if (init_forks(rules))
		return (1);
	return (0);
}
