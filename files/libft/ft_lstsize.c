/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:30:01 by jklocker          #+#    #+#             */
/*   Updated: 2022/10/11 10:06:59 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	if (lst == NULL)
		return (0);
	i = 1;
	while (lst->next != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
