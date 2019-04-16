/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:55:04 by awilk             #+#    #+#             */
/*   Updated: 2017/11/18 14:43:40 by awilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	int				j;
	unsigned char	cstr;
	char			*str;

	i = 0;
	j = 0;
	cstr = c;
	str = (char *)b;
	while (i < len)
	{
		str[i] = cstr;
		i++;
	}
	while (i != len)
	{
		i++;
	}
	return (b);
}
