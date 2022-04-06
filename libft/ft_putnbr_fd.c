/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 03:04:05 by lhumbert          #+#    #+#             */
/*   Updated: 2021/10/22 03:37:56 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"

void	ft_minint(int fd)
{
	write(fd, "-2147483648", 11);
	return ;
}

void	ft_print(int n, int fd)
{
	char	dgt;

	dgt = 48 + n;
	write(fd, &dgt, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		mult;
	int		tmp;
	char	start;

	if (n == -2147483648)
		return (ft_minint(fd));
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	mult = 1000000000;
	start = 0;
	while (mult > 1)
	{
		tmp = n / mult;
		if (tmp)
			start = 1;
		if (start)
			ft_print(tmp, fd);
		n -= tmp * mult;
		mult /= 10;
	}
	ft_print(n, fd);
}
