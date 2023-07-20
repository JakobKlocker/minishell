/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inc_shlvl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:12:06 by jklocker          #+#    #+#             */
/*   Updated: 2023/01/30 18:16:09 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	inc_shlvl(t_info *info)
{
	int			lvl;
	char		*new_str;
	char		*tmp;
	t_envlst	*cur;

	lvl = get_shlvl(info);
	if (lvl == -1)
		return ;
	lvl++;
	tmp = ft_itoa(lvl);
	new_str = ft_strjoin("SHLVL=", tmp);
	free(tmp);
	cur = info->envp;
	while (cur)
	{
		if (ft_strncmp(cur->var, "SHLVL=", 6) == 0)
		{
			free(cur->var);
			cur->var = new_str;
			return ;
		}
		cur = cur->next;
	}
}

int	get_shlvl(t_info *info)
{
	t_envlst	*cur;

	cur = info->envp;
	while (cur)
	{
		if (ft_strncmp(cur->var, "SHLVL=", 6) == 0)
			return (ft_atoi(cur->var + 6));
		cur = cur->next;
	}
	return (-1);
}
