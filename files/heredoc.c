/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:12:03 by jklocker          #+#    #+#             */
/*   Updated: 2023/01/30 18:42:56 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc(t_info *info, int *i, t_node *cur)
{
	char	*line;
	int		fd;
	char	*tmp;

	tmp = ft_itoa(*i);
	fd = open(tmp, O_CREAT | O_WRONLY | O_TRUNC, 777);
	line = readline("> ");
	while (ft_strcmp(line, info->cmd_input[*i + 1]) != 0)
	{
		ft_putendl_fd(line, fd);
		line = readline("> ");
	}
	cur->heredoc = ft_strdup(tmp);
	close(fd);
	fd = open(tmp, O_CREAT | O_RDONLY, 777);
	free(tmp);
	cur->in = fd;
	*i = *i + 1;
}
