/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_found.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:25:51 by jklocker          #+#    #+#             */
/*   Updated: 2022/10/20 14:33:59 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hex_found(char *str, unsigned int var, t_flags *flags, int *counter)
{
	hex_flags(str, var, flags, counter);
	hash_flag_small(var, flags, counter);
	if (var == 0 && flags->percision == 1 && flags->length_modifier == 0)
	{
		flags->var_length = 0;
		u_int_check_minus_flag(flags, counter);
		return ;
	}
	ft_putnbr_base_c(var, "0123456789abcdef", counter);
	u_int_check_minus_flag(flags, counter);
}

void	hex_flags(char *str, unsigned int var, t_flags *flags, int *counter)
{
	init_flags(flags, str);
	flags->var_length = hex_len(var);
	if (var == 0 && flags->percision == 1 && flags->length_modifier == 0)
		flags->var_length = 0;
	u_int_print_min_width(flags, counter);
	int_flag_zero(flags, counter);
	u_int_flag_percision(flags, counter);
}

void	hash_flag_small(unsigned int var, t_flags *flags, int *counter)
{
	if (var != 0 && flags->hash == 1)
	{
		write(1, "0x", 2);
		*counter = *counter + 2;
	}
}

/*
void	_flag_percision(t_flags *flags, int *counter, int var)
{
	int	c;

	if (flags->percision == 1)
	{
		if ((var < 0 || ((flags->plus == 1 && var >= 0)
			&& flags->length_modifier >= flags->var_length)))
		{
			flags->length_modifier = flags->length_modifier + 2;
			flags->var_length = flags->var_length + 1;
		}
		c = flags->var_length;
		{
			while (flags->length_modifier > c)
			{
				ft_putchar_fd_c('0', 1, counter);
				c++;
			}
		}
	}
}
*/