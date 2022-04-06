/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:59:20 by lhumbert          #+#    #+#             */
/*   Updated: 2021/10/22 02:26:09 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_getmult(int n)
{
	int	ret;

	ret = 1;
	while (n / ret > 9)
		ret *= 10;
	return (ret);
}

int	ft_initdigits(int *n, char *neg)
{
	char	dgts;
	int		mult;

	*neg = 0;
	dgts = 10;
	if (*n < 0)
	{
		*neg = 1;
		dgts++;
		*n *= -1;
	}
	mult = 1000000000;
	while (*n / mult == 0)
	{
		dgts--;
		mult /= 10;
	}
	return (dgts);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		dgts;
	int		mult;
	char	neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	dgts = ft_initdigits(&n, &neg);
	ret = (char *)malloc(sizeof(char) * (dgts + 1));
	if (!ret)
		return (NULL);
	if (neg)
		*(ret++) = '-';
	mult = ft_getmult(n);
	while (mult > 1)
	{
		*(ret++) = 48 + (n / mult);
		n -= (n / mult) * mult;
		mult /= 10;
	}
	*(ret++) = 48 + n;
	*ret = '\0';
	return (ret - dgts);
}
