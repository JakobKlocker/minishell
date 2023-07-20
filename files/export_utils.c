/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:11:39 by jklocker          #+#    #+#             */
/*   Updated: 2023/01/30 14:11:43 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	int	i;

	i = 0;
	if (!str1 || !str2)
		return (-1);
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (str1[i] - str2[i]);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_lstaddback(t_info *info)
{
	t_envlst	*temp;

	temp = info->envp;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = malloc(sizeof(t_envlst));
	if (!temp->next)
		call_perror_free(info);
	temp->next->next = NULL;
}

void	ft_lstinsert(t_info *info, char *str)
{
	t_envlst	*temp;

	temp = info->envp;
	while (temp->next)
		temp = temp->next;
	temp->var = ft_strdup(str);
}

int	check_exist(t_info *info, char *str)
{
	t_envlst	*temp;

	temp = info->envp;
	while (temp)
	{
		if (ft_strcmpeq(temp->var, str) == 0)
			return (0);
		temp = temp->next;
	}
	return (1);
}
