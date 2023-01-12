/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:18:16 by jklocker          #+#    #+#             */
/*   Updated: 2022/10/11 14:52:55 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*check_malloc(char const *s1, char const *s2)
{
	char	*ret;
	int		len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = getlen((char *)s1) + getlen((char *)s2);
	ret = malloc(len + 1);
	if (ret == NULL)
		return (NULL);
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ret;

	ret = check_malloc(s1, s2);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		ret[i] = s2[j];
		i++;
		j++;
	}
	ret[i] = '\0';
	return (ret);
}

/*
int	main(void)
{
	char * s = ft_strjoin("tripouille", "42");
	return (0);
}
*/