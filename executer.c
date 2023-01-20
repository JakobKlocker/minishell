#include "minishell.h"

char    **list_to_2d(t_info *info)
{
    t_envlst *cur;
    char    **ret;
    int i;

    cur = info->envp;
    ret = malloc(count_var(info) + 1);
    i = 0;
    while(cur)
    {
        ret[i] = cur->var;
        cur = cur->next;
        i++;
    }
    ret[i] = NULL;
    return (ret);
}

void    executer(t_info *info, t_node *cur)
{
    char    **envp;
    
    ft_printf("In executer");
    envp = list_to_2d(info);
    if(execve(cur->full_path, cur->full_cmd, envp) == -1)
        ft_printf("zsh: command not found: %s\n", cur->full_cmd[0]);
    free(envp);
}
