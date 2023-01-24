#include "minishell.h"

void our_exit(t_node *node, t_info *info)
{
    int i;
    t_node *cur;
    t_node *tmp;
    cur = node;

    i = 0;
    while (cur)
    {
        if (cur->full_cmd != NULL)
        {
            while (cur->full_cmd[i])
                free(cur->full_cmd[i++]);
            free(cur->full_cmd);
        }
        if (cur->full_path)
            free(cur->full_path);
        if (cur->heredoc)
            free(cur->heredoc);
        i = 0;
        tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    i = 0;
    if (info->cmd_input)
        free(info->cmd_input);
    free_list(info);
    exit(g_status);
}

void free_list(t_info *info)
{
    t_envlst *current = info->envp;
    t_envlst *next;
    if (count_var(info) != 0)
    {
        while (current)
        {
            next = current->next;
            free(current->var);
            free(current);
            current = next;
        }
    }
}