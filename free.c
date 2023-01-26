#include "minishell.h"

void	our_exit(t_node *node, t_info *info)
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

	cur = info->head;
	i = 0;
	while (cur)
	{
		if (cur->full_path && cur->full_cmd[0][0] != '.' && cur->full_cmd[0][0] != '/')
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
	info->head = NULL;
}

void	call_perror_free(t_info *info)
{
	perror("Error occured with a Syscall\n");
	our_exit(info->head, info);
}