#include "minishell.h"

int	get_node_count(t_info *info)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (info->cmd_input[i])
	{
		if (info->cmd_input[i][0] == '|')
			count++;
		i++;
	}
	return (count);
}

int	get_words_for_node(char **str, int i)
{
	int	ret;

	ret = 0;
	while (str[i] && str[i][0] != '|')
	{
		if (str[i][0] == '<' || str[i][0] == '>')
		{
			i = i + 2;
			continue ;
		}
		i++;
		ret++;
	}
	return (ret);
}

void	malloc_nodes(t_info *info)
{
	int		node_count;
	t_node	*tmp;

	tmp = malloc(sizeof(t_node));
	if (!tmp)
		return ;
	info->head = tmp;
	node_count = get_node_count(info);
	while (node_count > 0)
	{
		tmp->next = malloc(sizeof(t_node));
		tmp = tmp->next;
		node_count--;
	}
	tmp->next = NULL;
}

void	create_fd_out(t_info *info, int *i, t_node *cur)
{
	int	j;
	int	fd;

	if (info->cmd_input[*i][1] == '\0')
		fd = open(info->cmd_input[*i + 1], O_RDWR | O_CREAT, 0777);
	else
		fd = open(info->cmd_input[*i + 1], O_RDWR | O_CREAT | O_APPEND, 0777);
	j = 0;
	while (cur->out[j] != -1 && cur->out[j] != 1)
		j++;
	cur->out[j] = fd;
	*i = *i + 1;
}

void	create_fd_in(t_info *info, int *i, t_node *cur)
{
	int	j;
	int	fd;

	if (info->cmd_input[*i][1] == '\0')
		fd = open(info->cmd_input[*i + 1], O_RDWR);
	j = 0;
	while (cur->in[j] != -1 && cur->in[j] != 0)
		j++;
	cur->in[j] = fd;
	*i = *i + 1;
}

void	create_redircets(t_info *info)
{
	int		i;
	t_node	*cur;

	cur = info->head;
	i = -1;
	while (info->cmd_input[++i])
	{
		if (info->cmd_input[i][0] == '|')
			cur = cur->next;
		if (info->cmd_input[i][0] == '>')
			create_fd_out(info, &i, cur);
		if (info->cmd_input[i][0] == '<' && info->cmd_input[i][1] == '\0')
			create_fd_in(info, &i, cur);
		if (info->cmd_input[i][0] == '<' && info->cmd_input[i][1] == '<')
			heredoc(info, &i, cur);
	}
}

//Test function
void	init_nodes(t_info *info)
{
	t_node	*tmp;

	tmp = info->head;
	while (tmp)
	{
		tmp->full_path = NULL;
		tmp->heredoc = NULL;
		tmp->in[0] = 0;
		tmp->out[0] = 1;
		ft_memset(tmp->in + 1, -1, 1023 * 4);
		ft_memset(tmp->out + 1, -1, 1023 * 4);
		tmp = tmp->next;
	}
}

void	create_full_cmd(t_info *info)
{
	int		i;
	int		j;
	t_node	*tmp;

	tmp = info->head;
	i = 0;
	j = 0;
	while (info->cmd_input[i])
	{
		if (info->cmd_input[i][0] == '|')
		{
			tmp = tmp->next;
			i++;
			j = 0;
			continue ;
		}
		else if (info->cmd_input[i][0] == '<' || info->cmd_input[i][0] == '>')
		{
			i = i + 2;
			continue ;
		}
		tmp->full_cmd[j] = info->cmd_input[i];
		j++;
		i++;
	}
}

void	malloc_2d_nodes(t_info *info)
{
	int		i;
	int		words;
	t_node	*cur;

	cur = info->head;
	i = 0;
	while (info->cmd_input[i])
	{
		words = get_words_for_node(info->cmd_input, i);
		cur->full_cmd = malloc((words + 1) * sizeof(char *));
		cur->full_cmd[words] = NULL;
		while (info->cmd_input[i] && info->cmd_input[i][0] != '|')
			i++;
		cur = cur->next;
		if (info->cmd_input[i])
			i++;
	}
}

int	check_valid_redirects(t_info *info)
{
	int	i;

	i = 0;
	while (info->cmd_input[i])
	{
		if (info->cmd_input[i][0] == '<' || info->cmd_input[i][0] == '>')
		{
			if (!info->cmd_input[i + 1] || info->cmd_input[i + 1][0] == '<'
				|| info->cmd_input[i + 1][0] == '>' || info->cmd_input[i
				+ 1][0] == '|')
			{
				ft_printf("zsh: parse error near `\\n'\n");
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	prepare_nodes(t_info *info)
{
	if (check_valid_redirects(info) == 0)
		return (-1);
	malloc_nodes(info);
	init_nodes(info);
	malloc_2d_nodes(info);
	create_redircets(info);
	create_full_cmd(info);
}
