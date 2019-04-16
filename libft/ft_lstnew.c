/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 10:58:59 by awilk             #+#    #+#             */
/*   Updated: 2017/11/28 16:01:58 by awilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *ptr;

	if (!(ptr = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == 0)
	{
		ptr->content = NULL;
		ptr->content_size = 0;
	}
	else
	{
		ptr->content = ft_memcpy(ft_memalloc(content_size), content,
				content_size);
		ptr->content_size = content_size;
	}
	ptr->next = NULL;
	return (ptr);
}
