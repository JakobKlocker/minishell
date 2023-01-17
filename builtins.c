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
            write(node->out[k], node->full_cmd[j], ft_strlen(node->full_cmd[j]));
            is = 0;
            j++;
        }
        if (ind == -1)
            write (node->out[k], "\n", 1);
        }
}

void    cd(t_node *node, t_info *info)
{
    int i;

    // use export function to update OLDPWD/PWD

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

void env(t_info *info)
{
    while (info->envp)
        printf("%s\n", info->envp++);
}

void check_builtin(t_node *node, t_info *info)
{
    int i;

    i = ft_strlen(node->full_cmd[0]);
    if (!node->full_cmd)
        return (0);
    if (ft_strncmp(node->full_cmd[0], "echo", i) && i == 4)
        echo(node);
    else if (ft_strncmp(node->full_cmd[0], "cd", i) && i == 2)
        cd(node, info);
    else if (ft_strncmp(node->full_cmd[0], "pwd", i) && i == 3)
        pwd();
    else if (ft_strncmp(node->full_cmd[0], "env", i) && i == 3)
        env(info);
    else if (ft_strncmp(node->full_cmd[0], "export", i) && i == 6)
        export(node, info);
    else if (ft_strncmp(node->full_cmd[0], "unset", i) && i == 5)
        unset(node, info);
}

void unset(t_node *node, t_info *list)
{
    int j;
    int i;

    i = 0;
    j = 0;
    while (node->full_cmd[j])
    {
        while (list->envp)
        {
            if(check_equality(node->full_cmd[j], list->envp == 0))
            {
                del_pos(list->head, i);
            }
            i++;
            list->envp++;
        }
        j++;
    }
}

int check_var(t_node *node)
{
    int i;

    i = 0;
    if (check_for_appereance(node->full_cmd[1], '=') == 0)
    {
        while (node->full_cmd[1][i] != '=')
        {
            if (node->full_cmd[1][i] >= 'a' && node->full_cmd[1][i] <= 'z')
                i++;
            else if (node->full_cmd[1][i] >= 'A' && node->full_cmd[1][i] <= 'Z')
                i++;
            else
            {
                i = 0;
                printf("export: not an identifier: ");
                while (node->full_cmd[1][i] != '=')
                    write (1, &node->full_cmd[1][i], 1);
                return (1);
            }
    }
        return (0);
    }
    return (1);
}
