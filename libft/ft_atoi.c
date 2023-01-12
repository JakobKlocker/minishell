/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:06:58 by jklocker          #+#    #+#             */
/*   Updated: 2022/10/11 13:08:05 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	minus_counter;
	int	ret;

	i = 0;
	minus_counter = 0;
	ret = 0;
	while (str[i] == 9 || str[i] == 10 || str[i] == 11 || str[i] == 12
		|| str[i] == 13 || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		minus_counter++;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		ret = ret * 10 + str[i] - '0';
		i++;
	}
	if (minus_counter != 0)
		return (ret * -1);
	return (ret);
}

/*
int	main(void)
{
    char *n = "\t\v\f\r\n \f-06050";
    int i1 = atoi(n);
    int i2 = ft_atoi(n);
	return (0);
}
*/