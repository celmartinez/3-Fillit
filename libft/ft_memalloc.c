/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 09:44:20 by awilk             #+#    #+#             */
/*   Updated: 2017/11/21 19:32:44 by awilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*memptr;

	if (!(memptr = (void *)malloc(size * sizeof(void))))
		return (NULL);
	else
		ft_bzero(memptr, size);
	return (memptr);
}
