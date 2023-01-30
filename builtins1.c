/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:11:23 by jklocker          #+#    #+#             */
/*   Updated: 2023/01/30 14:11:23 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_putendlfd(char *s, int fd)
{
	if (!s || !fd)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}

void	unset(t_node *node, t_info *info)
{
	int	i;

	i = 1;
	while (node->full_cmd[i])
	{
		if (check_existing(info, node->full_cmd[i]) == 0)
		{
			delete_node(node->full_cmd[i], info);
			g_status = 0;
		}
		else if (check_for_sc(node->full_cmd[i]) == 0)
		{
			ft_printf("bash: unset: `%s: not a valid identifier\n",
				node->full_cmd[i]);
			g_status = 1;
		}
		i++;
	}
	g_status = 0;
}

int	check_var(t_node *node)
{
	int	i;

	i = 0;
	if (check_for_appereance(node->full_cmd[1], '=') == 0)
	{
		while (node->full_cmd[1][i] != '=')
		{
			if (node->full_cmd[1][i] >= 'a' && node->full_cmd[1][i] <= 'z')
				i++;
			else if (node->full_cmd[1][i] >= 'A' && node->full_cmd[1][i] <= 'Z')
				i++;
			else
			{
				i = 0;
				printf("export: not an identifier: ");
				while (node->full_cmd[1][i] != '=')
					write(1, &node->full_cmd[1][i], 1);
				return (1);
			}
		}
		return (0);
	}
	return (1);
}

void	delete_node(char *str, t_info *info)
{
	t_envlst	*temp;
	t_envlst	*prev;

	temp = info->envp;
	if (temp != NULL && ft_strcmpequnset(temp->var, str) == 0)
	{
		info->envp = temp->next;
		free(temp);
		return ;
	}
	while (temp && ft_strcmpequnset(temp->var, str) != 0)
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)
		return ;
	prev->next = temp->next;
	free(temp);
}

void	print_err(int err, char *str)
{
	if (err == 1)
	{
		g_status = errno;
		ft_putstr_fd("bash: cd: ", 2);
		ft_putstr_fd(str, 2);
		write(2, ": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		write(2, "\n", 1);
		g_status = 1;
	}
}
