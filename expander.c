#include "minishell.h"

int get_len_env_var(char *env_pos)
{
    int i;

    i = 0;
    while(env_pos[i] != ' ' && env_pos[i] != '\n' && env_pos[i] != '\0')
        i++;
    return (i);
}

char    *get_env_for_var(t_info *info, char *dol_pos, int len)
{
    while()
}

void    replace_env(char **str, int i, char *dol_pos, t_info *info)
{
    int len;

    char *env_pos;
    len = get_len_env_var(dol_pos);
    get_env_for_var()
}

void    expander(char   **str, t_info *info)
{
    int i;
    char    *dol_pos;

    i = 0;
    while(str[i])
    {
        dol_pos = get_dol_pos(str[i]);
        if(dol_pos)
            replace_env(str, i, dol_pos, info);
        
        dol_pos = NULL;
    }
}

char    *get_dol_pos(char *str)
{
    int i;

    while(*str)
    {
        if(*str == '\'' && ft_strchr(str + 1, '\''))
        {
            while(str + 1 != '\'')
                str++;
            str = str + 2;
        }
        if(*str == '$')
            return (str);
        str++;
    }
    return (NULL);
}