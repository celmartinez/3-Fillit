/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:35:36 by awilk             #+#    #+#             */
/*   Updated: 2017/11/27 17:47:25 by awilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(const char *s)
{
	int		i;
	int		j;
	char	*s2;

	if (s != NULL)
	{
		i = ft_strlen(s) - 1;
		if (!(s2 = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
			return (NULL);
		j = 0;
		while (i >= 0)
			s2[j++] = s[i--];
		s2[j] = '\0';
		return (s2);
	}
	return (NULL);
}
