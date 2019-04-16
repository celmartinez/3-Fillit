/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_is_valide.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 20:18:48 by cmartine          #+#    #+#             */
/*   Updated: 2018/01/25 17:49:10 by awilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_check_hash(char *buf, int ret, t_point *c, int i)
{
	if (buf[i] == '\0' && (i + 1 == ret) && c->line == 3 && c->t == 4)
		return (0);
	else
		return (1);
}

int			ft_square_is_valide(int ret, char *buf, int i)
{
	t_point c;

	while (i < ret - 1 && ret != 0)
	{
		c.line = 0;
		c.t = 0;
		while (c.line != 4)
		{
			c.car = 0;
			while ((buf[i] == '.' || buf[i] == '#') && c.car++ != 4)
			{
				if (buf[i] == '#')
					c.t++;
				i++;
			}
			if (!(c.car == 4 && buf[i] == '\n'))
				return (ft_check_hash(buf, ret, &c, i));
			c.line++;
			i++;
		}
		if (!(c.line == 4 && buf[i] == '\n') && c.t != 4)
			return (1);
		i++;
	}
	return (1);
}
