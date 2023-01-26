/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:09:40 by jklocker          #+#    #+#             */
/*   Updated: 2023/01/25 15:41:07 by jklocker         ###   ########.fr       */
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

static char	*jump_till_noset(char const *s1, char const *set)
{
	int	j;
	int	check;

	while (*s1)
	{
		j = 0;
		check = 0;
		while (set[j])
		{
			if (*s1 == set[j])
			{
				s1++;
				check = 1;
				break ;
			}
			j++;
		}
		if (check == 0)
			return ((char *)s1);
	}
	return ((char *)s1);
}

static char	*jump_till_noset_re(char const *s1, char const *set)
{
	int	check;
	int	len;
	int	j;

	len = getlen((char *)s1);
	while (len > 0)
	{
		j = 0;
		check = 0;
		while (set[j])
		{
			if (s1[len - 1] == set[j])
			{
				check = 1;
				break ;
			}
			j++;
		}
		if (check == 0)
			return ((char *)&s1[len]);
		len--;
	}
	return ((char *)&s1[len]);
}

static char	*check_dif(void)
{
	char	*ret;

	ret = malloc(1);
	ret[0] = '\0';
	return (ret);
}

char	*ft_strtrim(char *s1, char const *set)
{
	char	*first_addr;
	char	*last_addr;
	char	*ret;
	long	addr_dif;
	int		i;

	if (!s1 || !set)
		return (NULL);
	first_addr = jump_till_noset(s1, set);
	last_addr = jump_till_noset_re(s1, set);
	addr_dif = (long)last_addr - (long)first_addr;
	if (addr_dif < 0)
		return (check_dif());
	ret = malloc(addr_dif + 1);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (addr_dif > i)
	{
		ret[i] = first_addr[i];
		i++;
	}
	ret[i] = 0;
	free(s1);
	return (ret);
}

/*
int	main(void)
{
	char	*s;

	s = ft_strtrim("abcdba", "acb");
	return (0);
}
*/