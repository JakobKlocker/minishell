/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:11:25 by jklocker          #+#    #+#             */
/*   Updated: 2023/01/30 14:11:27 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*is_special(char *str, int *count)
{
	if ((*str == '<' && *(str + 1) == '<') || (*str == '>' && *(str
				+ 1) == '>'))
	{
		*count = *count + 1;
		return (str + 2);
	}
	if (*str == '|' || *str == '<' || *str == '>')
	{
		*count = *count + 1;
		return (str + 1);
	}
	return (str);
}

char	*is_in_quotes(char *str, int *count)
{
	if (*str == '"' && ft_strchr(str + 1, '"'))
	{
		str++;
		while (*str != '"')
			str++;
		str++;
		*count = *count + 1;
	}
	if (*str == '\'' && ft_strchr(str + 1, '\''))
	{
		str++;
		while (*str != '\'')
			str++;
		str++;
		*count = *count + 1;
	}
	return (str);
}

static char	*is_word(char *str, int *count)
{
	if (*str != ' ' && *str != '\n' && *str != '|' && *str != '<' && *str != '>'
		&& *str)
	{
		while ((*str != ' ' && *str != '\n' && *str != '|' && *str != '<'
				&& *str != '>' && *str))
		{
			if (*str == '\'' && ft_strchr(str + 1, '"'))
			{
				str++;
				while (*str != '"')
					str++;
			}
			if (*str == '\'' && ft_strchr(str + 1, '\''))
			{
				str++;
				while (*str != '\'')
					str++;
			}
			str++;
		}
		*count = *count + 1;
	}
	return (str);
}

int	count_words(char *str)
{
	int		count;

	count = 0;
	while (*str && *str != '\n')
	{
		while (*str == ' ' || *str == '\n')
			str++;
		str = is_special(str, &count);
		str = is_in_quotes(str, &count);
		str = is_word(str, &count);
	}
	return (count);
}
