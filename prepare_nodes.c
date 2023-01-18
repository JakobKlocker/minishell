#include "minishell.h"

int get_node_count(t_info *info)
{
    int count;
    int i;
    
    count = 0;
    i = 0;
    while(info->cmd_input[i])
    {
        if(info->cmd_input[i][0] == '|')
            count++;
        i++;
    }
    return (count);
}

int get_words_for_node(char **str, int  i)
{
    int ret;

    ret = 0;
    while(str[i] && str[i][0] != '|')
    {
        i++;
        ret++;
    }
    return (ret);
}

// void    create_fullcmd_node(t_info *info, t_node *node, int i)
// {
//     int j;
    
//     j = 0;
//     while(info->cmd_input[i] && info->cmd_input[i][0])
// }

void *create_nodes(t_info *info, int node_count)
{
        t_node *head;
        int i;
        int j;

        head = malloc(sizeof(t_node));
        if(!head)
            return (NULL);
        head->full_cmd = malloc((get_words_for_node(info->cmd_input, 0) + 1) * sizeof(char*));
        info->head = head;
        i = 0;
        //create_fullcmd_node();
        while(node_count-- > 0 && info->cmd_input[i])
        {
            j = 0;
            while(info->cmd_input[i] && info->cmd_input[i][0] != '|')
                head->full_cmd[j++] = info->cmd_input[i++];
            head->full_cmd[j] = NULL;
            if(info->cmd_input[i] == NULL)
                break;
            head->next = malloc(sizeof(t_node));
            head = head->next;
            head->full_cmd = malloc((get_words_for_node(info->cmd_input, i + 1) + 1) * sizeof(char*));
            if(info->cmd_input[i][0] == '|')
                i++;
        }
        head->full_cmd[j] = NULL;
}

void    prepare_nodes(t_info *info)
{
    int node_count;

    node_count = get_node_count(info) + 1;
    create_nodes(info, node_count);
}