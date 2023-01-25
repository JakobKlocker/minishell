#include "minishell.h"

char    **list_to_2d(t_info *info)
{
    t_envlst *cur;
    char    **ret;
    int i;

    cur = info->envp;
    ret = malloc(count_var(info) + 1);
    if(!ret)
        call_perror_free(info);
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
    int pid;
    int i;
    int out;

    i = 0;

    envp = list_to_2d(info);
    ft_printf("In executer\n");
    execve(cur->full_path, cur->full_cmd, envp);
}
