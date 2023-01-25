#include "minishell.h"

void    export(t_node *node, t_info *info)
{
    
    if (arg_c(node) == 1)
        print_export(node, info);
    else
        export_var(node, info);
}


//more than 25 lines
void    export_var(t_node *node, t_info *info)
{
    int i;

    i = 1;
    while (node->full_cmd[i])
    {
        if (check_for_sc(node->full_cmd[i]) == 1)
        {
            if (check_exist(info, node->full_cmd[i]) == 1)
            {
                if (check_for_appereance(node->full_cmd[i], '=') == 0 && ft_isalpha(node->full_cmd[i][0]) == 1)
                {
                    if (!(node->full_cmd[i][0] == '=') && !(ft_strlen(node->full_cmd[i]) == 1))
                    {
                        if ((arg_c(node) > 2 && ft_isdigit(node->full_cmd[i + 1][0]) == 1) || ft_isdigit(node->full_cmd[i][0] == 1))
                            printf("export: not an identifier: %s\n", node->full_cmd[i+1]);
                        ft_lstaddback(info);
                        ft_lstinsert(info, node->full_cmd[i]);
                    }
                }
                else
                    print_arg(node->full_cmd[i], 2);
            }
            else
            {
                if (check_for_appereance(node->full_cmd[i], '=') == 0 && ft_isalpha(node->full_cmd[i][0]) == 1)
                    replace_var(info, node->full_cmd[i]);
            }   
            }
        else
            print_arg(node->full_cmd[i], 1);
        i++;
    }
}

void    print_export(t_node *node, t_info *info)
{
    int i;
    char **envp;
    int j;
    char *temp;

    j = 0;
    envp = list_to_2d(info);
    while (j < count_var(info))
    {
        i = 0;
        while (i < count_var(info) - 1)
        {
            if (ft_strcmp(envp[i], envp[i + 1]) > 0)
            {
                temp = envp[i];
                envp[i] = envp[i + 1];
                envp[i + 1] = temp;
            }
            i++;
        }
        j++;
    }
    print_env(envp);
    free(envp);
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
        printf("declare -x %s\n", envp[i]);
        i++;
    }
}