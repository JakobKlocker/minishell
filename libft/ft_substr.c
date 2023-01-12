/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:23:07 by jklocker          #+#    #+#             */
/*   Updated: 2022/10/11 14:38:04 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*do_checks(char const *s, unsigned int start)
{
	char	*ret;

	ret = NULL;
	if (start > ft_strlen(s) || s == NULL)
	{
		ret = malloc(1);
		ret[0] = 0;
		return (ret);
	}
	return (ret);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (!s)
		return (NULL);
	ret = do_checks(s, start);
	if (!(ret == NULL))
		return (ret);
	if (ft_strlen(s + start) <= len)
		ret = malloc(ft_strlen(s + start) + 1);
	else if (ft_strlen(s + start) >= len)
		ret = malloc(len + 1);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[i + start] != '\0')
	{
		ret[i] = s[i + start];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

/*
int	main(void)
{
	char	*s;

		s = ft_substr("tripouille", 1, 1);
		free(s);
		return (0);
}
*/