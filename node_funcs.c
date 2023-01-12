#include "minishell.h"

void    init_nodes(t_node *head)
{
    while(head)
    {
        head->full_cmd = NULL;
        head->full_path = NULL;
        head->in = 0;
        head->out = 1;
        head = head->next;
    }
}
