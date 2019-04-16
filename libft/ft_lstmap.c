/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 12:46:28 by awilk             #+#    #+#             */
/*   Updated: 2017/11/27 15:48:38 by awilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_lst;

	if (lst != NULL)
	{
		if (!(new_lst = ft_lstnew(lst->content, lst->content_size)))
			return (NULL);
		new_lst = f(new_lst);
		if (lst->next)
			new_lst->next = ft_lstmap(lst->next, f);
		return (new_lst);
	}
	return (NULL);
}
