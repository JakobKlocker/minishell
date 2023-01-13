#include "libft/libft.h"
#include <dirent.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

typedef struct s_node
{
	char	**full_cmd;
	char	*full_path;
	int     in;
	int	    out[1024];
    void    *next;
}		t_node;

//builtins.c
void    echo(t_node *node);

//cmd_split
int	count_words(char *str);
int	next_double_quote_exists(char *str);
int	next_quote_exists(char *str);
