#include "minishell.h"

int		g_status = 0;

int	main(int argc, char **argv, char **envp)
{
	t_info	info;

	(void)argc;
	(void)argv;
	init_info(&info);
	copy_env(&info, envp);
	inc_shlvl(&info);
	get_user_input(&info);
}

void	get_user_input(t_info *info)
{
	while (1)
	{
		init_info(info);
		handle_signals(1);
		info->input = ft_strtrim(readline(CYELLOW "minishell: " RESET), " ");
		if (info->input == NULL)
			our_exit(info);
		if (info->input[0] == '\0')
			continue ;
		add_history(info->input);
		create_node(info);
		if (info->head && info->head->full_cmd && info->head->full_cmd[0]
			&& is_firstword_path(info) == 0)
			handle_forks(info);
		free_nodes(info);
		free(info->input);
	}
	our_exit(info);
}

void	create_node(t_info *info)
{
	info->cmd_input = first_split(info->input);
	expander(info->cmd_input, info);
	remove_quotes(info->cmd_input);
	prepare_nodes(info);
	get_full_path(info);
}
