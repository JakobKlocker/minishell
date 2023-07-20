/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:11:52 by jklocker          #+#    #+#             */
/*   Updated: 2023/01/30 17:11:56 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	main(void) //int argc, char **argv, char **envp)
// {
// 	char	*input;
// 	size_t	n;
// 	char	**arr;
// 	int		i;

// 	input = malloc(100);
// 	n = 100;
// 	getline(&input, &n, stdin);
// 	ft_printf("words: %i\n", count_words(input));
// 	arr = first_split(input);
// 	i = 0;
// 	while (arr[i] != NULL)
// 	{
// 		ft_printf("%s\n", arr[i]);
// 		i++;
// 	}
// }

static int	getlen_till_ch(char *s, char c)
{
	int	i;

	i = 0;
	i = getlen_till_ch_1(s, c, i);
	return (i);
}

int	getlen_till_ch_1(char *s, char c, int i)
{
	while (s[i])
	{
		if (s[i] == '"' && ft_strchr((s + 1), '"'))
		{
			while (s[i + 1] != '"')
				i++;
			i = i + 2;
		}
		if (s[i] == '\'' && ft_strchr(s + 1, '\''))
		{
			while (s[i + 1] != '\'')
				i++;
			i = i + 2;
		}
		if (((s[i] == '<' && s[i + 1] == '<') || (s[i] == '>' && s[i
						+ 1] == '>')) && i == 0)
			return (2);
		if ((s[i] == '<' || s[i] == '>' || s[i] == '|') && i == 0)
			return (1);
		if (s[i] == c || s[i] == '\0' || s[i] == '\n' || s[i] == '|'
			|| s[i] == '<' || s[i] == '>')
			return (i);
		i++;
	}
	return (i);
}

static char	**malloc_2d(char *s, char c)
{
	char	**ret;
	int		i;
	int		j;
	int		k;

	i = count_words(s);
	ret = malloc(((i + 1) * sizeof(char *)));
	if (ret == NULL)
		exit(1);
	j = 0;
	while (i > j)
	{
		while (*s == ' ')
			s++;
		k = getlen_till_ch(s, c);
		ret[j] = ft_calloc(k + 1, 1);
		if (!ret[j])
			exit(1);
		s = s + k;
		j++;
	}
	ret[j] = NULL;
	return (ret);
}

static char	**do_split(char *s, int i, int j)
{
	char	**ret;
	int		k;
	int		c;

	ret = malloc_2d(s, ' ');
	i = count_words(s);
	j = 0;
	while (i > j)
	{
		while (*s == ' ')
			s++;
		c = 0;
		k = getlen_till_ch(s, ' ');
		while (k > c)
		{
			ret[j][c] = *s;
			c++;
			s++;
		}
		ret[j][c] = '\0';
		j++;
	}
	return (ret);
}

char	**first_split(char *s)
{
	char	**ret;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	ret = do_split(s, i, j);
	if (!ret)
		exit(1);
	return (ret);
}
