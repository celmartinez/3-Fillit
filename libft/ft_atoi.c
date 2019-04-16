/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:46:36 by awilk             #+#    #+#             */
/*   Updated: 2017/11/24 15:20:14 by awilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_negative(int res, int negative)
{
	if (negative == 1)
		return (-res);
	else
		return (res);
}

int				ft_atoi(const char *str)
{
	int i;
	int res;
	int negative;

	i = 0;
	res = 0;
	negative = 0;
	while (str[i] == '\n' || str[i] == '\r' || str[i] == '\v' || str[i] == '\t'
			|| str[i] == ' ' || str[i] == '\f')
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] == '-' && str[i - 1] != '+')
	{
		negative = 1;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		res *= 10;
		res += (str[i] - 48);
		i++;
	}
	return (ft_negative(res, negative));
}
