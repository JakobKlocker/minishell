#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
    t_info info;
    copy_env(&info, envp);
    get_user_input(&info);
}

void    get_user_input(t_info *info)
{
    char    *input;

    input = readline("testshell: ");
    while(ft_strncmp(input, "exit\0", 5) != 0) 
    {
        write(1, "\n", 1);
        info->cmd_input = first_split(input);
        expander(info->cmd_input, info);
        print_2d(info->cmd_input);
        write(1, "\n", 1);
        input = readline("minishell:");
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