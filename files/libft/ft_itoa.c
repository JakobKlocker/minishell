/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:37:58 by jklocker          #+#    #+#             */
/*   Updated: 2022/10/11 10:14:59 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(int n)
{
	int	counter;

	counter = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		counter++;
	}
	while (n != 0)
	{
		counter++;
		n /= 10;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = int_len(n);
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (len > 0)
	{
		if (n % 10 < 0)
			str[len - 1] = ((n % 10) * -1) + '0';
		else
			str[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	if (str[0] == '0')
		str[0] = '-';
	return (str);
}

/*
int	main(void)
{
	printf("%s", ft_itoa(2147483647));
	return (0);
}
*/