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
    if (str1[i] == '=' || str2[i] == '=')
        return (0);
    else
        return str1[i] - str2[i];
}

void    replace_var(t_info *info, char *str)
{
    t_envlst *temp;

    temp = info->envp;
    while (temp)
    {
        if (ft_strcmpeq(temp->var, str) == 0)
            temp->var = ft_strdup(str);
        temp = temp->next;
    }
    g_status = 0;
}

int check_for_sc(char *str)
{
    int i;

    i = 0;
    while (str[i] && str[i] != '=')
    {
        if (ft_isalnum(str[i]) == 0)
            return (0);
        i++;
    }
    return (1);
}

void print_arg(char *str, int type)
{
    int i;

    i = 0;
    if (type == 1)
    {
        ft_putstr_fd("bash: export: `", 2);
        ft_printf (str);
        ft_putstr_fd("': not a valid identifier\n", 2);        
        g_status = 1;
    }       
}
