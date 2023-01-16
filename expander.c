#include "minishell.h"

#include "first_split.c"
#include "env_funcs.c"

char    *get_env_for_var(t_info *info, char *dol_pos, int len);
void    replace_env(char **str, int i, char *dol_pos, t_info *info);
void    expander(char   **str, t_info *info);
char    *get_dol_pos(char *str);


int	main(int argc, char **argv, char **envp)
{
    t_info info;
    char *line;
    char **input;
     size_t n = 100;

    line = malloc(100);
	getline(&line, &n, stdin);
    copy_env(&info, envp);
    input = first_split(line);
    expander(input, &info);
    ft_printf("%s", input[0]);
}

int get_len_env_var(char *var)
{
    int i;

    i = 0;
    while(var[i] != ' ' && var[i] != '\n' && var[i] != '\0' && var[i] != '\'' && var[i] != '"')
        i++;
    return (i);
}

char    *get_env_for_var(t_info *info, char *dol_pos, int len)
{
    envlst_t *tmp;
    char    tmp_repl;
    char    *ret;
    tmp_repl = dol_pos[len];
    dol_pos[len] = '\0';
    tmp = info->envp;
    while(tmp)
    {
        if(ft_strnstr(tmp->var, dol_pos, len) && tmp->var[len] == '=')
        {
            ret = ft_strnstr(tmp->var, dol_pos, len) + len + 1;
            dol_pos[len] = tmp_repl;
            return (ret);
        }
        tmp = tmp->next;
    }
}

char    *do_replace(char *str, char *env_pos, char *dol_pos, int our_var_len)
{
    char *ret;
    int i;
    int ptr_dif;

    ptr_dif = (unsigned int)dol_pos - (unsigned int)str;

    ret = malloc(ft_strlen(str) - our_var_len + 1 + ft_strlen(env_pos) + 1);
    if(ret == NULL)
        return (NULL);
    if(0 < ptr_dif)
        ft_memcpy(ret, str, ptr_dif);
    ft_memcpy(ret + ptr_dif, env_pos, ft_strlen(env_pos));
    ft_memcpy(ret + ptr_dif + ft_strlen(env_pos), str + ptr_dif + our_var_len + 1, ft_strlen(str + ptr_dif + our_var_len + 1));
    ret[i] = '\0';
    return (ret);
}

void    replace_env(char **str, int i, char *dol_pos, t_info *info)
{
    int our_var_len;
    char *env_var;
    char *env_pos;
    char *ret;

    our_var_len = get_len_env_var(dol_pos);
    env_pos = get_env_for_var(info, dol_pos, our_var_len);
    ret = do_replace(str[i], env_pos, dol_pos - 1, our_var_len);
    free(str[i]);
    str[i] = ret;
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
        {
            replace_env(str, i, dol_pos, info);
        }
        dol_pos = NULL;
        i++;
    }
}

char    *get_dol_pos(char *str)
{
    int i;
    int in_quotes;

    in_quotes = 0;
    while(*str)
    {
        if(*str == '"' && in_quotes == 1)
            in_quotes == 0;
        if(*str == '"' && ft_strchr(str + 1, '"') && in_quotes == 0)
            in_quotes = 1;
        if(*str == '\'' && ft_strchr(str + 1, '\'') && in_quotes == 0)
        {
            while(*(str + 1) != '\'')
                str++;
            str = str + 2;
        }
        if(*str == '$')
            return (str + 1);
        str++;
    }
    return (NULL);
}