#include "minishell.h"

int	main(void) //int argc, char **argv, char **envp)
{
	char *input = malloc(100);
	size_t n = 100;
	getline(&input, &n, stdin);
    printf("%i", count_words(input));
}