/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_found.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:23:33 by jklocker          #+#    #+#             */
/*   Updated: 2022/10/20 17:40:44 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	str_found(char *str, char *var, t_flags *flags, int *counter)
{
	str_flags(str, var, flags, counter);
	if (var == NULL && flags->percision == 1 && flags->length_modifier < 6)
	{
		check_minus_flag(flags, counter);
		return ;
	}
	if (flags->percision == 0)
		ft_putstr_fd_c(var, 1, counter);
	else
		ft_putstr_fd_n_c(var, 1, counter, flags->length_modifier);
	check_minus_flag(flags, counter);
}

void	str_flags(char *str, char *var, t_flags *flags, int *counter)
{
	init_flags(flags, str);
	flags->var_length = ft_strlen_n(var);
	if (flags->percision == 1 && flags->length_modifier <= flags->var_length)
		flags->var_length = flags->length_modifier;
	if (var == NULL && flags->percision == 1 && flags->length_modifier < 6)
		flags->var_length = 0;
	print_min_width(flags, counter);
}

/*
void	str_print_min_width(t_flags *flags, int *counter)
{
	int	c;

	c = flags->min_width - flags->var_length;
	if ((flags->minus != 1 && flags->zero == 0) || (flags->minus != 1
			&& flags->percision == 1))
	{
		while (c > 0)
		{
			ft_putchar_fd_c(' ', 1, counter);
			c--;
		}
	}
}
*/

void	ft_putstr_fd_n_c(char *s, int fd, int *counter, int n)
{
	int	i;

	i = 0;
	if (!s || !fd)
	{
		write(1, "(null)", 6);
		*counter = *counter + 6;
		return ;
	}
	while (*s && i < n)
	{
		write(fd, s, 1);
		*counter = *counter + 1;
		s++;
		i++;
	}
}

void	ft_putstr_fd_c(char *s, int fd, int *counter)
{
	if (!s || !fd)
	{
		write(1, "(null)", 6);
		*counter = *counter + 6;
		return ;
	}
	while (*s)
	{
		write(fd, s, 1);
		*counter = *counter + 1;
		s++;
	}
}
