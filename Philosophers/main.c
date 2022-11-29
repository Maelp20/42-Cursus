/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:28:03 by mpignet           #+#    #+#             */
/*   Updated: 2022/11/29 19:03:00 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_rul *parse(int ac, char **av)
{
    printf("parse\n");
    t_rul *rules;

    rules = malloc(sizeof(t_rul));
    if (!rules)
        return (NULL);
    rules->nb_philo = ft_atoi(av[1]);
    rules->lifespan = ft_atoi(av[2]);
    rules->mealtime = ft_atoi(av[3]);
    rules->sleeptime = ft_atoi(av[4]);
    if (av[5])
        rules->loop_limit = ft_atoi(av[5]);
    else
        rules->loop_limit = -1;
    return (rules);
}

void    *thread(void *ptr)
{
    printf("thread\n");
    t_philo *philo;
    
    philo = (t_philo *)ptr;
    usleep(10);
    printf("ID: %ld\n", philo->id);
    while (1)
    {
        printf("%ld philo %ld has taken a fork\n", get_time(), philo->id);
        printf("%ld philo %ld is eating\n", get_time(), philo->id);
        usleep(philo->rules->mealtime);
        printf("%ld philo %ld is sleeping\n", get_time(), philo->id);
        usleep(philo->rules->sleeptime);
    }
    return (ptr);
}

int philo(t_rul *rules)
{
    printf("philo\n");
    int         i;
    t_group     group;
    pthread_t   *ids;

    ids = malloc (sizeof (pthread_t) * rules->nb_philo);
    if (!ids)
        return (1);
    group.philo = malloc (sizeof(t_philo) * rules->nb_philo);
    if (!group.philo)
        return (1);
    group.thread_nbrs = malloc (sizeof(pthread_t) * rules->nb_philo);
    if (!group.thread_nbrs)
        return (1);
    i = -1;
    while (++i < rules->nb_philo)
    {
        group.philo[i].id = i + 1;
        group.philo[i].rules = rules;
        pthread_create(&ids[i], NULL, thread, &(group.philo[i]));
        group.thread_nbrs[i] = ids[i];
    }
    i = -1;
    while (++i < rules->nb_philo)
        pthread_join(group.thread_nbrs[i], NULL);
}

int main(int ac, char **av)
{
    t_rul *rules;
    
    if (ac < 5 || ac > 6)
        return (printf("Philo: Wrong number of arguments\n"), 1);
    rules = parse(ac, av);
    if (!rules)
        return (1);
    philo(rules);
    return (0);
}