/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:12:24 by jklocker          #+#    #+#             */
/*   Updated: 2023/01/30 18:06:06 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remove_quotes(char **s)
{
	int		i;
	char	*tmp;

	i = 0;
	while (s[i])
	{
		tmp = s[i];
		s[i] = do_remove(s[i]);
		free(tmp);
		i++;
	}
}

//Counts actual counts, double result
int	count_quotes(char *str)
{
	int	quote_count;

	quote_count = 0;
	while (*str)
	{
		str = is_in_quotes(str, &quote_count);
		str++;
	}
	return (quote_count);
}

static char	*do_remove_util(char *str, char c, char *replaced, int *i)
{
	str++;
	while (*str != c)
	{
		replaced[*i] = *str;
		*i = *i + 1;
		str++;
	}
	str++;
	return (str);
}

char	*do_remove(char *str)
{
	char	*replaced;
	int		i;

	replaced = malloc(ft_strlen(str) + 1 - (count_quotes(str) * 2));
	if (!replaced)
		exit(1);
	i = 0;
	while (*str)
	{
		if (*str == '"' && ft_strchr(str + 1, '"'))
		{
			str = do_remove_util(str, '"', replaced, &i);
		}
		if (*str == '\'' && ft_strchr(str + 1, '\''))
		{
			str = do_remove_util(str, '\'', replaced, &i);
		}
		replaced[i] = *str;
		if (*str == '\0')
			break ;
		i++;
		str++;
	}
	replaced[i] = '\0';
	return (replaced);
}
