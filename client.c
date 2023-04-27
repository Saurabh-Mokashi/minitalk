/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokashi <smokashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:15:45 by smokashi          #+#    #+#             */
/*   Updated: 2023/04/27 17:05:44 by smokashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int				sign;
	unsigned int	num;

	sign = 1;
	num = 0;
	while (*str == ' ' || *str == '\t' || *str == '\r' || *str == '\n' \
			||*str == '\v' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - '0');
		str++;
	}
	if (num > 2147483647 && sign == 1)
		return (-1);
	if (num > 2147483648 && sign == -1)
		return (0);
	return (num * sign);
}

void	fn(int t, unsigned char c, int pid)
{
	while (t > 0)
	{
		if (c / t == 1)
		{
			kill(pid, SIGUSR1);
			c = c - t;
		}
		else
			kill(pid, SIGUSR2);
		usleep(150);
		t = t / 2;
	}
}

int	main(int ac, char **agv)
{
	int		i;
	pid_t	pid;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(agv[1]);
		if (pid <= 0)
			return (0);
		while (agv[2][i])
		{
			fn(128, agv[2][i], pid);
			i++;
		}
	}
	else
		write(1, "only 2 args, first pid and second as string allowed\n", 52);
}
