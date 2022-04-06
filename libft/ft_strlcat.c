/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:59:38 by lhumbert          #+#    #+#             */
/*   Updated: 2021/10/25 19:22:15 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	src_len;
	unsigned int	rem;
	unsigned int	i;

	i = ft_strlen(dst);
	src_len = ft_strlen(src);
	rem = src_len;
	if (dstsize <= i)
		rem += dstsize;
	else
		rem += i;
	dst += i;
	while (*src && ++i < dstsize)
		*(dst++) = *(src++);
	*dst = '\0';
	return (rem);
}
