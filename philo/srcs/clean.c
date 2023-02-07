/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:00:58 by mpignet           #+#    #+#             */
/*   Updated: 2022/12/20 15:05:02 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	clean_all(t_rul *rules, t_group *philos)
{
	int	i;

	i = -1;
	while (++i < rules->nb_philo)
		pthread_join(philos->ph_ids[i], NULL);
	pthread_join(philos->supervisor, NULL);
	pthread_mutex_destroy(&rules->stop_prog_mt);
	pthread_mutex_destroy(&rules->print_mt);
	while (++i < rules->nb_philo)
		pthread_mutex_destroy(&rules->fork_tab[i].fork_mt);
	while (++i < rules->nb_philo)
		pthread_mutex_destroy(&philos->philo[i].meals_mt);
	free(rules->fork_tab);
	free(philos->philo);
	free(philos->ph_ids);
	return (0);
}
