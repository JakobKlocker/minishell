#include "minishell.h"

void    acess_env(t_info *info, int id)
{
    char *buf;
    t_envlst *temp;

    temp = info->envp;
    while (temp->next && id == 1)
    {
        if (ft_strncmp(temp->var, "OLDPWD", 6) == 0)
        {
            buf = getcwd(NULL, 0);
            temp->var = ft_strjoin("OLDPWD=", buf);
        }
        temp = temp->next;
    }
    while (temp->next && id == 0)
    {
        if (ft_strncmp(temp->var, "PWD", 3) == 0)
        {
            buf = getcwd(NULL, 0);
            temp->var = ft_strjoin("PWD=", buf);
        }
        temp = temp->next;
    }
}

void    our_exit(t_node *node, t_info *info)
{
    if (arg_c(node) > 2)
        ft_printf("exit: too many arguments\n");
    else
       //free everything 
    exit (g_status);
}

