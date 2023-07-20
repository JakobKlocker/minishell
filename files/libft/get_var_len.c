/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:29:14 by jklocker          #+#    #+#             */
/*   Updated: 2022/10/20 14:31:55 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	int_len_u(unsigned int n)
{
	unsigned int	counter;

	counter = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		counter++;
		n /= 10;
	}
	return (counter);
}

int	int_len(int n)
{
	int	counter;

	counter = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		counter++;
		n = n * -1;
	}
	while (n != 0)
	{
		counter++;
		n /= 10;
	}
	return (counter);
}

int	hex_len(unsigned long nb)
{
	int	counter;

	counter = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 16;
		counter++;
	}
	return (counter);
}

int	hex_len_ptr(void *ptr)
{
	int				counter;
	unsigned long	nb;

	counter = 0;
	if (ptr == NULL)
		return (5);
	nb = (unsigned long)ptr;
	while (nb != 0)
	{
		nb /= 16;
		counter++;
	}
	return (counter + 2);
}

size_t	ft_strlen_n(const char *str)
{
	size_t	i;

	if (str == NULL)
	{
		return (6);
	}
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
