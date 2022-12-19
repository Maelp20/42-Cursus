/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:28:03 by mpignet           #+#    #+#             */
/*   Updated: 2022/12/19 17:16:17 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int philo_sleep(t_philo *philo)
{
    if(need_to_stop_program(philo->rules))
        return (1);
    print_action(philo, "is sleeping");
    if (philo->rules->sleeptime > 0)
        ft_usleep(philo->rules, philo->rules->sleeptime);
    else
    {     
        if(need_to_stop_program(philo->rules))
                return (usleep(100), 1);
    }
    return (0);
}

time_t  get_thinktime(t_philo *philo)
{
    time_t  thinktime;

    thinktime = (philo->rules->lifespan - philo->rules->mealtime
            - (get_time() - philo->last_meal)) / 2;
    if (thinktime > 600)
        thinktime = 600;
    else if (thinktime < 0)
        thinktime = 1;
    return (thinktime);
}

void    *philo_routine(void *ptr)
{
    t_philo *philo;
    time_t  thinktime;

    philo = (t_philo *)ptr;
    while (!need_to_stop_program(philo->rules))
    {
        if(try_eating(philo))
            return(NULL);
        if(philo_sleep(philo))
            return(NULL);
        if(print_action(philo, "is thinking"))
            return (NULL);
        thinktime = get_thinktime(philo);
        if (ft_usleep(philo->rules, thinktime))
            return (NULL);
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
    // memset(&philos, 0, sizeof(t_group));
    i = -1;
    while (++i < rules->nb_philo)
    {
        // printf("creating philo %d\n", (i + 1));
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

    if (ac != 5 && ac != 6)
        return (printf("philo: wrong number of arguments\n"), 1);   
    memset(&rules, 0, sizeof(t_rul));
    if (parse(&rules, av))
        return (1);
    philosophers(&rules);
    return (0);
}