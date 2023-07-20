/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:36:16 by jklocker          #+#    #+#             */
/*   Updated: 2022/10/20 18:13:44 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	null_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->zero = 0;
	flags->min_width = 0;
	flags->percision = 0;
	flags->length_modifier = 0;
	flags->hash = 0;
}

const char	*set_zero(t_flags *flags, const char *str)
{
	flags->zero = 1;
	if (*(str + 1) >= '0' && *(str + 1) <= '9')
		str++;
	flags->min_width = ft_atoi(str);
	return (str);
}

const char	*set_dot(t_flags *flags, const char *str)
{
	flags->percision = 1;
	if (*(str + 1) >= '0' && *(str + 1) <= '9')
		str++;
	flags->length_modifier = ft_atoi(str);
	return (str);
}

const char	*loop_str(t_flags *flags, const char *str)
{
	if (*str == ' ')
		flags->space = 1;
	else if (*str == '+')
		flags->plus = 1;
	else if (*str == '-')
		flags->minus = 1;
	else if (*str == '#')
		flags->hash = 1;
	else if (*str == '.')
		str = set_dot(flags, str);
	else if (*str == '0')
		str = set_zero(flags, str);
	else if (*str >= '0' && *str <= '9')
		flags->min_width = ft_atoi(str);
	if (*str >= '0' && *str <= '9')
	{
		while (*str >= '0' && *str <= '9')
			str++;
	}
	else
		str++;
	return (str);
}

void	init_flags(t_flags *flags, const char *str)
{
	null_flags(flags);
	while (*str != 'c' && *str != 's' && *str != 'i' && *str != 'd'
		&& *str != 'u' && *str != 'p' && *str != '%' && *str != 'x'
		&& *str != 'X' && *str)
	{
		str = loop_str(flags, str);
	}
}
