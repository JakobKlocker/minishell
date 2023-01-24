#include "minishell.h"

#define WRITE_END 1
#define READ_END 0

void	handle_forks(t_info *info)
{
	int		pid;
	int		is_builtin;
	t_node	*cur;
	int		cur_in;

	cur = info->head;
	cur_in = STDIN_FILENO;
	while (cur)
	{
		pipe(info->fd);
		is_builtin = check_builtin(cur, info);
		if (is_builtin == 0)
		{
			pid = fork();
			if (pid == 0)
			{
				dup2(cur_in, 0);
				if (cur->next)
					dup2(info->fd[WRITE_END], 1);
				close(info->fd[READ_END]);
				check_builtin_fork(cur, info);
				exit(3);
			}
			else
			{
				waitpid(pid, NULL, 0);
				close(info->fd[WRITE_END]);
				if (cur_in != 0)
					close(cur_in);
				cur_in = info->fd[READ_END];
				cur = cur->next;
			}
		}
		close(cur_in);
	}
}

void	handle_executer(t_info *info, t_node *cur)
{
	int	pid;

	if (!cur->full_path)
	{
		ft_printf("zsh: command not found: %s\n", cur->full_cmd[0]);
		return ;
	}
	if (cur->heredoc)
		ft_putstr_fd(cur->heredoc, cur->out);
	if (fork() == 0)
	{
		dup2(cur->in, 0);
		dup2(cur->out, 1);
		executer(info, cur);
	}
	wait(NULL);
}

// void	add_pipe_fd(t_node *node, t_info *info)
// {
// 	int i;

// 	i = 0;
// 	t_node *cur;

// 	cur = node->next;
// 	if (!cur)
// 		return ;
// 	while (cur->in[i] != -1 && cur->in[i] != 0)
// 		i++;
// 	if (cur->in[i] != 0)
// 		cur->in[i] = 0;
// 	i = 0;
// 	while (cur->out[i] != -1 && cur->out[i] != 1)
// 		i++;
// 	if (cur->out[i] != 1)
// 		cur->out[i] = 1;
// }