/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 18:36:09 by jklocker          #+#    #+#             */
/*   Updated: 2022/10/20 14:55:58 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_bases(unsigned long nbr, int len, char *base, int *counter)
{
	if ((unsigned long)len <= nbr)
	{
		print_bases(nbr / len, len, base, counter);
		print_bases(nbr % len, len, base, counter);
	}
	if (nbr < (unsigned long)len)
		ft_putchar_fd_c(base[nbr], 1, counter);
}

void	pointer_error(int *counter)
{
	write(1, "(nil)", 5);
	*counter = *counter + 5;
}

void	ft_putnbr_base_p(void *addr, char *base, int *counter)
{
	int	i;
	int	k;

	i = 0;
	if (!addr)
		return (pointer_error(counter));
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return ;
		k = i + 1;
		while (base[k] != '\0')
		{
			if (base[k] == base[i])
				return ;
			k++;
		}
		i++;
	}
	if (i == 1 || i == 0)
		return ;
	write(1, "0x", 2);
	*counter = *counter + 2;
	print_bases((unsigned long)addr, i, base, counter);
}

void	ft_putnbr_base_c(unsigned long nbr, char *base, int *counter)
{
	int	i;
	int	k;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return ;
		k = i + 1;
		while (base[k] != '\0')
		{
			if (base[k] == base[i])
				return ;
			k++;
		}
		i++;
	}
	if (i == 1 || i == 0)
		return ;
	print_bases(nbr, i, base, counter);
}
