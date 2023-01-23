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
        if(pid == 0)
        check_builtin(cur, info);
        wait(NULL);
        cur = cur->next;
    }
}
