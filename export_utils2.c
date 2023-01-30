/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:11:47 by jklocker          #+#    #+#             */
/*   Updated: 2023/01/30 14:11:48 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmpeq(char *str1, char *str2)
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
	if (str1[i] == '=' && str2[i] == '=')
		return (0);
	else
		return (str1[i] - str2[i]);
}

void	replace_var(t_info *info, char *str)
{
	t_envlst	*temp;

	temp = info->envp;
	while (temp)
	{
		if (ft_strcmpeq(temp->var, str) == 0)
			temp->var = ft_strdup(str);
		temp = temp->next;
	}
	g_status = 0;
}

int	check_for_sc(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i] && str[i] != '=')
	{
		if (ft_isalnum(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	print_arg(char *str, int type)
{
	if (type == 1)
	{
		ft_putstr_fd("bash: export: `", 2);
		ft_printf(str);
		ft_putstr_fd("': not a valid identifier\n", 2);
		g_status = 1;
	}
}

int	str_is_this(char *str1, t_info *info, t_node *node, char *str2)
{
	int	ind;

	ind = 1;
	if (check_for_appereance(str1, '=') == 0 && ft_isalpha(str1[0]) == 1
		&& !(str1[0] == '=') && !(ft_strlen(str1) == 1))
	{
		if ((arg_c(node) > 2 && str2 && ft_isdigit(str2[0]) == 1)
			|| ft_isdigit(str1[0] == 1))
		{
			print_arg(str2, 1);
			ind = 0;
		}	
		insert(info, str1);
	}
	else
		print_arg(str1, 1);
	return (ind);
}
