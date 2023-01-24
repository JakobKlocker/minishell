#include "minishell.h"
#include <signal.h>

void  init_sigaction(void)
{
  struct sigaction  sig_int_handler;
  struct sigaction  sig_quit_handler;

  sig_int_handler.sa_handler = handle_sigint;
  sigemptyset(&sig_int_handler.sa_mask);
  sig_int_handler.sa_flags = 0;
  sigaction(SIGINT, &sig_int_handler, NULL);
  sig_quit_handler.sa_handler = handle_sigquit;
  sigemptyset(&sig_quit_handler.sa_mask);
  sig_quit_handler.sa_flags = 0;
  sigaction(SIGQUIT, &sig_quit_handler, NULL);
}

void    handle_sigint(int sig)
{
  if (sig == SIGINT)
  {
    g_status = 130;
    write (2, "\b\b  ", 4);
    rl_on_new_line();
    write (2, "\n", 1);
    rl_replace_line("", 0);
	  rl_redisplay();
  }
}

void  handle_sigquit(int sig)
{
  t_node node;
  t_info info;
  if (sig == SIGQUIT)
  {
    g_status =  130;
    our_exit(&node, &info);
  }
}