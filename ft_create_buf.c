/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_buf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 20:17:20 by cmartine          #+#    #+#             */
/*   Updated: 2018/01/25 17:49:23 by awilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

static void		ft_free_map(char **map, int c)
{
	int m;

	m = 0;
	while (m < c + 1)
	{
		free(map[m]);
		m++;
	}
	free(map);
}

static void		ft_free_tab(char ***tab, int ret)
{
	int k;
	int i;

	k = 0;
	while (k < ret / 21 + 1)
	{
		i = 0;
		while (i < 4)
		{
			free(tab[k][i]);
			i++;
		}
		free(tab[k]);
		k++;
	}
	free(tab);
}

static int		ft_sqrt(int nb)
{
	int i;

	i = 0;
	while (i * i < nb)
		i++;
	return (i);
}

static char		**ft_create_map(int c)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	if (!(map = (char **)malloc(sizeof(char *) * c + 1)))
		return (NULL);
	while (i < c)
	{
		if (!(map[i] = (char *)malloc(sizeof(char) * c + 1)))
			return (NULL);
		j = 0;
		while (j < c)
		{
			map[i][j] = '.';
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}

int				ft_create_buf(t_struct s, char *buf)
{
	if (ft_square_is_valide(s.ret, buf, 0) == 1
			|| ft_search_squares(s.ret, buf, 0) == 1)
	{
		ft_putendl("error");
		return (1);
	}
	s.c = ft_sqrt(((s.ret / 21) + 1) * 4);
	if (ft_square_is_valide(s.ret, buf, 0) != 1 &&
			ft_search_squares(s.ret, buf, 0) != 1)
	{
		s.tab = ft_tetritab(buf, s.ret, 0, 0);
		s.a = 0;
		s.b = 0;
		while (s.b != 1 && s.a < 30)
		{
			s.map = ft_create_map(s.c + s.a);
			s.b = ft_fill_map(&s, 0, 0, s.c + s.a);
			if (s.b == 1)
				ft_show_map(s.map);
			ft_free_map(s.map, s.c + s.a);
			s.a++;
		}
		ft_free_tab(s.tab, s.ret);
	}
	return (0);
}
