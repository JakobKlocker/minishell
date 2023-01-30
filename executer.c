/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:11:31 by jklocker          #+#    #+#             */
/*   Updated: 2023/01/30 18:16:29 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**list_to_2d(t_info *info)
{
	t_envlst	*cur;
	char		**ret;
	int			i;

	cur = info->envp;
	ret = ft_calloc(count_var(info) + 1, sizeof(char *));
	if (!ret)
		call_perror_free(info);
	i = 0;
	while (cur)
	{
		ret[i] = cur->var;
		cur = cur->next;
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

void	executer(t_info *info, t_node *cur)
{
	char	**envp;

	if (!cur->full_path)
		return ;
	envp = list_to_2d(info);
	execve(cur->full_path, cur->full_cmd, envp);
}
