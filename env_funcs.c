/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:11:28 by jklocker          #+#    #+#             */
/*   Updated: 2023/01/30 14:11:29 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	main(int argc, char **argv, char **envp)
// {
//     t_info info;
//     if (copy_env(&info, envp) == 1)
//         exit (0);
// }

int	copy_env(t_info *info, char **envp)
{
	int			i;
	t_envlst	*head;

	head = (t_envlst *)malloc(sizeof(t_envlst));
	if (!head)
		call_perror_free(info);
	info->envp = head;
	i = 0;
	copy_env_1(info, envp, i, head);
	return (0);
}

void	copy_env_1(t_info *info, char **envp, int i, t_envlst *head)
{
	int			len;

	while (envp[i])
	{
		if (i != 0)
		{
			head->next = (t_envlst *)malloc(sizeof(t_envlst));
			head = head->next;
		}
		len = ft_strlen(envp[i]);
		head->var = malloc(len + 1);
		if (!head->var)
			call_perror_free(info);
		ft_memcpy(head->var, envp[i], len);
		head->var[len] = '\0';
		i++;
	}
	head->next = NULL;
}
