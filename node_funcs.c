#include "minishell.h"

void    init_nodes(t_node *head)
{
    while(head)
    {
        head->full_cmd = 0;
        head->full_path = 0;
        head->in = 0;
        head->out = 1;
        head = head->next;
}