/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_int_found.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:01:29 by jklocker          #+#    #+#             */
/*   Updated: 2022/10/20 14:33:27 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	u_int_found(char *str, unsigned int var, t_flags *flags, int *counter)
{
	u_int_flags(str, var, flags, counter);
	if (var == 0 && flags->percision == 1 && flags->length_modifier == 0)
	{
		flags->var_length = 0;
		u_int_check_minus_flag(flags, counter);
		return ;
	}
	ft_putnbr_u_fd_c(var, 1, counter);
	u_int_check_minus_flag(flags, counter);
}

void	u_int_flags(char *str, unsigned int var, t_flags *flags, int *counter)
{
	init_flags(flags, str);
	flags->var_length = int_len_u(var);
	if (var == 0 && flags->percision == 1 && flags->length_modifier == 0)
		flags->var_length = 0;
	int_flag_space(var, flags, counter);
	if (flags->plus == 1)
		flags->var_length = flags->var_length + 1;
	u_int_print_min_width(flags, counter);
	u_int_flag_plus(flags, counter);
	int_flag_zero(flags, counter);
	u_int_flag_percision(flags, counter);
}

void	u_int_check_minus_flag(t_flags *flags, int *counter)
{
	int	c;

	if (flags->percision == 1 && flags->length_modifier >= flags->var_length)
		c = flags->min_width - flags->length_modifier;
	else
		c = flags->min_width - flags->var_length;
	if (flags->percision == 1 && flags->length_modifier >= flags->var_length
		&& flags->plus == 1)
		c++;
	if (flags->minus == 1)
	{
		while (c > 0)
		{
			ft_putchar_fd_c(' ', 1, counter);
			c--;
		}
	}
}

void	u_int_print_min_width(t_flags *flags, int *counter)
{
	int	c;

	if (flags->percision == 1 && flags->length_modifier >= flags->var_length)
		c = flags->min_width - flags->length_modifier;
	else
		c = flags->min_width - flags->var_length;
	if (flags->percision == 1 && flags->length_modifier >= flags->var_length
		&& (flags->plus == 1))
		c--;
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

void	u_int_flag_plus(t_flags *flags, int *counter)
{
	if (flags->plus == 1)
	{
		ft_putchar_fd_c('+', 1, counter);
	}
}
