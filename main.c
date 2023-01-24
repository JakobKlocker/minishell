#include "minishell.h"

int g_status = 0;

int	main(int argc, char **argv, char **envp)
{
    (void) argc;
    (void) argv;
    t_info info;
    init_sigaction();
    copy_env(&info, envp);
    get_user_input(&info);
}

void    get_user_input(t_info *info)
{
    char    *input;
    int status;
    input = readline("testshell: ");
    while(ft_strncmp(input, "exit\0", 5) != 0) 
    {
        info->cmd_input = first_split(input);
        expander(info->cmd_input, info);
        remove_quotes(info->cmd_input);
        prepare_nodes(info);
        get_full_path(info);
        handle_forks(info);
        input = readline("testshell: ");
    }
    //Free everything here
}

void    print_2d(char **str)
{
    int i;

    i = 0;
    while(str[i])
    {
        ft_printf("%s\n", str[i]);
        i++;
    }
}

void    print_nodes(t_info *info)
{
    int i;
    t_node *tmp;

    tmp = info->head;
    i = 0;
    while(tmp)
    {
        while(tmp->full_cmd[i])
        {
            ft_printf("%s ", tmp->full_cmd[i]);
            i++;
        }
        i = 0;
        ft_printf("\n");
        tmp = tmp->next;
    }
}