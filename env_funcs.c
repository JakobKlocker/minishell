#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
    t_info info;
    copy_env(&info, envp);
    int i = 0;
    while(info.envp[i])
    {
        ft_printf("%s\n", info.envp[i]);
        i++;
    }
}

static int    get_env_lines(char **envp)
{
    int i;
    i = 0;
    while(envp[i])
    {
        i++;
    }
    return (i);
}

void    copy_env(t_info *info, char **envp)
{
    int i;
    int len;
    i = 0;

    info->envp = malloc(sizeof(char**) * (get_env_lines(envp) + 1));
    while(envp[i])
    {
        len = ft_strlen(envp[i]);
        info->envp[i] = malloc(len + 1);
        memcpy(info->envp[i], envp[i], len);
        info->envp[i][len] = '\0';
        i++;
    }
    info->envp[i] = NULL;
}
