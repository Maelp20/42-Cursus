/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:00:37 by mpignet           #+#    #+#             */
/*   Updated: 2022/11/29 15:46:47 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

typedef struct  s_counter
{
    pthread_mutex_t count_mutex;
    unsigned int    count;    
}   t_counter;

void    *thread_routine(void *data)
{
    pthread_t   tid;
    t_counter   *counter;
    unsigned int i = -1;

    tid = pthread_self();
    counter = (t_counter *)data;
    pthread_mutex_lock(&counter->count_mutex);
    printf("%sThread[%ld]: start count = %u.%s\n", YELLOW, tid, counter->count, NC);
    pthread_mutex_unlock(&counter->count_mutex);
    while (++i < TIMES_TO_COUNT)
    {
        pthread_mutex_lock(&counter->count_mutex);
        counter->count++;
        pthread_mutex_unlock(&counter->count_mutex);
    }
    pthread_mutex_lock(&counter->count_mutex);
    printf("%sThread[%ld]: end count = %u.%s\n", BYELLOW, tid, counter->count, NC);
    pthread_mutex_unlock(&counter->count_mutex);
    return (NULL);
}

int	main(void)
{
	pthread_t   tid1;
    pthread_t   tid2;
    t_counter   counter;

    counter.count = 0;
    pthread_mutex_init(&counter.count_mutex, NULL);
	printf("Main: Le compte attendu est de %s%u%s\n", GREEN, 2 * TIMES_TO_COUNT, NC);
    pthread_create(&tid1, NULL, thread_routine, &counter);
    printf("Main: Creating first thread [%ld]\n", tid1);
    pthread_create(&tid2, NULL, thread_routine, &counter);
    printf("Main: Creating scnd thread [%ld]\n", tid2);
    pthread_join(tid1, NULL);
    printf("Main: First thread union [%ld]\n", tid1);
    pthread_join(tid2, NULL);
    printf("Main: Scnd thread union [%ld]\n", tid2);
    if ( counter.count != 2 * TIMES_TO_COUNT)
        printf ("%sMain: ERR ! count is %u%s\n", RED, counter.count, NC);
    else
        printf ("%sMain: OK ! count is %u%s\n", GREEN, counter.count, NC);
    pthread_mutex_destroy(&counter.count_mutex);
    return (0);
}