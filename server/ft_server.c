/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astridgaultier <astridgaultier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 20:42:27 by astridgault       #+#    #+#             */
/*   Updated: 2021/07/17 11:46:07 by astridgault      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// où et comment verifie-t-on que le pid ecrit dans client est ok?
// comment afficher un msg d'erreur à ce sujet si on n'envoie pas le pid ici?

void	ft_get_bit(int sig)
{	
	static unsigned char	c = 0;
	static int				size = 0;

	//c = 0;
	//size = 0;
	c |= (sig << (7 - size++));
	//size++;
	printf("c = %d size = %d\n", c, size);
	if (size == 8)
	{
		if (c == '\0') // si c la fin de la cdc
			write (1, "\n", 1);
		else
			write (1, &c, 1);
		//puts("che");
		size = 0;
		c = 0;
	}
}
/*
void	ft_get_signal(t_bit *bit, int sig)
{
	if (sig == SIGUSR1) // donc 0
		ft_treat_sigusr(bit, 0);
	else if (sig == SIGUSR2) // donc 1
		ft_treat_sigusr(bit, 1);
}
*/
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
	while (1)
	{
		signal(SIGUSR1, ft_get_bit);
		signal(SIGUSR2, ft_get_bit);	
/*		if (signal(SIGUSR1, ft_get_bit) == SIG_ERR)  // params de signal : n° du signal (un int) et action (dans une fct) à faire avec
		{
			write (1, "Wrong SIGUSR1 signal\n", 21);
			exit (EXIT_FAILURE); // verifier qu'exit est autorisé
		}
		else if (signal(SIGUSR2, ft_get_bit) == SIG_ERR)
		{
			write (1, "Wrong SIGUSR2 signal\n", 21);
			exit (EXIT_FAILURE);
		}
*/		pause();
	}
	return (0);
}

// sig_ign : ignorer le signal