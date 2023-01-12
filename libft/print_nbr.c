/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 09:02:17 by jklocker          #+#    #+#             */
/*   Updated: 2022/10/20 14:34:11 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd_c(long n, int fd, int *counter)
{
	if (n < 0)
		n = n * -1;
	if (n > 9)
	{
		ft_putnbr_fd_c(n / 10, fd, counter);
		ft_putnbr_fd_c(n % 10, fd, counter);
	}
	else if (n <= 9)
		ft_putchar_fd_c(n + '0', fd, counter);
}

void	ft_putnbr_u_fd_c(unsigned int n, int fd, int *counter)
{
	if (n > 9)
	{
		ft_putnbr_u_fd_c(n / 10, fd, counter);
		ft_putnbr_u_fd_c(n % 10, fd, counter);
	}
	else if (n <= 9)
	{
		ft_putchar_fd_c(n + '0', fd, counter);
	}
}
