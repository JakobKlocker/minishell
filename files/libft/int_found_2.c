/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_found_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:28:43 by jklocker          #+#    #+#             */
/*   Updated: 2022/10/20 17:58:46 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int_flag_space(int var, t_flags *flags, int *counter)
{
	if (flags->space == 1 && flags->plus == 0 && var >= 0)
	{
		ft_putchar_fd_c(' ', 1, counter);
	}
}

void	int_flag_plus(int var, t_flags *flags, int *counter)
{
	if (flags->plus == 1 && var >= 0)
	{
		ft_putchar_fd_c('+', 1, counter);
	}
}

void	int_flag_percision(t_flags *flags, int *counter, int var)
{
	int	c;

	if (flags->percision == 1 && flags->length_modifier >= flags->var_length)
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
