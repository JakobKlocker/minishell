/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:37:53 by jklocker          #+#    #+#             */
/*   Updated: 2023/01/16 15:37:55 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getlen_till_ch(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c || s[i] == '\0')
			return (i);
		i++;
	}
	return (i);
}

static int	count_certain_ch(char *s, char c)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	j = 0;
	while (s[i])
	{
		check = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			check = 1;
		}
		if (check == 1)
			j++;
	}
	return (j);
}

static char	**malloc_2d(char const *s, char c)
{
	char	**ret;
	int		i;
	int		j;

	ret = malloc((count_certain_ch((char *)s, c) + 1) * sizeof(char *));
	if (ret == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (s[++i])
	{
		if (s[i] != c)
		{
			ret[j] = malloc((getlen_till_ch((char *)s + i, c) + 1)
					* sizeof(char));
			if (ret[j++] == NULL)
				return (NULL);
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		if (s[i] == '\0')
			break ;
	}
	ret[j] = 0;
	return (ret);
}

static char	**do_split(char const *s, char c, int i, int j)
{
	char	**ret;
	int		k;

	ret = malloc_2d(s, c);
	if (!ret)
		return (NULL);
	while (s[++i])
	{
		if (s[i] != c)
		{
			k = 0;
			while (s[i] != c && s[i] != '\0')
			{
				ret[j][k++] = s[i++];
				if (s[i] == c || s[i] == '\0')
					ret[j][k] = '\0';
			}
			j++;
		}
		if (s[i] == '\0')
			break ;
	}
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s)
		return (NULL);
	ret = do_split(s, c, i, j);
	if (!ret)
		return (NULL);
	return (ret);
}

/*
char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	
	if (!ret)
		return (NULL);
	while (s[++i])
	{
		if (s[i] != c)
		{
			k = 0;
			while (s[i] != c && s[i] != '\0')
			{
				ret[j][k++] = s[i++];
				if (s[i] == c || s[i] == '\0')
					ret[j][k] = '\0';
			}
			j++;
		}
		if (s[i] == '\0')
			break ;
	}
	return (ret);
}
*/

/*
int	main(void)
{
	char	**tab;

	tab = ft_split("tripouille", 0);
	for (int i = 0; tab[i]; i++)
		free(tab[i]);
	free(tab);
	return (0);
}
*/