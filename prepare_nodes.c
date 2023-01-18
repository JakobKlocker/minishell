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

// void *create_nodes(t_info *info, int node_count)
// {
//         t_node *head;
//         int i;
//         int j;

//         head = malloc(sizeof(t_node));
//         if(!head)
//             return (NULL);
//         head->full_cmd = malloc((get_words_for_node(info->cmd_input, 0) + 1) * sizeof(char*));
//         info->head = head;
//         i = 0;
//         while(node_count-- > 0 && info->cmd_input[i])
//         {
//             j = 0;
//             while(info->cmd_input[i] && info->cmd_input[i][0] != '|')
//                 head->full_cmd[j++] = info->cmd_input[i++];
//             head->full_cmd[j] = NULL;
//             if(info->cmd_input[i] == NULL)
//                 break;
//             head->next = malloc(sizeof(t_node));
//             head = head->next;
//             head->full_cmd = malloc((get_words_for_node(info->cmd_input, i + 1) + 1) * sizeof(char*));
//             while(info->cmd_input[i] && info->cmd_input[i][0] == '|')
//                 i++;
//         }
//         head->full_cmd[j] = NULL;
// }

void    malloc_nodes(t_info *info)
{
    int node_count;
    t_node *tmp;
    
    tmp = malloc(sizeof(t_node));
    if(!tmp)
        return;
    node_count = get_node_count(info);
    while(node_count > 0)
    {
        tmp->next = malloc(sizeof(t_node));
        tmp = tmp->next;
        node_count--;
    }
    tmp->next = NULL;
}

void    create_fd_out(t_info *info, int *i, t_node *cur)
{
    int j;
    int fd;
    
    if(info->cmd_input[*i][1] == '\0')
        fd = open(info->cmd_input[*i + 1], O_WRONLY | O_CREAT);
    else
        fd = open(info->cmd_input[*i + 1], O_WRONLY | O_CREAT | O_APPEND);
    j = 0;
    while(cur->out[j] != -1)
        j++;
    cur->out[j] = fd;
    *i = *i + 2;
}

void    create_fd_in(t_info *info, int *i, t_node *cur)
{
    int j;
    int fd;
    
    if(info->cmd_input[*i][1] == '\0')
        fd = open(info->cmd_input[*i + 1], O_RDONLY);
    j = 0;
    while(cur->in[j] != -1)
        j++;
    cur->in[j] = fd;
    *i = *i + 2;
}

void    create_redirects(t_info *info)
{
    int i;
    t_node *cur;

    cur = info->head;
    i = -1;
    while(info->cmd_input[++i])
    {
        if(info->cmd_input[i] == '|')
            cur = cur->next;
        if(info->cmd_input[i] == '>')
            create_fd_out(info, &i, cur);
        if(info->cmd_input[i] == "<\0")
            create_fd_in(info, &i, cur);
    }
}

//Test function
void    init_node(t_info *info)
{
    t_node *tmp = info->head;
    while(tmp)
    {
        tmp->full_cmd = NULL;
        tmp->full_path = NULL;
        tmp->in[0] = -1;
        tmp->out[0] = -1;
        tmp->in[1] = -1;
        tmp->out[1] = -1;
        tmp = tmp->next;
    }
}

void    create_full_cmd(t_info *info)
{
    int i;
    int j;
    t_node *tmp;
    
    tmp = info->head;
    i = 0;
    j = 0;
    while(info->cmd_input[i])
    {
        if(info->cmd_input[i][0] == '|')
        {
            tmp = tmp->next;
            i++;
            j = 0;
            continue;
        }
        else if(info->cmd_input[i][0] == info->cmd_input[i][0] == '<' || info->cmd_input[i][0] == '>')
        {
            i = i + 2;
            continue;
        }
        tmp->full_cmd[j] = info->cmd_input[i];
        j++;
        i++;
    }
}

void    prepare_nodes(t_info *info)
{
    malloc_nodes(info);
    // Malloc 2D array inside of nodes first as well!
    init_nodes(info);
    create_redircets(info);
    create_full_cmd(info);
}
