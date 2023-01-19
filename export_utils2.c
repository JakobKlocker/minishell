#include "minishell.h"

int ft_strcmpeq(char *str1, char *str2)
{
    int i;

    i = 0;
    if (!str1 || !str2)
        return (-1);
    while (str1[i] && str2[i] && str2[i] != '=' && str1[i] != '=') 
    {
        if (str1[i] != str2[i])
            return str1[i] - str2[i];
        i++;
    }
    return str1[i] - str2[i];
}

void    replace_var(t_info *info, char *str)
{
    t_envlst *temp;

    temp = info->envp;
    while (temp)
    {
        if (ft_strcmpeq(temp->var, str) == 0)
            temp->var = str;
        temp = temp->next;
    }
}

int	ft_isdigit1(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int check_for_sc(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (ft_isalnum1(str[i]) == 0)
            return (0);
        i++;
    }
    return (1);
}

int	ft_isalnum1(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0'
			&& c <= '9'))
		return (1);
	return (0);
}
