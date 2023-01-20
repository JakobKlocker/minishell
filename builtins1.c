#include "minishell.h"

void    ft_putendlfd(char *s, int fd)
{
	if (!s || !fd)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}

void unset(t_node *node, t_info *info)
{
    int i;

    i = 1;
    while (node->full_cmd[i])
    {
        if (check_exist(info, node->full_cmd[i]) == 0)
                delete_node(node->full_cmd[i], info);
        else if(check_for_sc(node->full_cmd[i]) == 0)
            ft_printf("unset: %s: invalid parameter name\n", node->full_cmd[i]);
        i++;
    }
}

int check_var(t_node *node)
{
    int i;

    i = 0;
    if (check_for_appereance(node->full_cmd[1], '=') == 0)
    {
        while (node->full_cmd[1][i] != '=')
        {
            if (node->full_cmd[1][i] >= 'a' && node->full_cmd[1][i] <= 'z')
                i++;
            else if (node->full_cmd[1][i] >= 'A' && node->full_cmd[1][i] <= 'Z')
                i++;
            else
            {
                i = 0;
                printf("export: not an identifier: ");
                while (node->full_cmd[1][i] != '=')
                    write (1, &node->full_cmd[1][i], 1);
                return (1);
            }
    }
        return (0);
    }
    return (1);
}

void    delete_node(char *str, t_info *info)
{
    t_envlst *temp = info->envp;
    t_envlst *prev;
    
    if (temp != NULL && ft_strcmpeq(temp->var, str) == 0)
    {
        info->envp = temp->next;
        free(temp);
        return;
    }
    while (temp && ft_strcmpeq(temp->var, str) != 0)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}

void    print_err(int err, char *str)
{
    if (err == 2)
        ft_printf("cd: no such file or directory: %s\n", str);
    else if (err == 20)
        ft_printf("cd: not a directory: %s\n", str);

}