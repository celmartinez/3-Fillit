/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:34:58 by awilk             #+#    #+#             */
/*   Updated: 2017/11/26 05:42:02 by awilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	int		i;
	char	*stringmem;

	i = 0;
	if (!(stringmem = (char *)malloc(size + 1 * sizeof(char))))
		return (NULL);
	ft_bzero(stringmem, (size + 1));
	return (stringmem);
}
