/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokashi <smokashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:13:58 by smokashi          #+#    #+#             */
/*   Updated: 2023/04/27 16:50:44 by smokashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <signal.h>

// void	ft_putchar_fd(char c, int fd)
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
// 	write(1, "\n", 1);
// }

// void	sighandle(int sig)
// {
// 	static int	i = 0;
// 	static char	c = 0;

// 	if (sig == SIGUSR1)
// 		c = c | 1;
// 	i++;
// 	if (i == 8)
// 	{
// 		i = 0;
// 		write (1, &c, 1);
// 		usleep(100);
// 		c = 0;
// 	}
// 	else
// 		c <<= 1;
// }

// int	main(void)
// {
// 	int	a;
// 	struct sigaction sa ;

// 	a = getpid();
// 	ft_putnbr_fd(a, 1);
// 	// signal(SIGUSR1, sighandle);
// 	// signal(SIGUSR2, sighandle);
// 	sa.sa_handler = &sighandle;
// 	sigaction(SIGUSR1, &sa, NULL);
// 	sigaction(SIGUSR2, &sa, NULL);
// 	while (1)
// 		;
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

void	sighandle(int sig, siginfo_t *siginfo, void *hrl)
{
	static int	i = 0;
	static char	c = 0;
	int			j;

	(void)hrl;
	if (sig == SIGUSR1)
		c = c | 1;
	i++;
	if (i == 8)
	{
		i = 0;
		if (c == '\0')
		{
			usleep(300);
			j = kill(siginfo->si_pid, SIGUSR1);
		}
		else
			write (1, &c, 1);
		c = 0;
	}
	else
		c = c << 1;
}

int	main(int argc, char **argv)
{
	int					a;
	struct sigaction	sa;

	(void) argv;
	if (argc == 1)
	{
		a = getpid();
		ft_putnbr_fd(a, 1);
		sa.sa_flags = SA_SIGINFO;
		sa.sa_sigaction = sighandle;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		while (1)
			;
		return (0);
	}
	else
		write(1, "Wrong format \"./server_bonus\"\n", 30);
}
