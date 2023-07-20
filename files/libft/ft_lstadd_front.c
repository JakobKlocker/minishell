/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:53:22 by jklocker          #+#    #+#             */
/*   Updated: 2022/10/11 14:09:08 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
lst: The address of a pointer to the first link of
a list.
new: The address of a pointer to the node to be
added to the list.
*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = lst[0];
	lst[0] = new;
}
