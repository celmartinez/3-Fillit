/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:50:46 by awilk             #+#    #+#             */
/*   Updated: 2017/11/27 10:34:58 by awilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
	{
		return (((char*)haystack));
	}
	while (haystack[i] != '\0')
	{
		j = 0;
		while (needle[j] && needle[j] == haystack[i + j])
		{
			j++;
		}
		if (needle[j] == '\0')
			return (&(((char*)haystack)[i]));
		i++;
	}
	return (NULL);
}
