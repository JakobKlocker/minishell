/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_big_found.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:25:51 by jklocker          #+#    #+#             */
/*   Updated: 2022/10/20 14:33:54 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hex_big_found(char *str, unsigned int var, t_flags *flags, int *counter)
{
	hex_flags(str, var, flags, counter);
	hash_flag_big(var, flags, counter);
	if (var == 0 && flags->percision == 1 && flags->length_modifier == 0)
	{
		flags->var_length = 0;
		u_int_check_minus_flag(flags, counter);
		return ;
	}
	ft_putnbr_base_c(var, "0123456789ABCDEF", counter);
	u_int_check_minus_flag(flags, counter);
}

void	hash_flag_big(unsigned int var, t_flags *flags, int *counter)
{
	if (var != 0 && flags->hash == 1)
	{
		write(1, "0X", 2);
		*counter = *counter + 2;
	}
}
