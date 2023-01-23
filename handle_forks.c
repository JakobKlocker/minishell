#include "minishell.h"

void	add_pipe_fd(t_node *node);
void    handle_executer(t_info *info, t_node *cur);


void	handle_forks(t_info *info)
{
	int		pid;
	char	buffer[100];
	int		is_builtin;
	t_node	*cur;

	cur = info->head;
	pipe(info->fd);
	while (cur)
	{
        add_pipe_fd(cur);
		is_builtin = check_builtin(cur, info);
		if (is_builtin == 0)
		{
			pid = fork();
			if (pid == 0)
			{
                handle_executer(info, cur);
                exit(3);
			}
		}
		wait(NULL);
		cur = cur->next;
	}
}

void    handle_executer(t_info *info, t_node *cur)
{
    int i;
    int j;
    int pid;

    i = 0;
    if(!cur->full_path)
    {

        ft_printf("zsh: command not found: %s\n", cur->full_cmd[0]);
        return;
    }
    while(cur->out[i] != -1)
    {
        j = 0;
        while(cur->in[j] != -1)
        {
            dup2(cur->in[j], 0);
            dup2(cur->out[i], 1);
            if(cur->heredoc)
                ft_putstr_fd(cur->heredoc, cur->out[i]);
            if(fork() == 0)
                executer(info, cur);
            wait(NULL);
            j++;
        }
        i++;
    }
}


void	add_pipe_fd(t_node *node)
{
	int i;

	i = 0;
	t_node *cur;

	cur = node->next;
    if(!cur)
        return;
	while (cur->in[i] != -1 && cur->in[i] != 0)
		i++;
	if (cur->in[i] != 0)
		cur->in[i] = 0;
	i = 0;
	while (cur->out[i] != -1 && cur->out[i] != 1)
		i++;
	if (cur->out[i] != 1)
		cur->out[i] = 1;
}