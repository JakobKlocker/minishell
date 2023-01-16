#include "minishell.h"

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
        while (check_if_flag(node->full_cmd[j++]) == 0)
            ind = 0;
        while (node->full_cmd[j])
        {   
            if (is == 0)
                write (node->out[k], " ", 1);
            write(node->out[k], node->full_cmd[j], ft_strlen(node->full_cmd[j++]));
            is = 0;
        }
        if (ind == -1)
            write (node->out[k], "\n", 1);
        }
}

void    cd(t_node *node)
{
    int i;

    // Wenn env steht, hier PWD/OLDPWD "update" machen:
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
    while (*envp)
        printf("%s", *envp++);
}

void check_builtin (t_node *node, char **envp)
{
    int i;

    i = ft_strlen(node->full_cmd[0]);
    if (!node->full_cmd)
        return (0);
    if (ft_strncmp(node->full_cmd[0], "echo", i) && i == 4)
        echo(&node);
    else if (ft_strncmp(node->full_cmd[0], "cd", i) && i == 2)
        cd(&node);
    else if (ft_strncmp(node->full_cmd[0], "pwd", i) && i == 3)
        pwd();
    else if (ft_strncmp(node->full_cmd[0], "env", i) && i == 3)
        env(envp);
    else if (ft_strncmp(node->full_cmd[0], "export", i) && i == 6)
        export(&node, envp);
    else if (ft_strncmp(node->full_cmd[0], "unset", i) && i == 5)
        unset(&node, envp);
}

void    export(t_node *node, t_list *list)
{
    t_list * new_node;
    new_node = node->full_cmd[1];
    ft_lstadd_back()
}

void unset(t_node *node, char **envp)
{

}