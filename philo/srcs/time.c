/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlando <rlando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 13:42:02 by rlando            #+#    #+#             */
/*   Updated: 2021/08/11 16:18:18 by rlando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long time)
{
	long	val;

	val = ft_time() + time;
	while (ft_time() < val)
		usleep(time);
}

long	ft_time(void)
{
	long			res;
	struct timeval	timeval;

	gettimeofday(&timeval, NULL);
	res = (timeval.tv_sec * 1000) + (timeval.tv_usec / 1000);
	return (res);
}

long	ft_time_diff(long current_time)
{
	long	res;

	res = ft_time() - current_time;
	return (res);
}

void	ft_wait(int id)
{
	if (id % 2 == 0)
		usleep(200);
}
