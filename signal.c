#include "minishell.h"
#include <signal.h>

void	handle_signals(int type)
{
	if (type == 1)
	{	
		signal(SIGINT, handle_sigint);
		signal(SIGQUIT, handle_sigquit);
	}
	else if (type == 2)
	{
		signal(SIGINT, handle_sigintfork);
		signal(SIGQUIT, handle_sigquitfork);
	}
}

void	handle_sigint(int sig)
{
	if (sig == SIGINT)
	{
		write(2, "\n", 1);
		g_status = 130;
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	handle_sigquit(int sig)
{
	if (sig == SIGQUIT)
	{
		ft_putstr_fd("Quit (core dumped)\n", 2);
		write (2, " ", 1);
		g_status = 130;
	}
}

void	handle_sigintfork(int sig)
{
	if (sig == SIGINT)
	{
		write (2, "\n", 1);
	}
}

void	handle_sigquitfork(int sig)
{
	if (sig == SIGQUIT)
	{
		ft_putstr_fd("Quit (core dumped)\n", 2);
		write (2, " ", 1);
		g_status = 130;
		exit(g_status);
	}
}
