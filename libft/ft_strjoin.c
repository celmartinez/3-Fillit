/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:19:13 by awilk             #+#    #+#             */
/*   Updated: 2017/11/27 15:17:15 by awilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *ptr;

	if (s1 && s2)
	{
		if (!(ptr = ft_strnew((ft_strlen(s1) + ft_strlen(s2)))))
			return (NULL);
		if (s1)
			ft_strcpy(ptr, s1);
		if (s2)
			ft_strcat(ptr, s2);
		return (ptr);
	}
	return (NULL);
}
