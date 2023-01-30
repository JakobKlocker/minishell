#include "minishell.h"

void	our_exit_builtin(t_info *info)
{
	ft_printf("exit\n");
	if (info->head->full_cmd[1] && is_all_digit(info->head->full_cmd[1]) == 0)
	{
		ft_printf("bash: exit: asd: numeric argument required\n");
		g_status = 2;
		return ;
	}
	if (info->head->full_cmd[1] && is_all_digit(info->head->full_cmd[1]) == 1)
		g_status = ft_atoi(info->head->full_cmd[1]);
	free_env(info);
	free_nodes(info);
	if (info->cmd_input)
		free(info->cmd_input);
	exit(g_status);
}

int	is_all_digit(char *str)
{
	while (*str)
	{
		if (ft_isdigit(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}
