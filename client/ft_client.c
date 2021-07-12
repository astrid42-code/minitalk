/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astridgaultier <astridgaultier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 20:42:44 by astridgault       #+#    #+#             */
/*   Updated: 2021/07/12 14:57:50 by astridgault      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	pid_t	pid;
	int		j;
	//int		nbr;

	pid = 0;
	if (ac != 3)
	{
		write(1, "Wrong number of arguments\n", 26);
		EXIT_FAILURE;
	}
	else
	{
		j = 0;
		while (av[1][j])
		{
			if (ft_isdigit(av[1][j]) == 0)
			{
				write(1, "First argument is not a number\n", 31);
				return (1); // ou exit?
			}
			j++;
		}
		pid = ft_atoi(av[1]);
	}
	if (pid <= 1)
	{
		write(1, "Wrong PID\n", 10);
		EXIT_FAILURE;
	}
	ft_treat_arg(pid, av[2]);
	return (0);
}

void	ft_find_bit(int pid, char *str)
{
	int bit;
	int count;
	int i;

	count = 0;
	i = 0;
	while (str[i])
	{
		c = 0;
		while (c < 8)
		{
			bit |= (str[i] >> c++);
			ft_send_sig(pid, bit);
		}
		i++;
	}
}

void	ft_send_sig(int pid, int bit)
{
	if (bit == 0)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			write(1, "Sigusr1 error\n", 14);
			EXIT_FAILURE;
		}
	}
	if (bit == 1)
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			write(1, "Sigusr2 error\n", 14);
			EXIT_FAILURE;
		}
	}
}