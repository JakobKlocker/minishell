#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
    t_info info;
    if (copy_env(&info, envp) == 1)
        exit (0);
}

int    copy_env(t_info *info, char **envp)
{
    int i;
    int len;

    envlst_t * head = NULL;
    head = (envlst_t *)malloc(sizeof(envlst_t));
        if (!head)
            return (1);
    info->envp = head;
    i = 0;
    while (envp[i])
    {
        len = ft_strlen(envp[i]);
        head->var = malloc(len + 1);
        memcpy(head->var, envp[i], len);
        head->var[len] = '\0';
        head->next = NULL;
        head = head->next;
        i++;
    }
    return (0);
}
