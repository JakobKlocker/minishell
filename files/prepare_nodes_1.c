/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_nodes_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:12:16 by jklocker          #+#    #+#             */
/*   Updated: 2023/01/30 14:12:16 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_redircets(t_info *info)
{
	int		i;
	t_node	*cur;

	cur = info->head;
	i = -1;
	while (info->cmd_input[++i])
	{
		if (info->cmd_input[i][0] == '|')
			cur = cur->next;
		if (info->cmd_input[i][0] == '>')
			create_fd_out(info, &i, cur);
		if (info->cmd_input[i][0] == '<' && info->cmd_input[i][1] == '\0')
			create_fd_in(info, &i, cur);
		if (info->cmd_input[i][0] == '<' && info->cmd_input[i][1] == '<')
			heredoc(info, &i, cur);
	}
}

//Test function
void	init_nodes(t_info *info)
{
	t_node	*tmp;

	tmp = info->head;
	while (tmp)
	{
		tmp->full_path = NULL;
		tmp->heredoc = NULL;
		tmp->in = 0;
		tmp->out = 1;
		tmp = tmp->next;
	}
}

void	create_full_cmd(t_info *info)
{
	int		i;
	int		j;
	t_node	*tmp;

	tmp = info->head;
	i = 0;
	j = 0;
	while (info->cmd_input[i])
	{
		if (info->cmd_input[i][0] == '|')
		{
			tmp = tmp->next;
			i++;
			j = 0;
			continue ;
		}
		else if (info->cmd_input[i][0] == '<' || info->cmd_input[i][0] == '>')
		{
			i = i + 2;
			continue ;
		}
		tmp->full_cmd[j] = info->cmd_input[i];
		j++;
		i++;
	}
}

void	malloc_2d_nodes(t_info *info)
{
	int		i;
	int		words;
	t_node	*cur;

	cur = info->head;
	i = 0;
	while (info->cmd_input[i])
	{
		words = get_words_for_node(info->cmd_input, i);
		cur->full_cmd = malloc((words + 1) * sizeof(char *));
		if (!cur->full_cmd)
			call_perror_free(info);
		cur->full_cmd[words] = NULL;
		while (info->cmd_input[i] && info->cmd_input[i][0] != '|')
			i++;
		cur = cur->next;
		if (info->cmd_input[i])
			i++;
	}
}

int	check_valid_redirects(t_info *info)
{
	int	i;

	i = 0;
	while (info->cmd_input[i])
	{
		if (info->cmd_input[i][0] == '<' || info->cmd_input[i][0] == '>')
		{
			if (!info->cmd_input[i + 1] || info->cmd_input[i + 1][0] == '<'
				|| info->cmd_input[i + 1][0] == '>' || info->cmd_input[i
				+ 1][0] == '|')
			{
				ft_printf("zsh: parse error near `\\n'\n");
				return (0);
			}
		}
		i++;
	}
	return (1);
}
