#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <dirent.h>
#include <string.h>
#include <signal.h>

typedef struct s_node
{
	char	**full_cmd;
	char	*full_path;
	int     in;
	int	    out;
    void    *next;
}		t_node;

//builtins.c
void    echo(t_node *node);

