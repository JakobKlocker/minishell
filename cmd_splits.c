#include "minishell.h"

int	main(void) //int argc, char **argv, char **envp)
{
	char	*input;
	size_t	n;

	input = malloc(100);
	n = 100;
	getline(&input, &n, stdin);
	printf("%i", count_words(input));
}

int	count_words(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str == ' ' || *str == '\n')
			str++;
		if (*str == '"' && next_double_quote_exists(str + 1))
		{
			while (*(str + 1) != '"')
				str++;
			str = str + 2;
		}
		if (*str == '\'' && next_quote_exists(str + 1))
		{
			while (*(str + 1) != '\'')
				str++;
			str = str + 2;
		}
		while (*str && *str != ' ' && *str != '\n')
			str++;
		if (*str == ' ' || *str == '\n')
			count++;
		str++;
	}
	return (count);
}

int	next_double_quote_exists(char *str)
{
	while (*str)
	{
		if (*str == '"')
			return (1);
		str++;
	}
	return (0);
}

int	next_quote_exists(char *str)
{
	while (*str)
	{
		if (*str == '\'')
			return (1);
		str++;
	}
	return (0);
}
