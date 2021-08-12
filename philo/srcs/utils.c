/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlando <rlando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 15:46:41 by rlando            #+#    #+#             */
/*   Updated: 2021/08/11 14:33:01 by rlando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_isdigit(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
			if (av[i][j] < 48 || av[i][j] > 57)
				return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	res;

	sign = 1;
	res = 0;
	while (*str == 32 || (*str > 8 && *str < 14))
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			sign = sign * -1;
		str++;
	}
	while (*str > 47 && *str < 58)
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	return (res * sign);
}
