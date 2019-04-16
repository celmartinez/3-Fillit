/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetritab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 20:18:26 by cmartine          #+#    #+#             */
/*   Updated: 2018/01/25 17:50:14 by awilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	ft_changealpha(char c, int k, char *buf, int t)
{
	char b;

	if (buf[t] == '#')
	{
		b = 'A' + k;
		c = b;
	}
	return (c);
}

static char	*ft_tetriline(t_struct *u, char *buf, int k, int *t)
{
	int j;

	if (!(u->tab[k][u->i] = (char *)malloc(sizeof(char) * 5)))
		return (NULL);
	j = 0;
	while (j < 4)
	{
		u->tab[k][u->i][j] = ft_changealpha(buf[*t], k, buf, *t);
		j++;
		(*t)++;
	}
	u->tab[k][u->i][j] = '\0';
	(*t)++;
	return (u->tab[k][u->i]);
}

char		***ft_tetritab(char *buf, int ret, int k, int t)
{
	int			*pt;
	t_struct	u;

	if (!(u.tab = (char ***)malloc(sizeof(char **) * ((ret / 21) + 2))))
		return (NULL);
	pt = &t;
	while (k < (ret / 21) + 1)
	{
		if (!(u.tab[k] = (char **)malloc(sizeof(char *) * 5)))
			return (NULL);
		u.i = 0;
		while (u.i < 4)
		{
			u.tab[k][u.i] = ft_tetriline(&u, buf, k, &t);
			(u.i)++;
		}
		u.tab[k][u.i] = NULL;
		k++;
		t++;
	}
	u.tab[k] = NULL;
	return (u.tab);
}
