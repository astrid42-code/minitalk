/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astridgaultier <astridgaultier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 12:17:53 by asgaulti          #+#    #+#             */
/*   Updated: 2021/07/13 18:17:16 by astridgault      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <sys/types.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		main(int ac, char **av);
void	ft_get_msg(int signal_num, siginfo_t *info, void *context);
bool	ft_check_av(char **av);
void	ft_find_bit(int pid, char *str);
void	ft_send_signal(int pid, int bit);
void	ft_get_bit(int sig, siginfo_t *info, void *context);
int		ft_isdigit(char c);
int		ft_atoi(const char *str);
void	ft_putnbr(int nb);
void	ft_putchar(char c);

#endif