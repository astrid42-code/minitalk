/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astridgaultier <astridgaultier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 12:17:53 by asgaulti          #+#    #+#             */
/*   Updated: 2021/07/12 14:52:48 by astridgault      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int     main(int ac, char **av);
void	ft_find_bit(int pid, char *str);
void	ft_send_signal(int pid, int bit);

// utils
int	    ft_isalnum(int c);
int	    ft_isalpha(int c);
int	    ft_isdigit(char c);
int	    ft_atoi(const char *str);
void	ft_putnbr(int nb);
int	    ft_strlen(char *str);
void	ft_putchar(char c);

#endif