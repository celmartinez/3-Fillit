/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:27:47 by awilk             #+#    #+#             */
/*   Updated: 2017/11/23 22:10:50 by awilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int len2;

	len2 = len - 1;
	if (dst < src)
		ft_memcpy(dst, src, len);
	else if (dst > src)
		while (len2 >= 0)
		{
			((char *)dst)[len2] = ((char *)src)[len2];
			len2--;
		}
	return (dst);
}
