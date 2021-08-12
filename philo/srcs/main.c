/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlando <rlando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 15:46:16 by rlando            #+#    #+#             */
/*   Updated: 2021/08/11 16:18:02 by rlando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*groundhog_day(void	*arg)
{
	t_philo	*p;
	int		everyone_full;

	p = (t_philo *)arg;
	everyone_full = 0;
	while (TRUE)
	{
		ft_wait(p->id);
		pthread_mutex_lock(&p->all->forks[p->left_fork]);
		ft_printf(FORK, p);
		pthread_mutex_lock(&p->all->forks[p->right_fork]);
		ft_printf(FORK, p);
		ft_printf(EAT, p);
		p->last_meal = ft_time();
		ft_usleep(p->all->time_to_eat);
		pthread_mutex_unlock(&p->all->forks[p->right_fork]);
		pthread_mutex_unlock(&p->all->forks[p->left_fork]);
		if (p->all->num_of_meals == ++everyone_full)
			break ;
		ft_printf(SLEEP, p);
		ft_usleep(p->all->time_to_sleep);
		ft_printf(THINK, p);
	}
	p->fed_up = 1;
	return (NULL);
}

static int	init(t_struct *all)
{
	int		i;

	i = -1;
	all->start_point = ft_time();
	pthread_mutex_init(&all->print, NULL);
	while (++i < all->num_of_philo)
	{
		all->philo[i].all = all;
		all->philo[i].id = i + 1;
		all->philo[i].fed_up = 0;
		all->philo[i].left_fork = i;
		all->philo[i].right_fork = (i + 1) % all->num_of_philo;
		all->philo[i].last_meal = all->start_point;
		pthread_mutex_init(&all->forks[i], NULL);
	}
	i = -1;
	while (++i < all->num_of_philo)
	{
		if (pthread_create(&all->pthreads[i], NULL,
				&groundhog_day, &all->philo[i]) != 0)
			return (1);
	}
	return (0);
}

static int	malloc_structs(t_struct *all)
{
	all->philo = (t_philo *)malloc(sizeof(t_philo) * all->num_of_philo);
	if (all->philo == NULL)
		return (1);
	all->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* all->num_of_philo);
	if (all->forks == NULL)
	{
		free(all->philo);
		return (1);
	}
	all->pthreads = (pthread_t *)malloc(sizeof(pthread_t) * all->num_of_philo);
	if (all->pthreads == NULL)
	{
		free(all->philo);
		free(all->forks);
		return (1);
	}
	return (0);
}

static int	parse(int ac, char **av, t_struct *philo)
{
	if (ft_isdigit(av))
		return (1);
	philo->num_of_philo = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		philo->num_of_meals = ft_atoi(av[5]);
	else
		philo->num_of_meals = -1;
	if (philo->num_of_philo < 1 || philo->time_to_die < 1
		|| philo->time_to_eat < 1 || philo->time_to_sleep < 1
		|| (ac == 6 && philo->num_of_meals < 1))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int			i;
	t_struct	all;

	if (argc != 5 && argc != 6)
		return (ft_error("Invalid number of arguments", EINVAL));
	if (parse(argc, argv, &all))
		return (ft_error("Invalid arguments", EINVAL));
	if (malloc_structs(&all))
		return (ft_error("Memory not allocated", ENOMEM));
	if (init(&all))
		return (ft_error("Failed to create a process thread", ENOEXEC));
	i = -1;
	while (++i < all.num_of_philo)
		pthread_detach(all.pthreads[i]);
	check_status(&all);
	i = -1;
	while (++i < all.num_of_philo)
		pthread_mutex_destroy(&all.forks[i]);
	pthread_mutex_destroy(&all.print);
	free(all.forks);
	free(all.pthreads);
	free(all.philo);
	return (0);
}
