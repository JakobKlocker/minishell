#include "minishell.h"

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
