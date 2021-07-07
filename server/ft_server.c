/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 20:42:27 by astridgault       #+#    #+#             */
/*   Updated: 2021/07/08 01:16:27 by asgaulti@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	(void)av;
	
	if (ac != 1)		
		write(1, "Invalid parameters\n", 19);
	else
	{
		write(1, "PID = ", 6);
		ft_putnbr(getpid());
		write(1, "\n", 1);
	}
	return (0);
}