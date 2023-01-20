#include "minishell.h"

void    handle_forks(t_info *info)
{
    int fd[2];
    int pid;
    t_node *cur = info->head;
    int stdin_copy = dup(0);
    int stdout_copy = dup(1);

    pipe(fd);
    while(cur)
    {
        pid = fork();
        if(cur->next)
        {
            dup2(fd[0], 0);
            dup2(fd[1], 1);
        }
        else
        {
            dup2(stdin_copy, 0);
            dup2(stdout_copy, 1);
        }
        if(pid == 0)
            check_builtin(cur, info);
        wait(NULL);
        cur = cur->next;
    }
}
