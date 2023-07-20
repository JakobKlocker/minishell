/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:11:58 by jklocker          #+#    #+#             */
/*   Updated: 2023/01/30 14:11:59 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_path_ptr(t_info *info)
{
	t_envlst	*cur;

	cur = info->envp;
	while (cur)
	{
		if (ft_strncmp(cur->var, "PATH=", 5) == 0)
			return (cur->var + 5);
		cur = cur->next;
	}
	return (NULL);
}

char	**split_add_cmd(char *path_ptr, t_node *cur)
{
	char	**ret;
	char	*tmp;
	char	*tmp1;
	int		i;

	ret = ft_split(path_ptr, ':');
	i = 0;
	while (cur->full_cmd && cur->full_cmd[0] && ret && ret[i])
	{
		tmp = ft_strjoin(ret[i], "/");
		tmp1 = ft_strjoin(tmp, cur->full_cmd[0]);
		free(tmp);
		free(ret[i]);
		ret[i] = tmp1;
		i++;
	}
	return (ret);
}

void	free_split(char **split_paths)
{
	int	i;

	i = 0;
	while (split_paths[i])
	{
		free(split_paths[i]);
		i++;
	}
	free(split_paths);
}

void	get_full_path(t_info *info)
{
	char	*path_ptr;
	char	**split_paths;
	int		i;
	t_node	*cur;

	cur = info->head;
	path_ptr = get_path_ptr(info);
	while (cur)
	{
		split_paths = split_add_cmd(path_ptr, cur);
		i = 0;
		while (split_paths && split_paths[i])
		{
			if (access(split_paths[i], F_OK) == 0)
			{
				cur->full_path = ft_strdup(split_paths[i]);
				break ;
			}
			i++;
		}
		if (split_paths)
			free_split(split_paths);
		cur = cur->next;
	}
}

int	is_firstword_path(t_info *info)
{
	t_node	*cur;

	cur = info->head;
	while (cur)
	{
		if (cur->full_cmd && cur->full_cmd[0] && (cur->full_cmd[0][0] == '.'
			|| cur->full_cmd[0][0] == '/'))
		{
			cur->full_path = cur->full_cmd[0];
			if (access(cur->full_path, X_OK) != 0)
			{
				g_status = 127;
				ft_printf("bash: %s: No such file or directory\n",
					cur->full_path);
				return (-1);
			}
		}
		cur = cur->next;
	}
	return (0);
}
