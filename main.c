/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:12:09 by jklocker          #+#    #+#             */
/*   Updated: 2023/01/30 15:59:54 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	char	*asd;

	while (1)
	{
		init_info(info);
		handle_signals(1);
		asd = readline(CYELLOW "minishell: " RESET);
		info->input = ft_strtrim(asd, " ");
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
