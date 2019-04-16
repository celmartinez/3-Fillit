/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:16:28 by awilk             #+#    #+#             */
/*   Updated: 2017/11/26 06:05:31 by awilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		dest;
	int		tot_len;
	int		end;
	char	*ptr;

	i = 0;
	dest = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return (ft_strdup("\0"));
	end = ft_strlen(s) - 1;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	tot_len = end + 1 - i;
	if (!(ptr = ft_strnew(tot_len)))
		return (NULL);
	while (i <= end)
		ptr[dest++] = s[i++];
	ptr[dest] = '\0';
	return (ptr);
}
