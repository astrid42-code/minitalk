/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astridgaultier <astridgaultier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 20:42:44 by astridgault       #+#    #+#             */
/*   Updated: 2021/07/13 17:56:29 by astridgault      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_get_msg(int signal_num, siginfo_t *info, void *context)
{
	(void)signal_num;
	(void)context;
	(void)info;
	write(1, "Message received by server\n", 27);
	exit(EXIT_SUCCESS);
}

void	ft_find_bit(int pid, char *str)
{
	int	bit;
	int	count;
	int	i;

	i = 0;
	while (str[i])
	{
		bit = 0;
		count = 0;
		while (count < 8)
		{
			bit = (str[i] >> count++) & 1;
			ft_send_signal(pid, bit);
			usleep(42);
		}
		i++;
	}
	count = 0;
	while (count < 8)
	{
		bit = ('\0' >> count++) & 1;
		ft_send_signal(pid, bit);
		usleep(42);
	}
}

void	ft_send_signal(int pid, int bit)
{
	if (bit == 0)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			write(1, "Error : signal not send\n", 24);
			exit (EXIT_FAILURE);
		}
	}
	if (bit == 1)
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			write(1, "Error : signal not send\n", 24);
			exit (EXIT_FAILURE);
		}
	}
}

/*
** Check if PID is only number
**
**	@param av Argv argument
**
**	@return true if only number, false otherwise
*/
bool	ft_check_av(char **av)
{
	int	j;

	j = 0;
	while (av[1][j])
	{
		if (ft_isdigit(av[1][j]) == 0)
		{
			return (false);
		}
		j++;
	}
	return (true);
}

int	main(int ac, char **av)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = 0;
	if (ac != 3)
	{
		write(1, "Wrong number of arguments\n", 26);
		exit (EXIT_FAILURE);
	}
	else
	{
		sa.sa_sigaction = ft_get_msg;
		sa.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &sa, NULL);
		pid = ft_atoi(av[1]);
		if (ft_check_av(av) == false || pid < 1)
		{
			write (1, "Wrong PID\n", 10);
			exit (EXIT_FAILURE);
		}
	}
	ft_find_bit(pid, av[2]);
	return (0);
}
