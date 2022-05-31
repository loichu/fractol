/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:43:00 by lhumbert          #+#    #+#             */
/*   Updated: 2022/05/31 21:48:59 by loichu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		integer_part(char *nb, int res)
{
	if (ft_isdigit(*nb))
		return (integer_part(nb + 1, res * 10 + (*nb - 48)));
	return (res);
}

double	decimal_part(char *nb)
{
	double	res;
	int		mult;

	res = 0;
	mult = 10;
	while (ft_isdigit(*nb))
	{
		res += (double)(*nb++ - 48) / mult;
		mult *= 10;
	}
	return (res);
}

double	ft_atof(char *nb)
{
	int		sign;
	char	**split;
	double	res;

	sign = 1;
	if (*nb == '-')
		sign = -1;
	if (*nb == '+' || *nb == '-')
		nb++;
	split = ft_split(nb, '.');
	res = integer_part(*split++, 0);
	if (*split)
		res += decimal_part(*split);
	printf("sign: %i\n", sign);
	return (res * sign);
}

bool	check_format(char *cnb, bool is_real)
{
	if (*cnb == '+' || *cnb == '-')
		cnb++;
	if (!ft_isdigit(*cnb))
		return (false);
	while (ft_isdigit(*cnb))
		cnb++;
	if (*cnb == '.')
	{
		cnb++;
		while (ft_isdigit(*cnb))
			cnb++;
	}
	if (is_real && *cnb != '+' && *cnb != '-')
		return (false);
	if (is_real)
		return (check_format(cnb, false));
	return (*cnb == 'i');
}

t_cnb	ft_atoc(char *cnb)
{
	t_cnb	res;

	if (!check_format(cnb, true))
		return ((t_cnb){.real=0, .imag=0});
	res.real = ft_atof(cnb);
	if (*cnb == '+' || *cnb == '-')
		cnb++;
	while (ft_isdigit(*cnb))
		cnb++;
	if (*cnb == '.')
	{
		cnb++;
		while (ft_isdigit(*cnb))
			cnb++;
	}
	res.imag = ft_atof(cnb);
	return (res);
}
