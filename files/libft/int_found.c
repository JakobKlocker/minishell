/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_found.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:07:49 by jklocker          #+#    #+#             */
/*   Updated: 2022/10/20 18:04:44 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int_found(char *str, int var, t_flags *flags, int *counter)
{
	int_flags(str, var, flags, counter);
	if (var == 0 && flags->percision == 1 && flags->length_modifier == 0)
	{
		flags->var_length = 0;
		int_check_minus_flag(flags, counter, var);
		return ;
	}
	ft_putnbr_fd_c((long)var, 1, counter);
	int_check_minus_flag(flags, counter, var);
}

void	int_flags(char *str, int var, t_flags *flags, int *counter)
{
	init_flags(flags, str);
	flags->var_length = int_len(var);
	if (var == 0 && flags->percision == 1 && flags->length_modifier == 0)
		flags->var_length = 0;
	int_flag_space(var, flags, counter);
	if (flags->plus == 1 && var >= 0)
		flags->var_length = flags->var_length + 1;
	int_print_min_width(flags, counter, var);
	int_flag_plus(var, flags, counter);
	if (var < 0)
		ft_putchar_fd_c('-', 1, counter);
	int_flag_zero(flags, counter);
	int_flag_percision(flags, counter, var);
}

void	int_print_min_width(t_flags *flags, int *counter, int var)
{
	int	c;

	if (flags->percision == 1 && flags->length_modifier >= flags->var_length)
		c = flags->min_width - flags->length_modifier;
	else
		c = flags->min_width - flags->var_length;
	if (flags->percision == 1 && flags->length_modifier >= flags->var_length
		&& (var < 0 || flags->plus == 1))
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

void	int_check_minus_flag(t_flags *flags, int *counter, int var)
{
	int	c;

	if (flags->percision == 1 && flags->length_modifier >= flags->var_length)
		c = flags->min_width - flags->length_modifier;
	else
		c = flags->min_width - flags->var_length;
	if (flags->percision == 1 && flags->length_modifier >= flags->var_length
		&& (var < 0 || flags->plus == 1))
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

void	int_flag_zero(t_flags *flags, int *counter)
{
	int	c;

	if (flags->zero == 1 && flags->minus == 0 && flags->percision == 0)
	{
		c = flags->min_width - flags->var_length;
		{
			while (c > 0)
			{
				ft_putchar_fd_c('0', 1, counter);
				c--;
			}
		}
	}
}
