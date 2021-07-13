/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astridgaultier <astridgaultier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 20:42:27 by astridgault       #+#    #+#             */
/*   Updated: 2021/07/13 18:27:16 by astridgault      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// où et comment verifie-t-on que le pid ecrit dans client est ok?
// comment afficher un msg d'erreur à ce sujet si on n'envoie pas le pid ici?

void	ft_treat_sigusr(int sig)
{
	char	c;
	int		i;
	
	i = 0;
	c |= (sig << i++);
	if (i == 8)
	{
		if (c == '\0') // si c la fin de la cdc
			write (1, '\n', 1);
		else
			write (1, &c, 1);
	}
}

void	ft_client_signal(int sig)
{
	if (sig == SIGUSR1) // donc 0
		ft_treat_sigusr(0);
	else (sig == SIGUSR2) // donc 1
		ft_treat_sigusr(1);
}

int	main(int ac)
{	
	if (ac != 1)		
		write(1, "Invalid parameters\n", 19);
	else
	{
		write(1, "PID = ", 6);
		ft_putnbr(getpid());
		write(1, "\n", 1);
		exit (EXIT_FAILURE); // verifier qu'exit est autorisé
	}
	if signal(SIGUSR1, action(ft_client_signal) == SIG_ERROR)  // params de signal : n° du signal (un int) et action (dans une fct) à faire avec
	{
		write (1, "Wrong SIGUSR1 signal\n", 21);
		exit (EXIT_FAILURE);
	}
	else if signal(SIGUSR2, action(ft_client_signal) == SIG_ERROR)
	{
		write (1, "Wrong SIGUSR2 signal\n", 21);
		exit (EXIT_FAILURE);
	}
	return (0);
}

// sig_ign : ignorer le signal