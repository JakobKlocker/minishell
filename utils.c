#include "minishell.h"

int check_if_flag(char *str)
{
    int i;

    i = 0;
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

int check_for_appereance(char *str, char c)
{
    int i;

    i = 0;
    while(str[i])
    {
        if (str[i] == c)
            return (0);
        i++;
    }
    return (1);
}


int check_equality(char *str1, char *str2)
{
    int i;
    
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

void    edit_opwd(t_node *node, t_info *info)
{
    
}

int check_alpha(char *str)
{
    int i;
    
    i = 0;
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
            i++;
        else
            return (-1);
    }
    return (0);
}

int arg_c(t_node *node)
{
    int i;

    i = 0;
    while (node->full_cmd[i])
        i++;
    return (i);
}