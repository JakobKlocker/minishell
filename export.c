#include "minishell.h"

void    export(t_node *node, t_info *info)
{
    
    if (arg_c(node) == 1)
        print_export(node, info);
    else
        export_var(node, info);
}

void    export_var(t_node *node, t_info *info)
{
    int i;
    i = 1;
    while (node->full_cmd[i])
    {
        if (check_for_appereance(node->full_cmd[i], '=') == 0 && check_alpha(node->full_cmd[i]) == 0)
        {
            ft_lstaddback(info);
            ft_lstinsert(info, node->full_cmd[i]);
        }
        i++;
    }
}

void    print_export(t_node *node, t_info *info)
{
    int i;
    char **envp;
    int j;
    int len;
    t_envlst *temp;

    temp = info->envp;
    i = 0;
    j = 0;
    len = 0;
    envp = (char **)malloc(sizeof(char**) * count_var(info) + 1);
    while (temp)
    {
        envp[i] = malloc(sizeof(char *) * (ft_strlen(info->envp->var)));
        ft_strlcpy(envp[i], info->envp->var, ft_strlen(info->envp->var));
        i++;
        temp = temp->next;
    }
    i = 0;
    while (j < count_var(info))
    {
        i = 0;
        while (envp[i] - 1)
        {
            if (ft_strcmp(envp[i], envp[i + 1]) > 0)
            {
                ft_strcpy(envp[count_var(info)], envp[i]);
                ft_strcpy(envp[i], envp[i + 1]);
                ft_strcpy(envp[i + 1], envp[count_var(info)]);
            }
            i++;
        }
        j++;
    }
    print_env(envp);
}

int count_var(t_info *info)
{
    int i;
    t_envlst *temp;
    
    temp = info->envp;
    i = 0;
    while (temp != NULL)
    {
        i++;
        temp = temp->next;
    }
    return (i);
}

void print_env(char **envp)
{
    int i;

    i = 0;
    while (envp[i])
    {
        printf("%s\n", envp[i++]);
    }
}