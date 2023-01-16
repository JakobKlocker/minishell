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

typedef struct s_info
{
	t_node	*head;
	char	**envp;
	pid_t	pid;
}		t_info;


//builtins.c
void    echo(t_node *node);
void	pwd(void);
void    cd(t_node *node);
void 	check_builtin (t_node *node, char **envp)

//utils
int check_flag(char *str);

//env_functions
static int    get_env_lines(char **envp);
void    copy_env(t_info *info, char **envp);

//first split, splits into 2D array removing spaces and keeping str inside quotes in one, lexer
int	count_words(char *str);
static int	getlen_till_ch(char *s, char c);
static char	**malloc_2d(char *s, char c);
static char	**do_split(char *s, int i, int j);
char	**first_split(char *s);

//second split, 