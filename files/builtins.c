/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:11:20 by jklocker          #+#    #+#             */
/*   Updated: 2023/01/30 14:11:21 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_builtin(t_node *node, t_info *info)
{
	int	i;

	i = ft_strlen(node->full_cmd[0]);
	if (ft_strcmp(node->full_cmd[0], "env") == 0 && i == 3)
		env(info);
	else if (ft_strcmp(node->full_cmd[0], "export") == 0 && i == 6)
		export(node, info);
	else if (ft_strcmp(node->full_cmd[0], "unset") == 0 && i == 5)
		unset(node, info);
	else if (ft_strcmp(node->full_cmd[0], "exit") == 0 && i == 4)
		our_exit_builtin(info);
	else if (ft_strcmp(node->full_cmd[0], "cd") == 0 && i == 2)
		cd(node, info);
	else
		return (0);
	return (1);
}

void	echo(t_node *node)
{
	int	ind;
	int	is;
	int	j;

	is = -1;
	ind = -1;
	j = 1;
	while (check_if_flag(node->full_cmd[j]) == 0)
	{
		ind = 0;
		j++;
	}
	while (node->full_cmd[j])
	{
		if (is == 0)
			write(node->out, " ", 1);
		write(node->out, node->full_cmd[j], ft_strlen(node->full_cmd[j]));
		is = 0;
		j++;
	}
	if (ind == -1)
		write(node->out, "\n", 1);
	g_status = 0;
}

void	cd(t_node *node, t_info *info)
{
	int	i;

	acess_env(info, 1);
	i = 0;
	while (node->full_cmd[i])
		i++;
	if (i > 2)
	{
		ft_putstr_fd("bash: cd: too many arguments\n", 2);
		g_status = 1;
	}
	if (i == 2)
	{
		if (chdir(node->full_cmd[1]) != 0)
			print_err(1, node->full_cmd[1]);
		else
			g_status = 0;
	}
	else
	{
		chdir(getenv("HOME"));
		g_status = 0;
	}
	acess_env(info, 0);
}

void	pwd(void)
{
	char	*buf;

	buf = getcwd(NULL, 0);
	ft_putendlfd(buf, 1);
	free(buf);
	g_status = 0;
}

void	env(t_info *info)
{
	t_envlst	*temp;

	temp = info->envp;
	while (temp)
	{
		printf("%s\n", temp->var);
		temp = temp->next;
	}
	g_status = 0;
}
