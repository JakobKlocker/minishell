/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_found.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:58:13 by jklocker          #+#    #+#             */
/*   Updated: 2022/10/20 14:34:27 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ptr_found(char *str, void *ptr, t_flags *flags, int *counter)
{
	ptr_flags(str, ptr, flags, counter);
	ft_putnbr_base_p(ptr, "0123456789abcdef", counter);
	check_minus_flag(flags, counter);
}

void	ptr_flags(char *str, void *ptr, t_flags *flags, int *counter)
{
	init_flags(flags, str);
	flags->var_length = hex_len_ptr(ptr);
	if (flags->percision == 1 && flags->length_modifier <= flags->var_length)
		flags->var_length = flags->length_modifier;
	print_min_width(flags, counter);
}
