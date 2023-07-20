/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:30:21 by jklocker          #+#    #+#             */
/*   Updated: 2022/10/20 18:15:17 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
#include "char_found.c"
#include "ft_printf.h"
#include "get_var_len.c"
#include "hex_big_found.c"
#include "hex_found.c"
#include "init_flags.c"
#include "int_found.c"
#include "print_hex_p.c"
#include "print_nbr.c"
#include "ptr_found.c"
#include "str_found.c"
#include "u_int_found.c"
#include "int_found_2.c"
#include "u_int_found_2.c"
*/

const char	*ft_manage_arg(const char *str, va_list ap, t_flags *flags,
		int *counter)
{
	int	i;

	i = 0;
	while (str[i] != 'c' && str[i] != 's' && str[i] != 'i' && str[i] != 'd'
		&& str[i] != 'u' && str[i] != 'p' && str[i] != '%' && str[i] != 'x'
		&& str[i] != 'X' && str[i])
		i++;
	if (str[i] == 'c')
		char_found((char *)str, (char)va_arg(ap, int), flags, counter);
	else if (str[i] == 's')
		str_found((char *)str, va_arg(ap, char *), flags, counter);
	else if (str[i] == 'p')
		ptr_found((char *)str, va_arg(ap, void *), flags, counter);
	else if (str[i] == 'i' || str[i] == 'd')
		int_found((char *)str, va_arg(ap, int), flags, counter);
	else if (str[i] == 'u')
		u_int_found((char *)str, va_arg(ap, unsigned int), flags, counter);
	else if (str[i] == 'x')
		hex_found((char *)str, va_arg(ap, unsigned int), flags, counter);
	else if (str[i] == 'X')
		hex_big_found((char *)str, va_arg(ap, unsigned int), flags, counter);
	else if (str[i] == '%')
		ft_putchar_fd_c('%', 1, counter);
	return (&str[i + 1]);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		counter;
	t_flags	flags;

	va_start(ap, str);
	counter = 0;
	while (*str)
	{
		if (*str != '%')
		{
			write(1, str, 1);
			counter++;
			str++;
		}
		else
			str = ft_manage_arg(str + 1, ap, &flags, &counter);
	}
	va_end(ap);
	return (counter);
}

/*
int	main(void)
{
	ft_printf("%.d, %.0d", 0, 0);
	return (0);
}
*/