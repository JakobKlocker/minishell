#ifndef MINISHELL_H
# define MINISHELL_H

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

//envp list
typedef struct envlst 
{
	char *var;
	struct envlst *next;
} 		envlst_t;

typedef struct s_info
{
	t_node	*head;
	envlst_t	*envp;
	pid_t	pid;
}		t_info;

//builtins.c
void    echo(t_node *node);
void	pwd(void);
void    cd(t_node *node, t_info *info);
void 	check_builtin(t_node *node, t_info *info);
void 	env(t_info *info);

//utils.c
int check_if_flag(char *str);
int check_for_appereance(char *str, char c);
int check_equality(char *str1, char *str2);

//env_functions
static int    get_env_lines(char **envp);
int    copy_env(t_info *info, char **envp);

//first split, splits into 2D array removing spaces and keeping str inside quotes in one, lexer
int	count_words(char *str);
static int	getlen_till_ch(char *s, char c);
static char	**malloc_2d(char *s, char c);
static char	**do_split(char *s, int i, int j);
char	**first_split(char *s);

//second split, 

#endif