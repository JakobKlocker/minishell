#include "minishell.h"

// int	main(int argc, char **argv, char **envp)
// {
//     t_info info;
//     if (copy_env(&info, envp) == 1)
//         exit (0);
// }

int    copy_env(t_info *info, char **envp)
{
    int i;
    int len;
    envlst_t * head;

    head = (envlst_t *)malloc(sizeof(envlst_t));
    if (!head)
        return (1);
    info->envp = head;
    i = 0;
    while (envp[i])
    {
        if(i != 0)
        {
            head->next = (envlst_t *)malloc(sizeof(envlst_t));
            head = head->next;
        }
        len = ft_strlen(envp[i]);
        head->var = malloc(len + 1);
        memcpy(head->var, envp[i], len);
        head->var[len] = '\0';
        i++;
    }
    head->next = NULL;
    return (0);
}
