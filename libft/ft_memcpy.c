/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:22:20 by awilk             #+#    #+#             */
/*   Updated: 2017/11/20 21:19:48 by awilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int				i;
	char			*dest;
	const char		*source;

	i = 0;
	dest = dst;
	source = src;
	while (n > 0)
	{
		dest[i] = source[i];
		i++;
		n--;
	}
	return (dst);
}
