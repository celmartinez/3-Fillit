/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:42:38 by awilk             #+#    #+#             */
/*   Updated: 2017/11/27 17:46:20 by awilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*s2;
	int		ls1;
	size_t	i;

	i = 0;
	ls1 = (ft_strlen(s));
	if (!(s2 = (char *)malloc(sizeof(char) * n + 1)))
		return (NULL);
	while (i < n)
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
