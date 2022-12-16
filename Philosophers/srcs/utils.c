/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:00:58 by mpignet           #+#    #+#             */
/*   Updated: 2022/12/16 18:43:32 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t get_time(void)
{
    struct timeval  tv;
    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

time_t time_stamp(time_t start_time)
{
    return (get_time() - start_time);
}

int    print_action(t_philo *philo, char *msg)
{
    if(need_to_stop_program(philo->rules))
        return (1);
    pthread_mutex_lock(&philo->rules->print_mt);
    printf("%ld philo %d %s\n", time_stamp(philo->rules->start_time), philo->id, msg);
    pthread_mutex_unlock(&philo->rules->print_mt);
    return (0);
}