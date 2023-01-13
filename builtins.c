#include "minishell.h"

void    echo(t_node *node)
{
    int ind;
    int i;
    int is; 
    int k;

    k = 0;
    while (node->out[k])
    {
        i = 1;
        is = -1;
        ind = -1;
        if (ft_strncmp(node->full_cmd[1], "-n", ft_strlen(node->full_cmd[1])) == 0)
        {
            ind = 0;
            i++;
        }
        while (node->full_cmd[i])
        {
            if (is == 0)
                write (node->out[k], " ", 1);
            write(node->out[k], node->full_cmd[i], ft_strlen(node->full_cmd[i++]));
            is = 0;
        }
        if (ind == -1)
            write (node->out[k], "\n", 1);
        }
}

void    cd(t_node *node)
{
    int i;

    // Wenn env steht, hier OLDPWD "update" machen:
    //  OLDPWD in eigener ENV = pwd();

    i = 0;
    while (node->full_cmd[i])
        i++;
    if(i > 3)
    {
        printf("cd: too many arguments");
        exit (0);
    }
    if (i > 1)
    {
        if(chdir(node->full_cmd[1]) != 0)
            printf("cd: no such file or directory: %s\n", node->full_cmd[1]);
    }
    else
        chdir(getenv("HOME"));
}

void    pwd(void)
{
    char *buf;

    buf = getcwd(NULL, 0);
    ft_putendl_fd(buf, 1);
    free(buf);
}

void env(char **envp)
{
    int i;

    while (envp[i])
        printf("\n%s", envp[i]);
}
