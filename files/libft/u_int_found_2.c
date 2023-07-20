/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_int_found_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:32:55 by jklocker          #+#    #+#             */
/*   Updated: 2022/10/20 14:34:58 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	u_int_flag_percision(t_flags *flags, int *counter)
{
	int	c;

	if (flags->percision == 1)
	{
		if (flags->plus == 1 && flags->length_modifier >= flags->var_length)
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
