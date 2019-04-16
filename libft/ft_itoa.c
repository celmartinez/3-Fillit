/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 16:52:46 by awilk             #+#    #+#             */
/*   Updated: 2017/11/26 03:51:55 by awilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_forleng(int n)
{
	int nbr;

	nbr = 1;
	if (n < 0)
	{
		if (n == -2147483648)
			return (12);
		nbr++;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		nbr++;
	}
	return (nbr);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		neg;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = 0;
	len = ft_forleng(n);
	if (n < 0)
	{
		n = -n;
		neg = 1;
	}
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	if (neg == 1)
		str[0] = '-';
	return (str);
}
