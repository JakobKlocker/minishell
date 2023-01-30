/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_nodes_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:12:18 by jklocker          #+#    #+#             */
/*   Updated: 2023/01/30 14:12:19 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return (0);
}
