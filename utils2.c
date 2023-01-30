/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:12:47 by jklocker          #+#    #+#             */
/*   Updated: 2023/01/30 15:48:04 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	acess_env(t_info *info, int id)
{
	char		*buf;
	t_envlst	*temp;

	temp = info->envp;
	while (temp->next && id == 1)
	{
		if (ft_strncmp(temp->var, "OLDPWD", 6) == 0)
		{
			buf = getcwd(NULL, 0);
			temp->var = ft_strjoin("OLDPWD=", buf);
		}
		temp = temp->next;
	}
	while (temp->next && id == 0)
	{
		if (ft_strncmp(temp->var, "PWD", 3) == 0)
		{
			buf = getcwd(NULL, 0);
			temp->var = ft_strjoin("PWD=", buf);
		}
		temp = temp->next;
	}
}

void	init_info(t_info *info)
{
	info->head = NULL;
	info->cmd_input = NULL;
	info->input = NULL;
}

void	insert(t_info *info, char *str)
{
	ft_lstaddback(info);
	ft_lstinsert(info, str);
	g_status = 0;
}

int	check_existing(t_info *info, char *str)
{
	t_envlst	*temp;

	temp = info->envp;
	while (temp)
	{
		if (ft_strcmpequnset(temp->var, str) == 0)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	ft_strcmpequnset(char *str1, char *str2)
{
	int	i;

	i = 0;
	if (!str1 || !str2)
		return (-1);
	while (str1[i] && str2[i] && str2[i] != '=' && str1[i] != '=')
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	if (str1[i] == '=' || str2[i] == '=')
		return (0);
	else
		return (str1[i] - str2[i]);
}
