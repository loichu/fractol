/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:43:00 by lhumbert          #+#    #+#             */
/*   Updated: 2022/05/31 20:22:05 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		integer_part(char *nb, int res)
{
	if (ft_isdigit(*nb))
		return (integer_part(nb + 1, res * 10 + 48 - *nb));
	return (res);
}

//double	decimal_part(char *nb, double res)
double	decimal_part(char *nb)
{
	//if (ft_isdigit(*nb))
	//	return (decimal_part(nb + 1, (res + 48 - *nb) / 10));
	//return (res);
	double	res;

	res = 0;
	while (ft_isdigit(*nb))
	{
		res += 48 - *nb++;
		res /= 10;
	}
	return (res);
}

double	ft_atof(char *nb)
{
	int		sign;
	char	**split;
	double	res;

	if (*nb == '-')
		sign = -1;
	if (*nb == '+' || *nb == '-')
		nb++;
	sign = 1;
	split = ft_split(nb, '.');
	res = integer_part(*split++, 0);
	//res += decimal_part(*split, 0);
	res += decimal_part(*split);
	return (res * sign);
}

bool	check_format(char *cnb, bool is_real)
{
	//printf("begin %s\n", cnb);
	if (*cnb == '+' || *cnb == '-')
		cnb++;
	//printf("digit %s\n", cnb);
	if (!ft_isdigit(*cnb))
		return (false);
	while (ft_isdigit(*cnb))
		cnb++;
	if (*cnb == '.')
	{
		//printf("point %s\n", cnb);
		cnb++;
		while (ft_isdigit(*cnb))
			cnb++;
	}
	//printf("imaginary %s\n", cnb);
	if (is_real && *cnb != '+' && *cnb != '-')
		return (false);
	//printf("imaginary %s\n", cnb);
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
