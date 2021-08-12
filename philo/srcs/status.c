/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlando <rlando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 13:55:59 by rlando            #+#    #+#             */
/*   Updated: 2021/08/11 15:49:27 by rlando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_printf(char *s, t_philo *p)
{		
	printf("\e[0;92m%ld\e[0m\t%d %s\n",
		ft_time_diff(p->all->start_point), p->id, s);
}

int	ft_error(char *s, int code)
{
	write(STRERR, "Error: ", 7);
	write(STRERR, s, ft_strlen(s));
	write(STRERR, "\n", 1);
	return (code);
}

int	check_status(t_struct *all)
{
	int	i;
	int	satiety_stat;

	satiety_stat = 0;
	while (TRUE)
	{
		i = 0;
		while (i < all->num_of_philo)
		{
			if (all->philo[i].fed_up == 1)
				all->philo[i].fed_up = ++satiety_stat;
			if (satiety_stat == all->num_of_philo && all->num_of_meals > 0)
				return (0);
			if (all->philo[i].fed_up == 0
				&& ft_time_diff(all->philo[i].last_meal) > all->time_to_die)
			{
				pthread_mutex_lock(&all->print);
				ft_printf(DEATH, &all->philo[i]);
				return (0);
			}
			i++;
			usleep(200);
		}
	}
	return (0);
}
