/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:12:36 by jklocker          #+#    #+#             */
/*   Updated: 2023/01/30 14:12:38 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		write (2, "\b\b  \b\b", 6);
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
		g_status = 130;
	}
}
