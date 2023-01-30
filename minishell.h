/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:13:01 by jklocker          #+#    #+#             */
/*   Updated: 2023/01/30 18:12:19 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define CYELLOW "\001\e\033[35m\002"
# define RESET "\001\e[0m\002"

# include "libft/ft_printf.h"
# include "libft/libft.h"
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

extern int			g_status;

typedef struct s_node
{
	char			**full_cmd;
	char			*full_path;
	char			*heredoc;
	int				in;
	int				out;
	struct s_node	*next;
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
	int				fd[2];
	char			*input;
}					t_info;

# define WRITE_END 1
# define READ_END 0

//builtins.c
void				echo(t_node *node);
void				pwd(void);
void				cd(t_node *node, t_info *info);
int					check_builtin(t_node *node, t_info *info);
int					check_builtin_fork(t_node *node, t_info *info);
void				env(t_info *info);

//builtins1.c
void				unset(t_node *node, t_info *list);
void				ft_putendlfd(char *s, int fd);
int					check_var(t_node *node);
void				delete_node(char *str, t_info *info);
void				print_err(int err, char *str);

//utils.c
int					check_if_flag(char *str);
int					check_for_appereance(char *str, char c);
int					check_equality(char *str1, char *str2);
int					arg_c(t_node *node);
int					check_alpha(char *str);

//env_functions
//static int			get_env_lines(char **envp);
int					copy_env(t_info *info, char **envp);
void				copy_env_1(t_info *info, char **envp, int i,
						t_envlst *head);

//first split

int					count_words(char *str);
//static int			getlen_till_ch(char *s, char c);
int					getlen_till_ch_1(char *s, char c, int i);
//static char			**malloc_2d(char *s, char c);
//static char			**do_split(char *s, int i, int j);
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
void				create_node(t_info *info);
void				get_user_input(t_info *info);
void				free_cmd_input(t_info *info);
void				free_special_chars(t_info *info);

//count words
char				*is_in_quotes(char *str, int *count);

//remove quotes
void				remove_quotes(char **s);
int					count_quotes(char *str);
char				*do_remove(char *str);

//export.c
void				export(t_node *node, t_info *info);
void				export_var(t_node *node, t_info *info);
void				print_export(t_info *info);
int					count_var(t_info *info);
void				print_env(char **envp);

//export_utils.c
char				*ft_strcpy(char *dest, const char *src);
int					ft_strcmp(const char *str1, const char *str2);
void				ft_lstaddback(t_info *info);
void				ft_lstinsert(t_info *info, char *str);
int					check_exist(t_info *info, char *str);

//export_utils2.c
int					ft_strcmpeq(char *str1, char *str2);
void				replace_var(t_info *info, char *str);
int					check_for_sc(char *str);
void				print_arg(char *str, int type);
int					str_is_this(char *str1, t_info *info, t_node *node,
						char *str2);

//prepare_nodes.c
int					get_node_count(t_info *info);
int					get_words_for_node(char **str, int i);
void				malloc_nodes(t_info *info);
void				create_fd_out(t_info *info, int *i, t_node *cur);
void				create_fd_in(t_info *info, int *i, t_node *cur);

//prepare_nodes_1.c
void				create_redircets(t_info *info);
void				init_nodes(t_info *info);
void				create_full_cmd(t_info *info);
void				malloc_2d_nodes(t_info *info);
int					check_valid_redirects(t_info *info);

//prepare_nodes_2.c
int					prepare_nodes(t_info *info);

//heredoc.c
void				heredoc(t_info *info, int *i, t_node *cur);

//full_path.c
char				*get_path_ptr(t_info *info);
void				get_full_path(t_info *info);
void				free_split(char **split_paths);
char				**split_add_cmd(char *path_ptr, t_node *cur);
int					is_firstword_path(t_info *info);

//utils2.c
void				acess_env(t_info *info, int id);
void				init_info(t_info *info);
void				insert(t_info *info, char *str);
int					check_existing(t_info *info, char *str);
int					ft_strcmpequnset(char *str1, char *str2);

//Executer
char				**list_to_2d(t_info *info);
void				executer(t_info *info, t_node *cur);

//handle_forks.c
void				handle_forks(t_info *info);
void				handle_executer(t_info *info, t_node *cur);
void				loop_forks(t_info *info, t_node *cur, int pid, int cur_in);
void				node_check_path(t_node *cur);
int					is_builtin(t_node *node);

//signal.c
void				handle_sigint(int sig);
void				handle_sigquit(int sig);
void				handle_signals(int type);
void				handle_sigintfork(int sig);
void				handle_sigquitfork(int sig);

//free.c
void				our_exit(t_info *info);
void				free_env(t_info *info);
void				free_nodes(t_info *info);
void				free_nodes_1(t_node *cur, t_node *tmp, int i);
void				call_perror_free(t_info *info);

//inc_shlvl.c
void				inc_shlvl(t_info *info);
int					get_shlvl(t_info *info);

//our_exit_builtin.c
void				our_exit_builtin(t_info *info);
int					is_all_digit(char *str);

#endif