#include "minishell.h"

int check_builtin(t_node *node, t_info *info)
{
    int i;

    if (!node->full_cmd)
        return (0);
    i = ft_strlen(node->full_cmd[0]);
    if (ft_strcmp(node->full_cmd[0], "echo") == 0 && i == 4)
        echo(node);
    else if (ft_strcmp(node->full_cmd[0], "cd") == 0 && i == 2)
        cd(node, info);
    else if (ft_strcmp(node->full_cmd[0], "pwd") == 0 && i == 3)
         pwd();
    else if (ft_strcmp(node->full_cmd[0], "env") == 0 && i == 3)
        env(info);
    else if (ft_strcmp(node->full_cmd[0], "export") == 0 && i == 6)
        export(node, info);
    else if (ft_strncmp(node->full_cmd[0], "unset", i) == 0 && i == 5)
        unset(node, info);
    else
        return (0);
    return (1);
}

void    echo(t_node *node)
{
    int ind;
    int is; 
    int k;
    int j;

    k = 0;
    while (node->out[k])
    {
        is = -1;
        ind = -1;
        j = 1;
        while (check_if_flag(node->full_cmd[j]) == 0)
        {
            ind = 0;
            j++;
        }
        while (node->full_cmd[j])
        {   
            if (is == 0)
                write (node->out[k], " ", 1);
            write(node->out[k], node->full_cmd[j], ft_strlen(node->full_cmd[j]));
            is = 0;
            j++;
        }
        if (ind == -1)
            write (node->out[k], "\n", 1);
        k++;
        }
}

void    cd(t_node *node, t_info *info)
{
    int i;

    acess_env(info, 1);
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
            print_err(errno, node->full_cmd[1]);
    }
    else
        chdir(getenv("HOME"));
    acess_env(info, 0);
}

void    pwd(void)
{
    char *buf;

    buf = getcwd(NULL, 0);
    ft_putendlfd(buf, 1);
    free(buf);
}

void env(t_info *info)
{
    t_envlst *temp = info->envp;
    while (temp->next != NULL)
    {
        printf("%s\n", temp->var);
        temp = temp->next;
    }
}