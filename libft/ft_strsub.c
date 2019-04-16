/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:58:06 by awilk             #+#    #+#             */
/*   Updated: 2017/11/26 06:00:28 by awilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	int		j;
	size_t	i;

	i = 0;
	j = 0;
	if (!(ptr = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (s)
	{
		while (i < len)
		{
			ptr[i] = s[start];
			i++;
			start++;
		}
		ptr[i] = '\0';
	}
	return (ptr);
}
