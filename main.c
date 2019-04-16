/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:38:40 by awilk             #+#    #+#             */
/*   Updated: 2018/01/25 17:48:46 by awilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

int		main(int argc, char *argv[])
{
	char		buf[BUF_SIZE];
	int			fd;
	t_struct	s;

	if (argc != 2)
	{
		ft_putendl("usage: fillit source_file");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("open () error");
		return (1);
	}
	s.ret = read(fd, buf, BUF_SIZE);
	buf[s.ret - 1] = '\0';
	ft_create_buf(s, buf);
	if (close(fd) == -1)
	{
		ft_putendl("close () error");
		return (1);
	}
	return (0);
}
