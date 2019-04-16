/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 19:05:45 by awilk             #+#    #+#             */
/*   Updated: 2017/11/26 04:46:44 by awilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_words(const char *s, char c)
{
	int		w_counter;
	size_t	i;

	w_counter = 0;
	i = 0;
	while (i < ft_strlen(s))
	{
		while (((char *)s)[i] == c)
		{
			if (((char *)s)[i + 1] == '\0')
				return (w_counter);
			i++;
		}
		while (((char *)s)[i] != c && ((char *)s)[i] != '\0')
			i++;
		w_counter++;
	}
	return (w_counter);
}

static char			**ft_tab_fill(const char *s, char c, char **tab)
{
	int w;
	int i;
	int j;

	w = 0;
	i = 0;
	if (s[0] == '\0')
	{
		tab[i] = NULL;
		return (tab);
	}
	while (i < ft_words(s, c))
	{
		j = 0;
		if (!(tab[i] = malloc(sizeof(char *) * ft_strlen(s) + 1)))
			return (NULL);
		while (s[w] == c && s[w] != '\0')
			w++;
		while (s[w] != c && s[w] != '\0')
			tab[i][j++] = s[w++];
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

char				**ft_strsplit(const char *s, char c)
{
	char **tab;

	if (s != NULL)
	{
		if (!(tab = malloc(sizeof(char *) * (ft_words(s, c) + 1))))
			return (NULL);
		return (ft_tab_fill(s, c, tab));
	}
	return (NULL);
}
