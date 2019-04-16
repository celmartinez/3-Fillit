/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_is_valide.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 20:18:02 by cmartine          #+#    #+#             */
/*   Updated: 2018/01/25 17:51:08 by awilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

static void	ft_free_square(char **tab, int ret)
{
	int i;

	i = 0;
	while (i < (ret / 21) + 2)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static int	ft_tetri_is_valide(char *buf)
{
	int		links;
	int		i;

	links = 0;
	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '.' || buf[i] == '\n')
			i++;
		if (buf[i] == '#')
		{
			if (buf[i + 1] == '#' && i < 18)
				links++;
			if (buf[i + 5] == '#' && i <= 13)
				links++;
			if (buf[i - 1] == '#' && i >= 1)
				links++;
			if (buf[i - 5] == '#' && i >= 5)
				links++;
			i++;
		}
	}
	if (links == 6 || links == 8)
		return (1);
	return (0);
}

static int	ft_is_it_really(char **tab, int ret)
{
	int i;

	i = 0;
	while (i < ((ret / 21 + 1)))
	{
		if (ft_tetri_is_valide(tab[i]) == 1)
			i++;
		else
			return (1);
	}
	return (0);
}

int			ft_search_squares(int ret, char *buf, int k)
{
	int		i;
	int		j;
	int		a;
	char	**tab;

	i = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * ((ret / 21) + 2))))
		return (-1);
	while (i < ((ret / 21) + 1))
	{
		j = 0;
		if (!(tab[i] = (char *)malloc(sizeof(char) * 21)))
			return (-1);
		while (j <= 18 && buf[k] != '\0')
			tab[i][j++] = buf[k++];
		tab[i][j] = '\0';
		k = k + 2;
		i++;
	}
	tab[i] = NULL;
	a = ft_is_it_really(tab, ret);
	ft_free_square(tab, ret);
	return (a);
}
