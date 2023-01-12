/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 09:33:31 by jklocker          #+#    #+#             */
/*   Updated: 2022/10/11 10:17:30 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strlength(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	ret;

	ret = strlength((char *)src);
	if (size == 0)
		return (ret);
	i = 0;
	while (size - 1 > i && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ret);
}

/*
int	main(void)
{
	int	a;

	char dest[10]; memset(dest, 'A', 10);
	ft_strlcpy(dest, "1", 0);
	return (0);
}
*/