#include "minishell.h"

void    our_exit(t_node *node, t_info *info)
{
    int i;
    
    i = 0;
    if(node->full_cmd[0] == 0)
    {
        while (node->full_cmd[i])
            free(node->full_cmd[i++]);
        free (node->full_cmd);
    }
    if (node->full_path)
        free (node->full_path);
    if (node->heredoc)
        free (node->heredoc);
    free (info->head);
    i = 0;
    while (info->cmd_input[i])
        free (info->cmd_input[i++]);
    free (info->cmd_input);
    exit(g_status);
}

void    free_list(t_info *info)
{
    t_envlst *current = info->envp;
    t_envlst *next;
    if (count_var(info) != 0)
    {
        while (current)
        {
            next = current->next;
            free (current);
            current = next;
        }
    }
}