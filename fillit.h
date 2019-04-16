/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:52:41 by awilk             #+#    #+#             */
/*   Updated: 2018/01/25 17:52:52 by awilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H
# define BUF_SIZE 5000

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_coord
{
	int			t;
	int			m;
	int			n;
	int			i;
	int			j;
	int			i1;
	int			j1;
}				t_coord;

typedef struct	s_struct
{
	int			ret;
	int			i;
	int			a;
	int			b;
	int			c;
	char		**map;
	char		***tab;
}				t_struct;

typedef struct	s_point
{
	int			line;
	int			car;
	int			t;
}				t_point;

int				ft_square_is_valide(int ret, char *buf, int i);
int				ft_search_squares(int ret, char *buf, int k);
int				ft_create_buf(t_struct s, char *buf);
char			***ft_tetritab(char *buf, int ret, int k, int t);
int				ft_fill_map(t_struct *s, int position, int k, int c);
void			ft_show_map(char **map);

#endif
