/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:56:44 by awilk             #+#    #+#             */
/*   Updated: 2017/11/21 19:28:06 by awilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	n;
	size_t	len;

	i = 0;
	j = 0;
	n = size;
	while (n-- != 0 && dst[i] != '\0')
		i++;
	len = &dst[i] - &dst[0];
	n = size - len;
	if (n == 0)
		return (len + ft_strlen(src));
	while (src[j] != '\0')
	{
		if (n != 1)
		{
			dst[i++] = src[j];
			n--;
		}
		j++;
	}
	dst[i] = '\0';
	return (len + ((&src[j] - (&src[0]))));
}
