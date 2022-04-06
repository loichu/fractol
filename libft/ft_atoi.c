/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 22:14:15 by lhumbert          #+#    #+#             */
/*   Updated: 2021/10/25 20:28:49 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_isspace(char c)
{
	if (c == ' '
		|| c == '\f'
		|| c == '\n'
		|| c == '\r'
		|| c == '\t'
		|| c == '\v')
		return (1);
	else
		return (0);
}

char	*skip_spaces(const char *str)
{
	while (ft_isspace(*str))
		str++;
	return ((char *)str);
}

/*
 *	Checks whether i will overflow after a multplication by 10 and an addition
 *	of a in absolut value. Sign paramater with value 1 or -1 is used to know
 *	the actual sign;
 *
 *	returns -1 if negative overflow, 1 if positive overflow, 0 otherwise.
 */
char	ft_intwilloverflow(int i, int a, char sign)
{
	if (i < 214748364)
		return (0);
	if (i > 214748364 || (sign > 0 && a > 7) || (sign < 0 && a > 8))
		return (sign);
	return (0);
}

int	ft_atoi(const char *str)
{
	char	sign;
	char	*a;
	int		i;

	a = skip_spaces(str);
	sign = 1;
	if (*a == '-' || *a == '+')
	{
		if (*(a++) == '-')
			sign = -1;
	}
	i = 0;
	while (*a == '0')
		a++;
	while (ft_isdigit(*a))
	{
		if (ft_intwilloverflow(i, *a - 48, sign) > 0)
			return (-1);
		if (ft_intwilloverflow(i, *a - 48, sign) < 0)
			return (0);
		i *= 10;
		i += *(a++) - 48;
	}
	return (i * sign);
}
