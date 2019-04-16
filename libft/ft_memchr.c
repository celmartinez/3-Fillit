/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:05:26 by awilk             #+#    #+#             */
/*   Updated: 2017/11/27 09:43:27 by awilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long	i;
	char			*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		if (((unsigned char *)str)[i] == ((unsigned char)c))
			return (&((unsigned char*)s)[i]);
		i++;
	}
	return (NULL);
}
