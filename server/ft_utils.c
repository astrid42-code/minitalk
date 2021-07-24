/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 20:38:53 by astridgault       #+#    #+#             */
/*   Updated: 2021/07/08 01:01:22 by asgaulti@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr(int nb)
{
	int	n;

	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	n = nb;
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + 48);
	}
	if (n >= 0 && n <= 9)
		ft_putchar((n % 10) + 48);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}
