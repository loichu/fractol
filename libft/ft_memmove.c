/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:30:41 by lhumbert          #+#    #+#             */
/*   Updated: 2021/10/22 02:11:19 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*bsrc;
	unsigned char	*bdst;
	size_t			i;

	if (!(dst || src))
		return (dst);
	bsrc = (unsigned char *)src;
	bdst = (unsigned char *)dst;
	if (src < dst)
	{
		while (len-- > 0)
			bdst[len] = bsrc[len];
	}
	else
	{
		i = -1;
		while (++i < len)
			bdst[i] = bsrc[i];
	}
	return (dst);
}
