/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 20:19:11 by cmartine          #+#    #+#             */
/*   Updated: 2018/01/25 17:49:44 by awilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

static t_coord	ft_find_coord(char ***tab, int k, int i, int j)
{
	t_coord	point;

	point.i1 = 0;
	while (tab[k][i][j] == '.' && j < 4)
	{
		j++;
		if (j == 3 && i < 3 && tab[k][i][j] == '.')
		{
			i++;
			j = 0;
		}
	}
	if (tab[k][i][j] != '.' && tab[k][i][j] != '\0')
	{
		point.i1 = i;
		point.j1 = j;
		if (i < 3 && j >= 1)
		{
			if (tab[k][i + 1][j - 1] != '.' && i < 3 && j >= 1)
				point.j1 = j - 1;
			if (tab[k][i + 1][j - 2] != '.' && i < 3 && j >= 2)
				point.j1 = j - 2;
		}
	}
	return (point);
}

static void		ft_put_tetri(t_struct *s, int k, int c, int *position)
{
	int		i;
	int		j;
	int		m;
	int		n;
	t_coord	pt;

	i = 0;
	j = 0;
	pt = ft_find_coord(s->tab, k, 0, 0);
	m = *position / c;
	n = *position % c;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4 && m < c && n < c)
		{
			if (s->tab[k][i][j] != '.' && s->tab[k][i][j] != '\0' &&
					s->map[m + (i - pt.i1)][n + (j - pt.j1)] == '.')
				s->map[m + (i - pt.i1)][n + (j - pt.j1)] = s->tab[k][i][j];
			j++;
		}
		i++;
	}
}

static char		ft_can_the_tetri_be_putted(t_struct *s, int k, int c,
		int *position)
{
	t_coord	p;

	p = ft_find_coord(s->tab, k, 0, 0);
	p.t = 0;
	p.m = ((*position) / c);
	p.n = ((*position) % c);
	p.i = 0;
	while (p.i < 4 && (p.m + (p.i - p.i1) < c) && (p.m + (p.i - p.i1) >= -3))
	{
		p.j = 0;
		while (p.j < 4 && (p.n + (p.j - p.j1) < c) && (p.m + (p.i - p.i1) < c)
				&& (p.n + (p.j - p.j1) >= -3))
		{
			if (s->tab[k][p.i][p.j] != '.' && s->tab[k][p.i][p.j] != '\0' &&
					s->map[p.m + (p.i - p.i1)][p.n + (p.j - p.j1)] == '.')
				(p.t)++;
			(p.j)++;
		}
		(p.i)++;
	}
	if (p.t == 4)
		return (1);
	while ((*position)++ < c * c)
		return (ft_can_the_tetri_be_putted(s, k, c, position));
	return (0);
}

static char		**ft_delete_tetri(char **map, int k, int c)
{
	int m;
	int n;

	m = 0;
	n = 0;
	while (m < c)
	{
		n = 0;
		while (n < c)
		{
			if (map[m][n] == (k + 'A'))
				map[m][n] = '.';
			n++;
		}
		m++;
	}
	return (map);
}

int				ft_fill_map(t_struct *s, int position, int k, int c)
{
	int m;
	int n;
	int *z;

	if (k == s->ret / 21 + 1)
		return (1);
	if (position == c * c + 1)
		return (0);
	z = &position;
	m = position / c;
	n = position % c;
	if (ft_can_the_tetri_be_putted(s, k, c, &position))
	{
		ft_put_tetri(s, k, c, &position);
		if (ft_fill_map(s, 0, k + 1, c))
			return (1);
		ft_delete_tetri(s->map, k, c);
		if (ft_fill_map(s, position + 1, k, c))
			return (1);
	}
	return (0);
}
