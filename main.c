#include "minishell.h"

int		g_status = 0;

int	main(int argc, char **argv, char **envp)
{
	t_info	info;

	init_info(&info);
	copy_env(&info, envp);
	inc_shlvl(&info);
	get_user_input(&info);
	init_sigaction(&info);
}

void	get_user_input(t_info *info)
{
	while (1)
	{
		init_info(info);
		info->input = ft_strtrim(readline("testshell: "), " ");
		if (info->input == NULL)
			our_exit(info->head, info);
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
	our_exit(info->head, info);
}

void	create_node(t_info *info)
{
	info->cmd_input = first_split(info->input);
	expander(info->cmd_input, info);
	remove_quotes(info->cmd_input);
	prepare_nodes(info);
	get_full_path(info);
}

// void    print_2d(char **str)
// {
//     int i;

//     i = 0;
//     while(str[i])
//     {
//         ft_printf("%s\n", str[i]);
//         i++;
//     }
// }

// void    print_nodes(t_info *info)
// {
//     int i;
//     t_node *tmp;

//     tmp = info->head;
//     i = 0;
//     while(tmp)
//     {
//         while(tmp->full_cmd[i])
//         {
//             ft_printf("%s ", tmp->full_cmd[i]);
//             i++;
//         }
//         i = 0;
//         ft_printf("\n");
//         tmp = tmp->next;
//     }
// }
