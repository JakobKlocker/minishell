/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_found.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:27:49 by jklocker          #+#    #+#             */
/*   Updated: 2022/10/20 14:32:12 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	char_found(char *str, char var, t_flags *flags, int *counter)
{
	char_flags(str, flags, counter);
	ft_putchar_fd_c(var, 1, counter);
	check_minus_flag(flags, counter);
}

void	char_flags(char *str, t_flags *flags, int *counter)
{
	init_flags(flags, str);
	flags->var_length = 1;
	print_min_width(flags, counter);
}

void	print_min_width(t_flags *flags, int *counter)
{
	int	c;

	c = flags->min_width - flags->var_length;
	if (flags->minus != 1 && flags->zero == 0)
	{
		while (c > 0)
		{
			ft_putchar_fd_c(' ', 1, counter);
			c--;
		}
	}
}

void	check_minus_flag(t_flags *flags, int *counter)
{
	int	c;

	c = flags->min_width - flags->var_length;
	if (flags->minus == 1)
	{
		while (c > 0)
		{
			ft_putchar_fd_c(' ', 1, counter);
			c--;
		}
	}
}

void	ft_putchar_fd_c(char c, int fd, int *counter)
{
	write(fd, &c, 1);
	*counter = *counter + 1;
}
