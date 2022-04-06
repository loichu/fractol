/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:08:10 by lhumbert          #+#    #+#             */
/*   Updated: 2021/10/22 02:12:23 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char	*bsrc;
	char	*bdst;

	bsrc = (char *)src;
	bdst = (char *)dst;
	while (n-- > 0)
	{
		if (bdst || bsrc)
			*(bdst++) = *(bsrc++);
	}
	return (dst);
}
