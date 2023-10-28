/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelpignet <maelpignet@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:28:03 by mpignet           #+#    #+#             */
/*   Updated: 2023/10/28 09:10:02 by maelpignet       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_sleep(t_philo *philo)
{
	if (need_to_stop_program(philo->rules))
		return (1);
	print_action(philo, "is sleeping");
	if (philo->rules->sleeptime > 0)
		ft_usleep(philo->rules, philo->rules->sleeptime);
	else
	{
		if (need_to_stop_program(philo->rules))
			return (usleep(100), 1);
	}
	return (0);
}

time_t	get_thinktime(t_philo *philo)
{
	time_t	thinktime;

	thinktime = (philo->rules->lifespan - philo->rules->mealtime
			- (get_time() - philo->last_meal)) / 2;
	if (thinktime > 600)
		thinktime = 600;
	else if (thinktime < 0)
		thinktime = 1;
	return (thinktime);
}

void	*routine(void *ptr)
{
	t_philo	*philo;
	time_t	thinktime;

	philo = (t_philo *)ptr;
	while (!need_to_stop_program(philo->rules))
	{
		if (try_eating(philo))
			return (NULL);
		if (philo_sleep(philo))
			return (NULL);
		if (print_action(philo, "is thinking"))
			return (NULL);
		thinktime = get_thinktime(philo);
		if (ft_usleep(philo->rules, thinktime))
			return (NULL);
	}
	return (ptr);
}

int	philosophers(t_rul *rules)
{
	int		i;
	t_group	philos;

	memset(&philos, 0, sizeof(t_group));
	philos.rules = rules;
	philos.philo = malloc (sizeof(t_philo) * rules->nb_philo);
	if (!philos.philo)
		return (1);
	philos.ph_ids = malloc (sizeof(pthread_t) * rules->nb_philo);
	if (!philos.ph_ids)
		return (1);
	i = -1;
	while (++i < rules->nb_philo)
	{
		if (init_philo(&philos.philo[i], rules, i))
			return (perror("philo"), 1);
		if (pthread_create(&philos.ph_ids[i], NULL, routine, &philos.philo[i]))
			return (perror("philo"), 1);
	}
	if (pthread_create(&philos.supervisor, NULL, program_check, &philos))
		return (perror("philo"), 1);
	clean_all(rules, &philos);
	return (0);
}


// args : nb_philo, time_to_die, time_to_eat, time_to_sleep, [nb_time_to_eat]

int	main(int ac, char **av)
{
	t_rul	rules;

	if (ac != 5 && ac != 6)
		return (printf("philo: wrong number of arguments\n"), 1);
	memset(&rules, 0, sizeof(t_rul));
	if (parse(&rules, av))
		return (1);
	philosophers(&rules);
	return (0);
}
