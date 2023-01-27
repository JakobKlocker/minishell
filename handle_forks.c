#include "minishell.h"

void	handle_forks(t_info *info)
{
	int		pid;
	t_node	*cur;
	int		cur_in;

	cur = info->head;
	cur_in = STDIN_FILENO;
	if (!cur->next)
	{
		if (check_builtin(cur, info) == 1)
			return ;
	}
	if (!cur->full_path)
	{
		ft_printf("%s: command not found\n", cur->full_cmd[0]);
		g_status = 127;
		return ;
	}
	loop_forks(info, cur, pid, cur_in);
	if (g_status == 256)
		g_status = 127;
}

void	loop_forks(t_info *info, t_node *cur, int pid, int cur_in)
{
	while (cur)
	{
		pipe(info->fd);
		handle_signals(2);
		pid = fork();
		if (pid == -1)
			call_perror_free(info);
		if (pid == 0)
		{
			dup2(cur_in, 0);
			if (cur->next)
				dup2(info->fd[WRITE_END], 1);
			close(info->fd[READ_END]);
			check_builtin_fork(cur, info);
		}
		close(info->fd[WRITE_END]);
		if (cur_in != 0)
			close(cur_in);
		cur_in = info->fd[READ_END];
		cur = cur->next;
	}
	pid = -1;
	while (pid++ < get_node_count(info))
		wait(&g_status);
	close(info->fd[READ_END]);
}

void	handle_executer(t_info *info, t_node *cur)
{
	int	pid;

	dup2(cur->in, 0);
	dup2(cur->out, 1);
	executer(info, cur);
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