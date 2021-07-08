/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 12:17:53 by asgaulti          #+#    #+#             */
/*   Updated: 2021/07/08 01:08:31 by asgaulti@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int	main(int ac, char **av);

// utils
int	ft_isalnum(int c);
int	ft_isalpha(int c);
int	ft_isdigit(char c);
int	ft_atoi(const char *str);
void	ft_putnbr(int nb);
int	ft_strlen(char *str);
void	ft_putchar(char c);

#endif