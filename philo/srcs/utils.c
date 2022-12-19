/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:00:58 by mpignet           #+#    #+#             */
/*   Updated: 2022/12/19 17:08:22 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_put_error(char *s)
{
	write (2, s, ft_strlen(s));
}

int ft_usleep(t_rul *rules, time_t time)
{
    time_t  waittime;

    waittime = get_time() + time;
    while (get_time() < waittime)
    {
        if (need_to_stop_program(rules))
            return (1);
        usleep(10);
    }
    return (0);
}

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
    if(need_to_stop_program(philo->rules))
        return (pthread_mutex_unlock(&philo->rules->print_mt), 1);
    printf("%ld %d %s\n", time_stamp(philo->rules->start_time), philo->id, msg);
    pthread_mutex_unlock(&philo->rules->print_mt);
    return (0);
}