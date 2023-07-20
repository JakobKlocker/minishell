/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:11:55 by jklocker          #+#    #+#             */
/*   Updated: 2023/01/30 18:11:30 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	our_exit(t_info *info)
{
	ft_printf("exit\n");
	free_env(info);
	free_nodes(info);
	if (info->cmd_input)
		free(info->cmd_input);
	exit(g_status);
}

void	free_env(t_info *info)
{
	t_envlst	*current;
	t_envlst	*next;

	current = info->envp;
	if (count_var(info) != 0)
	{
		while (current)
		{
			next = current->next;
			free(current->var);
			free(current);
			current = next;
		}
	}
}

void	free_nodes(t_info *info)
{
	int		i;
	t_node	*cur;
	t_node	*tmp;

	tmp = NULL;
	cur = info->head;
	i = 0;
	free_special_chars(info);
	free_nodes_1(cur, tmp, i);
	info->head = NULL;
}

void	free_nodes_1(t_node *cur, t_node *tmp, int i)
{
	while (cur)
	{
		if (cur->full_path && cur->full_cmd[0] && cur->full_cmd[0][0] != '.'
			&& cur->full_cmd[0][0] != '/')
			free(cur->full_path);
		if (cur->full_cmd != NULL)
		{
			while (cur->full_cmd[i])
				free(cur->full_cmd[i++]);
			free(cur->full_cmd);
		}
		if (cur->heredoc)
		{
			unlink(cur->heredoc);
			free(cur->heredoc);
		}
		i = 0;
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
}

void	call_perror_free(t_info *info)
{
	perror("Error occured with a Syscall\n");
	our_exit(info);
}
