/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 09:46:38 by jklocker          #+#    #+#             */
/*   Updated: 2022/10/11 14:07:51 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strlength(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;
	size_t	ret;

	dest_len = strlength(dest);
	src_len = strlength((char *)src);
	i = 0;
	if (size > dest_len)
		ret = src_len + dest_len;
	else
		ret = size + src_len;
	if (size == 0)
		return (ret);
	while (src[i] != '\0' && size > dest_len + 1)
	{
		dest[dest_len] = src[i];
		i++;
		dest_len++;
	}
	if (size != 0)
		dest[dest_len] = '\0';
	return (ret);
}

/*
int	main(void)
{
	char	b[0xF];

        b[0xF] = "nyan !";
        ft_strlcat(((void*)0), b, 0);
	return (0);
}
*/