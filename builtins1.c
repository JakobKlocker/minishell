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

// void unset(t_node *node, t_info *list)
// {
//     int j;
//     int i;

//     i = 0;
//     j = 0;
//     while (node->full_cmd[j])
//     {
//         while (list->envp)
//         {
//             if(check_equality(node->full_cmd[j], list->envp == 0))
//             {
//                 del_pos(list->head, i);
//             }
//             i++;
//             list->envp++;
//         }
//         j++;
//     }
// }

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
