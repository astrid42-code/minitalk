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

int	main(int ac, char **av)
{
	pid_t	pid;
	int		j;

	pid = 0;
	if (ac != 3)
	{
		write(1, "Wrong number of arguments\n", 26);
		exit (EXIT_FAILURE);
	}
	else
	{
		j = 0;
		while (av[1][j])
		{
			if (ft_isdigit(av[1][j]) == 0)
			{
				write(1, "First argument is not a number\n", 31);
				exit (EXIT_FAILURE);
			}
			j++;
		}
		pid = ft_atoi(av[1]);
		printf("PID = %d av = %s\n", pid, av[1]);
	}
	// comment vérifier que c le meme pid que celui du server??
/*	if (pid <= 1)
	{
		write(1, "Wrong PID\n", 10);
		exit (EXIT_FAILURE);
	}
*/	ft_find_bit(pid, av[2]);
	return (0);
}

void	ft_find_bit(int pid, char *str)
{
	int bit;
	int count;
	int i;

	i = 0;
	bit = 0;
	while (str[i])
	{
		count = 0;
		while (count < 8)
		{
			bit |= (str[i] >> count++);
			ft_send_signal(pid, bit);
		}
		i++;
	}
}

void	ft_send_signal(int pid, int bit)
{
	if (bit == 0)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			write(1, "Sigusr1 error\n", 14);
			exit (EXIT_FAILURE);
		}
	}
	if (bit == 1)
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			write(1, "Sigusr2 error\n", 14);
			exit (EXIT_FAILURE);
		}
	}
}