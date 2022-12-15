/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:28:03 by mpignet           #+#    #+#             */
/*   Updated: 2022/12/14 17:29:05 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int philo_sleep(t_philo *philo)
{
    time_t  wake_up_time;

    wake_up_time = get_time() + philo->rules->sleeptime;
    printf("%ld philo %d is sleeping\n", get_time(), philo->id);
    while (get_time() < wake_up_time)
    {
        pthread_mutex_lock(&philo->rules->stop_prog_mt);
        if (philo->rules->stop_program == true)
            return (pthread_mutex_unlock(&philo->rules->stop_prog_mt), 1);
        pthread_mutex_unlock(&philo->rules->stop_prog_mt);
        usleep(100);
    }
    return (0);
}

void    *philo_routine(void *ptr)
{
    t_philo *philo;
    
    philo = (t_philo *)ptr;
    if (philo->id % 2)
        usleep(10);
    while (1)
    {
        pthread_mutex_lock(&philo->rules->stop_prog_mt);
        if (philo->rules->stop_program == true)
            return (NULL);
        pthread_mutex_unlock(&philo->rules->stop_prog_mt);
        if(take_forks(philo))
            return(NULL);
        if(philo_sleep(philo))
            return(NULL);
        printf("%ld philo %d is thinking\n", get_time(), philo->id);
    }
    return (ptr);
}

int philosophers(t_rul *rules)
{
    int         i;
    t_group     philos;

    philos.rules = rules;
    philos.philo = malloc (sizeof(t_philo) * rules->nb_philo);
    if (!philos.philo)
        return (1);
    philos.thread_nbrs = malloc (sizeof(pthread_t) * rules->nb_philo);
    if (!philos.thread_nbrs)
        return (1);
    i = -1;
    while (++i < rules->nb_philo)
    {
        init_philo(&philos.philo[i], rules, i);
        pthread_create(&philos.thread_nbrs[i], NULL, philo_routine, &philos.philo[i]);
    }
    pthread_create(&philos.supervisor, NULL, program_check, &philos);
    i = -1;
    while (++i < rules->nb_philo)
        pthread_join(philos.thread_nbrs[i], NULL);
    pthread_join(philos.supervisor, NULL);
    return (0);
}

int main(int ac, char **av)
{
    t_rul   rules;
    
    printf("begin : %ld\n", get_time());
    if (ac < 5 || ac > 6)
        return (printf("Philo: Wrong number of arguments\n"), 1);
    parse(&rules, av);
    philosophers(&rules);
    return (0);
}