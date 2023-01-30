/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:11:36 by jklocker          #+#    #+#             */
/*   Updated: 2023/01/30 14:11:37 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*reaplce_empty(char *str, char *dol_pos, int our_var_len)
{
	char			*ret;
	unsigned int	ptr_dif;

	ptr_dif = (char *)dol_pos - (char *)str;
	ret = malloc(ft_strlen(str) - our_var_len);
	if (ret == NULL)
		exit(1);
	if (0 < ptr_dif)
		ft_memcpy(ret, str, ptr_dif);
	ft_memcpy(ret + ptr_dif, str + ptr_dif + our_var_len + 1, ft_strlen(str
			+ ptr_dif + our_var_len + 1));
	ret[ft_strlen(str) - our_var_len - 1] = '\0';
	return (ret);
}

char	*do_replace(char *str, char *env_pos, char *dol_pos, int our_var_len)
{
	char			*ret;
	unsigned int	ptr_dif;

	if (env_pos == NULL)
	{
		ret = reaplce_empty(str, dol_pos, our_var_len);
		return (ret);
	}
	ptr_dif = (char *)dol_pos - (char *)str;
	ret = malloc(ft_strlen(str) - our_var_len + 1 + ft_strlen(env_pos) + 1);
	if (ret == NULL)
		exit(1);
	if (0 < ptr_dif)
		ft_memcpy(ret, str, ptr_dif);
	ft_memcpy(ret + ptr_dif, env_pos, ft_strlen(env_pos));
	ft_memcpy(ret + ptr_dif + ft_strlen(env_pos), str + ptr_dif + our_var_len
		+ 1, ft_strlen(str + ptr_dif + our_var_len + 1));
	if (strcmp(dol_pos, "$?") == 0)
		ret[our_var_len + ptr_dif] = '\0';
	else
		ret[ptr_dif + ft_strlen(env_pos) + ft_strlen(str + ptr_dif + our_var_len
				+ 1)] = '\0';
	return (ret);
}

void	replace_env(char **str, int i, char *dol_pos, t_info *info)
{
	int		our_var_len;
	char	*env_pos;
	char	*ret;

	our_var_len = get_len_env_var(dol_pos);
	env_pos = get_env_for_var(info, dol_pos, our_var_len);
	if (dol_pos[0] == '?')
	{
		our_var_len = ft_strlen(ft_itoa(g_status));
		env_pos = ft_itoa(g_status);
	}
	ret = do_replace(str[i], env_pos, dol_pos - 1, our_var_len);
	free(str[i]);
	str[i] = ret;
}

void	expander(char **str, t_info *info)
{
	int		i;
	char	*dol_pos;

	i = 0;
	while (str[i])
	{
		dol_pos = get_dol_pos(str[i]);
		while (dol_pos)
		{
			replace_env(str, i, dol_pos, info);
			dol_pos = get_dol_pos(str[i]);
		}
		dol_pos = NULL;
		i++;
	}
}

char	*get_dol_pos(char *str)
{
	int	in_quotes;

	in_quotes = 0;
	while (*str)
	{
		if (*str == '"' && in_quotes == 1)
			in_quotes = 0;
		if (*str == '"' && ft_strchr(str + 1, '"') && in_quotes == 0)
			in_quotes = 1;
		if (*str == '\'' && ft_strchr(str + 1, '\'') && in_quotes == 0)
		{
			while (*(str + 1) != '\'')
				str++;
			str = str + 2;
		}
		if (*str == '$')
			return (str + 1);
		str++;
	}
	return (NULL);
}
