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
            temp->var = str;
        temp = temp->next;
    }
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
        ft_printf ("export: not valid in this context: ");
    else if (type == 2)
        ft_printf("export: not an identifier: ");
    while (str[i] != '=')
        write (1, &str[i++], 1);
    write (1, "\n", 1);
}
