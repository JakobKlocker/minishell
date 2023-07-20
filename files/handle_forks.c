/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:12:01 by jklocker          #+#    #+#             */
/*   Updated: 2023/01/30 15:57:51 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_forks(t_info *info)
{
	int		pid;
	t_node	*cur;
	int		cur_in;

	pid = 0;
	cur = info->head;
	cur_in = STDIN_FILENO;
	if (!cur->next)
	{
		if (check_builtin(cur, info) == 1)
			return ;
	}
	handle_signals(2);
	loop_forks(info, cur, pid, cur_in);
	if (g_status != 0 && g_status != 1 && g_status != 2)
		g_status = 127;
}

void	loop_forks(t_info *info, t_node *cur, int pid, int cur_in)
{
	while (cur)
	{
		pipe(info->fd);
		node_check_path(cur);
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
	dup2(cur->in, 0);
	dup2(cur->out, 1);
	executer(info, cur);
}

void	node_check_path(t_node *cur)
{
	if (!cur->full_path && is_builtin(cur) == 0)
	{
		ft_printf("%s: command not found\n", cur->full_cmd[0]);
		g_status = 127;
	}
}

int	is_builtin(t_node *node)
{
	int	i;

	i = ft_strlen(node->full_cmd[0]);
	if (ft_strcmp(node->full_cmd[0], "echo") == 0 && i == 4)
		return (1);
	else if (ft_strcmp(node->full_cmd[0], "pwd") == 0 && i == 3)
		return (1);
	else if (ft_strcmp(node->full_cmd[0], "env") == 0 && i == 3)
		return (1);
	else if (ft_strcmp(node->full_cmd[0], "export") == 0 && i == 6)
		return (1);
	else if (ft_strcmp(node->full_cmd[0], "unset") == 0 && i == 5)
		return (1);
	else if (ft_strcmp(node->full_cmd[0], "exit") == 0 && i == 4)
		return (1);
	else if (ft_strcmp(node->full_cmd[0], "cd") == 0 && i == 2)
		return (1);
	return (0);
}
