#include "minishell.h"

void    heredoc(t_info *info, int *i, t_node *cur)
{
    char    *line;
    char    *heredoc;
    char    *tmp;

    heredoc = ft_calloc(1,1);
    if(!heredoc)
        call_perror_free(info);
    line = readline("> ");
    while(ft_strcmp(line, info->cmd_input[*i + 1]) != 0)
    {
        tmp = heredoc;
        heredoc = ft_strjoin(heredoc, line);
        free(tmp);
        tmp = heredoc;
        heredoc = ft_strjoin(heredoc, "\n");
        free(tmp);
        line = readline("> ");
    }
    *i = *i + 1;
    cur->heredoc = heredoc;
}
