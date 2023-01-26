#include "minishell.h"

void    heredoc(t_info *info, int *i, t_node *cur)
{
    char    *line;
    char    *heredoc;
    char    *tmp;
    int     fd;

    fd = open(ft_itoa(*i), O_CREAT | O_WRONLY | O_TRUNC, 777);
    line = readline("> ");
    while(ft_strcmp(line, info->cmd_input[*i + 1]) != 0)
    {
        ft_putendl_fd(line, fd);
        line = readline("> ");
    }
    cur->heredoc = ft_strdup(ft_itoa(*i));
    close(fd);
    fd = open(ft_itoa(*i), O_CREAT | O_RDONLY, 777);
    cur->in = fd;
    *i = *i + 1;
}
