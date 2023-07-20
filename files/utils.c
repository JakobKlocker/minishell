/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:12:43 by jklocker          #+#    #+#             */
/*   Updated: 2023/01/30 14:12:44 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_if_flag(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	if (str[i++] != '-')
		return (-1);
	while (str[i])
	{
		if (str[i] == 'n')
			i++;
		else
			return (-1);
	}
	return (0);
}

int	check_for_appereance(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	check_equality(char *str1, char *str2)
{
	int	i;

	i = 0;
	if (ft_strlen(str1) != ft_strlen(str2))
		return (-1);
	while (str1[i])
	{
		if (str1[i] == str2[i])
			i++;
		else
			return (-1);
	}
	return (0);
}

int	arg_c(t_node *node)
{
	int	i;

	i = 0;
	while (node->full_cmd[i])
		i++;
	return (i);
}
