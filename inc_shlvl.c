#include "minishell.h"

void	inc_shlvl(t_info *info)
{
	int			lvl;
	char		*new_str;
	t_envlst	*cur;

	lvl = get_shlvl(info);
	if (lvl == -1)
		return ;
    lvl++;
	new_str = malloc(ft_strlen(ft_itoa(lvl)) + 7);
	if (!new_str)
		exit(1);
	new_str = ft_strjoin("SHLVL=", ft_itoa(lvl));
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
	t_envlst *cur;

	cur = info->envp;
	while (cur)
	{
		if (ft_strncmp(cur->var, "SHLVL=", 6) == 0)
			return (ft_atoi(cur->var + 6));
		cur = cur->next;
	}
	return (-1);
}
