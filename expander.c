#include "minishell.h"

int is_env_var(char *str)
{
    int in_quote;
    int in_double_quote;
    
    in_quote = 0;
    in_double_quote = 0;
    while(*str)
    {
        if(*str == '\'' && in_double_quote == 0 && ft_strchr(str + 1, '\''))
            in_quote = 1;
        if()

    }
}
int is_env_var(char *str)
{
    int in_quote;
    int in_double_quote;
    
    in_quote = 0;
    in_double_quote = 0;
    while(*str)
    {
        if(*str == '\'' && in_double_quote == 0 && ft_strchr(str + 1, '\''))
            in_quote = 1;
        if()
    }
}
{
    int i;
    i = 0;
    while(cmd[i])
    {
        is_env_var(cmd[i]);
    }
}