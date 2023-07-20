/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_nodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:12:21 by jklocker          #+#    #+#             */
/*   Updated: 2023/01/31 13:20:06 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_node_count(t_info *info)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (info->cmd_input[i])
	{
		if (info->cmd_input[i][0] == '|')
			count++;
		i++;
	}
	return (count);
}

int	get_words_for_node(char **str, int i)
{
	int	ret;

	ret = 0;
	while (str[i] && str[i][0] != '|')
	{
		if (str[i][0] == '<' || str[i][0] == '>')
		{
			i = i + 2;
			continue ;
		}
		i++;
		ret++;
	}
	return (ret);
}

void	malloc_nodes(t_info *info)
{
	int		node_count;
	t_node	*tmp;

	tmp = malloc(sizeof(t_node));
	if (!tmp)
		call_perror_free(info);
	info->head = tmp;
	node_count = get_node_count(info);
	while (node_count > 0)
	{
		tmp->next = malloc(sizeof(t_node));
		if (!tmp->next)
			call_perror_free(info);
		tmp = tmp->next;
		node_count--;
	}
	tmp->next = NULL;
}

void	create_fd_out(t_info *info, int *i, t_node *cur)
{
	int	fd;

	if (info->cmd_input[*i][1] == '\0')
		fd = open(info->cmd_input[*i + 1], O_RDWR | O_CREAT, 0777);
	else
		fd = open(info->cmd_input[*i + 1], O_RDWR | O_CREAT | O_APPEND, 0777);
	cur->out = fd;
	*i = *i + 1;
}

void	create_fd_in(t_info *info, int *i, t_node *cur)
{
	int	fd;

	fd = open(info->cmd_input[*i + 1], O_RDWR);
	cur->in = fd;
	*i = *i + 1;
}
