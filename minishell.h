#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/ft_printf.h"
# include "libft/libft.h"
# include <dirent.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_node
{
	char			**full_cmd;
	char			*full_path;
	int				in;
	int				out[1024];
	void			*next;
}					t_node;

//envp list
typedef struct s_envlst
{
	char			*var;
	struct s_envlst	*next;
}					t_envlst;

typedef struct s_info
{
	t_node			*head;
	t_envlst		*envp;
	pid_t			pid;
	char			**cmd_input;
}					t_info;

//builtins.c
void				echo(t_node *node);
void				pwd(void);
void				cd(t_node *node, t_info *info);
void				check_builtin(t_node *node, t_info *info);
void				env(t_info *info);

//utils.c
int check_if_flag(char *str);
int check_for_appereance(char *str, char c);
int check_equality(char *str1, char *str2);
int arg_c(t_node *node);
int check_alpha(char *str);

//env_functions
static int			get_env_lines(char **envp);
int					copy_env(t_info *info, char **envp);

//first split, splits into 2D array removing spaces and keeping str inside quotes in one, lexer
int					count_words(char *str);
static int			getlen_till_ch(char *s, char c);
static char			**malloc_2d(char *s, char c);
static char			**do_split(char *s, int i, int j);
char				**first_split(char *s);

//expander
char				*reaplce_empty(char *str, char *dol_pos, int our_var_len);
char				*do_replace(char *str, char *env_pos, char *dol_pos,
						int our_var_len);
void				replace_env(char **str, int i, char *dol_pos, t_info *info);
void				expander(char **str, t_info *info);
char				*get_dol_pos(char *str);

//expander 1
int					get_len_env_var(char *var);
char				*get_env_for_var(t_info *info, char *dol_pos, int len);

//main
void    get_user_input(t_info *info);
void    print_2d(char **str);

//count words
char	*is_in_quotes(char *str, int *count);


//remove quotes
void	**remove_quotes(char **s);
int    count_quotes(char *str);
char    *do_remove(char *str);

//export.c
void    export(t_node *node, t_info *info);
void    export_var(t_node *node, t_info *info);
void    print_export(t_node *node, t_info *info);
void 	print_env(char **envp);
int 	count_var(t_info *info);
char 	*ft_strcpy(char *dest, const char *src);
int 	ft_strcmp(const char *str1, const char *str2);
void    ft_lstaddback(t_info *info);
void    ft_lstinsert(t_info *info, char *str);
void	ft_putendlfd(char *s, int fd);

#endif