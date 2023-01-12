#include "minishell.h"

void    echo(t_node *node)
{
    int ind;
    int i;
    int is; 

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
            write (node->out, " ", 1);
        write(node->out, node->full_cmd[i], ft_strlen(node->full_cmd[i++]));
        is = 0;
    }
    if (ind == -1)
        write (node->out, "\n", 1);
}