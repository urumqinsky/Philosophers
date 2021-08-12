/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlando <rlando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 15:46:33 by rlando            #+#    #+#             */
/*   Updated: 2021/08/11 15:11:41 by rlando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/errno.h>
# define TRUE 1
# define STRERR 2
# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DEATH "\e[0;91mdied\e[0m"

struct	s_struct;

typedef struct s_philo {
	int				id;
	int				fed_up;
	int				left_fork;
	int				right_fork;
	long			last_meal;
	struct s_struct	*all;
}	t_philo;

typedef struct s_struct {
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_meals;
	long			start_point;
	t_philo			*philo;
	pthread_t		*pthreads;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
}	t_struct;

int		check_status(t_struct *all);
int		ft_atoi(const char *str);
int		ft_isdigit(char **av);
int		ft_error(char *s, int code);
void	ft_usleep(long time);
void	ft_free(void *val);
void	ft_wait(int id);
void	ft_printf(char *s, t_philo *p);
long	ft_time(void);
long	ft_time_diff(long current_time);
size_t	ft_strlen(const char *s);

#endif
