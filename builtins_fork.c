#include "minishell.h"

int	check_builtin_fork(t_node *node, t_info *info)
{
	int	i;

	i = ft_strlen(node->full_cmd[0]);
	if (ft_strcmp(node->full_cmd[0], "echo") == 0 && i == 4)
		echo(node);
	else if (ft_strcmp(node->full_cmd[0], "pwd") == 0 && i == 3)
		pwd();
	else if (ft_strcmp(node->full_cmd[0], "env") == 0 && i == 3)
		env(info);
	else if (ft_strcmp(node->full_cmd[0], "export") == 0 && i == 6)
		export(node, info);
	else if (ft_strcmp(node->full_cmd[0], "unset") == 0 && i == 5)
		unset(node, info);
	else if (ft_strcmp(node->full_cmd[0], "exit") == 0 && i == 4)
		our_exit(node, info);
	else if (ft_strcmp(node->full_cmd[0], "cd") == 0 && i == 2)
		cd(node, info);
	else
		handle_executer(info, node);
	exit(g_status);
	return (1);
}
