/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokashi <smokashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:15:35 by smokashi          #+#    #+#             */
/*   Updated: 2022/07/22 20:34:55 by smokashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <signal.h>

// int count = 0;
// char arr[8];

// void ft_putchar_fd(char c, int fd)
// {
// 	write(1, &c, fd);
// }

// void	rec(long int n, int fd)
// {
// 	if (n >= 10)
// 		rec(n / 10, fd);
// 	ft_putchar_fd(((long int)n % 10) + '0', fd);
// }

// void	ft_putnbr_fd(int p, int fd)
// {
// 	long int	n;

// 	if (p < 0)
// 	{
// 		if (p == -2147483648)
// 		{
// 			write (fd, "-2147483648", 11);
// 			return ;
// 		}
// 		ft_putchar_fd('-', fd);
// 		n = (long int)(-1 * p);
// 	}
// 	else
// 		n = (long int)(p);
// 	rec(n, fd);
// 	write(1,"\n",1);
// }

// void sighandle(int sig)
// {
// 	static int i = 0;
// 	static char c = 0;
// 	// c = c | (sig == SIGUSR1);
// 	// if (++i == 8)
// 	// {
// 	// 	// usleep(10);
// 	// 	i = 0;
// 	// 	ft_putchar_fd(c,1);
// 	// 	// write(1,&c,1);
// 	// 	// write(1,&c,8);
// 	// 	c = 0;
// 	// }
// 	// else
// 	// 	c <<= 1;
// 	if (sig == SIGUSR1)
// 		c = c|1;
// 	// usleep(10);
// 	i++;
// 	if(i == 8)
// 	{
// 		i = 0;
// 		write(1,&c,1);
// 		c = 0;
// 	}
// 	else
// 		c<<=1;
// }

// int main()
// {
// 	int a = getpid();
// 	ft_putnbr_fd(a, 1);
// 	signal(SIGUSR1, sighandle);
// 	signal(SIGUSR2,sighandle);
// 	while(1) ;
// 	return (0);
// }

void	ft_putchar_fd(char c, int fd)
{
	write(1, &c, fd);
}

void	rec(long int n, int fd)
{
	if (n >= 10)
		rec(n / 10, fd);
	ft_putchar_fd(((long int)n % 10) + '0', fd);
}

void	ft_putnbr_fd(int p, int fd)
{
	long int	n;

	if (p < 0)
	{
		if (p == -2147483648)
		{
			write (fd, "-2147483648", 11);
			return ;
		}
		ft_putchar_fd('-', fd);
		n = (long int)(-1 * p);
	}
	else
		n = (long int)(p);
	rec(n, fd);
	write(1, "\n", 1);
}

void	sighandle(int sig)
{
	static int	i = 0;
	static char	c = 0;

	if (sig == SIGUSR1)
		c = c | 1;
	i++;
	if (i == 8)
	{
		i = 0;
		write (1, &c, 1);
		// usleep(500);
		c = 0;
	}
	else
		c = c << 1;
}

int	main(void)
{
	int	a;

	a = getpid();
	ft_putnbr_fd(a, 1);
	signal(SIGUSR1, sighandle);
	signal(SIGUSR2, sighandle);
	while (1)
		;
	return (0);
}
