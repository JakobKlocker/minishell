#include "minishell.h"

void    handle_forks(t_info *info)
{
    int fd[2];
    int pid;
    t_node *cur = info->head;

    pipe(fd);
    while(cur)
    {
        pid = fork();
        if(pid == 0)
            check_builtin(cur, info);
        cur = cur->next;
    }
    check_builtin(cur, info);
}
