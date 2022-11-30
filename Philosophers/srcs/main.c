/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:28:03 by mpignet           #+#    #+#             */
/*   Updated: 2022/11/30 18:24:17 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    parse(t_rul *rules, char **av)
{
    rules->nb_philo = ft_atoi(av[1]);
    rules->lifespan = ft_atoi(av[2]);
    rules->mealtime = ft_atoi(av[3]);
    rules->sleeptime = ft_atoi(av[4]);
    if (av[5])
        rules->loop_limit = ft_atoi(av[5]);
    else
        rules->loop_limit = -1;
    init_forks(rules);
}

void    philo_eat(t_philo *philo)
{
    printf("%ld philo %d is eating\n", get_time(), philo->id);
    usleep(philo->rules->mealtime);
    philo->last_meal = get_time();
    philo->nb_meals++;
    pthread_mutex_lock(&philo->left_fork->fork_mt);
    philo->left_fork->taken_by = 0;
    pthread_mutex_unlock(&philo->left_fork->fork_mt);
    pthread_mutex_lock(&philo->right_fork->fork_mt);
    philo->right_fork->taken_by = 0;
    pthread_mutex_unlock(&philo->right_fork->fork_mt);
}

void    take_forks(t_philo *philo)
{
    int equipment;
    
    equipment = 0;
   // printf("left fork : %d\n", philo->left_fork->taken_by);
    pthread_mutex_lock(&philo->left_fork->fork_mt);
    if (philo->left_fork->taken_by == philo->id)
        equipment++;
    else if (!philo->left_fork->taken_by)
    {
        printf("%ld philo %d has taken a fork\n", get_time(), philo->id);
        philo->left_fork->taken_by = philo->id;
        equipment++;
    }
    pthread_mutex_unlock(&philo->left_fork->fork_mt);
   // printf("right fork : %d\n", philo->right_fork->taken_by);
    pthread_mutex_lock(&philo->right_fork->fork_mt);
    if (philo->right_fork->taken_by == philo->id)
        equipment++;
    else if (!philo->right_fork->taken_by)
    {
        printf("%ld philo %d has taken a fork\n", get_time(), philo->id);
        philo->right_fork->taken_by = philo->id;
        equipment++;
    }
    pthread_mutex_unlock(&philo->right_fork->fork_mt);
    if (equipment == 2)
        philo_eat(philo);
}

void    *thread(void *ptr)
{
    t_philo *philo;
    
    philo = (t_philo *)ptr;
    usleep(10);
    int i = -1;
    while (++i < 10)
    {
        take_forks(philo);
        printf("%ld philo %d is sleeping\n", get_time(), philo->id);
        usleep(philo->rules->sleeptime);
    }
    return (ptr);
}

int philo(t_rul *rules)
{
    int         i;
    t_group     group;

    group.philo = malloc (sizeof(t_philo) * rules->nb_philo);
    if (!group.philo)
        return (1);
    group.thread_nbrs = malloc (sizeof(pthread_t) * rules->nb_philo);
    if (!group.thread_nbrs)
        return (1);
    i = -1;
    while (++i < rules->nb_philo)
    {
        init_philo(&group.philo[i], rules, i);
        pthread_create(&group.thread_nbrs[i], NULL, thread, &group.philo[i]);
    }
    i = -1;
    while (++i < rules->nb_philo)
        pthread_join(group.thread_nbrs[i], NULL);
    return (0);
}

int main(int ac, char **av)
{
    t_rul   rules;
    
    if (ac < 5 || ac > 6)
        return (printf("Philo: Wrong number of arguments\n"), 1);
    parse(&rules, av);
    philo(&rules);
    return (0);
}