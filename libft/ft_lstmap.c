/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:48:56 by jklocker          #+#    #+#             */
/*   Updated: 2022/10/11 14:08:54 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Iterates the list ’lst’ and applies the function
’f’ on the content of each node. Creates a new
list resulting of the successive applications of
the function ’f’. The ’del’ function is used to
delete the content of a node if needed.*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*new_list;

	if (!f || !lst || !del)
		return (NULL);
	new_list = ft_lstnew(f(lst->content));
	if (!new_list)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	ret = new_list;
	while (lst->next)
	{
		lst = lst->next;
		new_list->next = ft_lstnew(f(lst->content));
		if (!new_list)
		{
			ft_lstclear(&new_list, del);
			ft_lstclear(&lst, del);
			return (NULL);
		}
		new_list = new_list->next;
	}
	return (ret);
}

/*
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*real_ret;

	if (lst == NULL)
		return (NULL);
	else if (lst != NULL)
	{
		ret = malloc(sizeof(t_list));
		if (ret == NULL)
			return (NULL);
		real_ret = ret;
	}
	while (lst != NULL)
	{
		ret->content = f(lst->content);
		if (lst->content != NULL)
			del(lst->content);
		ret->next = malloc(sizeof(t_list));
		if (ret->next == NULL)
			return (NULL);
		ret = ret->next;
		lst = lst->next;
	}
	ret->next = NULL;
	return (real_ret);
}
*/