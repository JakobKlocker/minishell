/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:09:40 by jklocker          #+#    #+#             */
/*   Updated: 2022/10/11 13:37:31 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
static int	getlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (*little == '\0' || little == NULL || (big == NULL && len == 0))
		return ((char *)big);
	i = 0;
	j = 0;
	while (big[i] != '\0' && len > i)
	{
		if (big[i] == little[0])
		{
			k = i;
			while ((big[k] == little[j] && len > k) || little[j] == '\0')
			{
				if (little[j] == '\0')
					return ((char *)big + i);
				k++;
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	ft_strnstr(((void*)0), "fake", 0);
	return (0);
}
*/