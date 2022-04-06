/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:07:09 by lhumbert          #+#    #+#             */
/*   Updated: 2021/10/22 02:10:38 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;

	str = (char *) b;
	while (len-- > 0)
		*(str++) = (unsigned char) c;
	return (b);
}
