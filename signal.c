#include "minishell.h"
#include <signal.h>

// void  init_sigaction(t_info *info)
// {
//   struct sigaction  sig_int_handler;
//   struct sigaction  sig_quit_handler;

//   sig_int_handler.sa_handler = handle_sigint;
//   sigemptyset(&sig_int_handler.sa_mask);
//   sig_int_handler.sa_flags = 0;
//   sigaction(SIGINT, &sig_int_handler, NULL);
//   sig_quit_handler.sa_handler = handle_sigquit;
//   sigemptyset(&sig_quit_handler.sa_mask);
//   sig_quit_handler.sa_flags = 0;
//   sigaction(SIGQUIT, &sig_quit_handler, NULL);
// }

// void    handle_sigint(int sig)
// {
//   if (sig == SIGINT)
//   {
//     g_status = 130;
//     write (2, "\b\b  ", 4);
//     rl_on_new_line();
//     write (2, "\n", 1);
//     rl_replace_line("", 0);
// 	  rl_redisplay();
//   }
// }

// void  handle_sigquit(int sig)
// {

//   if (sig == SIGQUIT)
//   {
//     g_status =  130;
//   }
// }

void  init_sigaction(t_info *info)
{
    struct sigaction  sig_int_handler;
    struct sigaction  sig_quit_handler;

    sig_int_handler.sa_handler = handle_sigint;
    sigemptyset(&sig_int_handler.sa_mask);
    sig_int_handler.sa_flags = 0;
    sigaction(SIGINT, &sig_int_handler, NULL);
    sig_quit_handler.sa_sigaction = handle_sigquit;
    sigemptyset(&sig_quit_handler.sa_mask);
    sig_quit_handler.sa_flags = SA_SIGINFO;
    sig_quit_handler.sa_flags |= SA_RESTART;
    sig_quit_handler.sa_sigaction = (void *)info;
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

void  handle_sigquit(int sig, siginfo_t *info, void *ptr)
{
    t_info *data_ptr = (t_info *)ptr;
    ft_printf("Hello");
    if (sig == SIGQUIT)
    {
        g_status =  130;
        exit(0);
        // our_exit(data_ptr->head, data_ptr);
    }
}
