/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astridgaultier <astridgaultier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 20:42:27 by astridgault       #+#    #+#             */
/*   Updated: 2021/07/22 16:53:19 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_get_bit(int sig, siginfo_t *info, void *context)
{	
	static unsigned char	c = 0;
	static int				size = 0;

	(void)context;
	if (sig == SIGUSR2)
		c |= (1 << (size));
	size++;
	if (size == 8)
	{
		if (c == '\0')
		{
			if (kill(info->si_pid, SIGUSR1) == -1)
			{
				write (1, "Failure in signal reception\n", 28);
				exit (EXIT_FAILURE);
			}
			write (1, "\nMessage received\n", 18);
		}
		else
			write (1, &c, 1);
		size = 0;
		c = 0;
	}
}

int	main(int ac, char **av)
{	
	struct sigaction	sa;

	(void)av;
	sa.sa_sigaction = ft_get_bit;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (ac != 1)
	{
		write(1, "Invalid parameters\n", 19);
		return (EXIT_FAILURE);
	}
	else
	{
		write(1, "PID = ", 6);
		ft_putnbr(getpid());
		write(1, "\n", 1);
	}
	while (1)
		pause();
	return (0);
}
