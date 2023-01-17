#include "minishell.h"

void    export(t_node *node, t_list *list)
{
    
    if (arg_c(node) == 1)
        print_export(node, list);
    else
        export_var(node, list);

    
}

void    export_var(t_node *node, t_list *list)
{
    int i;

    i = 1;
    while (node->full_cmd[i])
    {
        if (check_for_appereance(node->full_cmd[i], '=') == 0 && check_alpha(node->full_cmd[i] == 0))
        {
            list->next = node->full_cmd[i];
            ft_lstadd_back(list, list->next);
            list->next = NULL;
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
    char *temp;

    t_info *temp = info->head;
    i = 0;
    j = 0;
    len = 0;
    envp = (char **) malloc(sizeof(char**) * count_var(info) + 1);
    while (temp != NULL)
    {
        envp[i] = malloc(sizeof(char *) * (ft_strlen(info->envp->var)));
        ft_strlcpy(envp[i], info->envp->var, ft_strlen(info->envp->var));
        i++;
        temp = temp->envp->next; 
    }
    i = 0;
    while (j < count_var(info))
    {
        i = 0;
        while (envp[i] - 1)
        {
            if (strcmp(envp[i], envp[i + 1]) > 0)
            {
                ft_strlcpy(envp[count_var(info)], envp[i], ft_strlen(envp[i]) + 1);
                ft_strlcpy(envp[i], envp[i + 1], ft_strlen(envp[i + 1]) + 1);
                ft_strlcpy(envp[i + 1], envp[count_var(info)], ft_strlen(envp[count_var(info)]));
            }
            i++;
        }
        j++;
    }
}

int count_var(t_info *info)
{
    int i;
    t_info *temp;
    
    temp = info->head;
    i = 0;
    while (temp != NULL)
    {
        i++;
        temp = temp->envp->next;
    }
    return (i);
}