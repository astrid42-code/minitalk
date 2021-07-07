/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 20:42:44 by astridgault       #+#    #+#             */
/*   Updated: 2021/07/08 01:09:25 by asgaulti@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	pid_t	pid;
	int		nbr;

	pid = 0;
	if (ac != 3)
	{
		write(1, "Wrong number of arguments\n", 26);
		EXIT_FAILURE;
	}
	else
	{
		nbr = ft_atoi(av[1]);
		if (ft_isdigit(nbr) == 0)
		{
			write(1, "First argument is not a number\n", 31);
			return (1); // ou exit?
		}
		pid = ft_atoi(av[1]);
	}
	if (pid <= 1)
	{
		write(1, "Wrong PID\n", 10);
		EXIT_FAILURE;
	}
	//ft_treat_arg(pid, av[2]);
		// envoyer l'arg[2] en binaire au client
		//recevoir le signal du serveur et l'envoyer aux fcts qui traduisent le binaire recu en char / int ...
	return (0);
}