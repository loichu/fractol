/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:26:17 by lhumbert          #+#    #+#             */
/*   Updated: 2021/10/22 00:39:31 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_empty(void)
{
	char	*ret;

	ret = (char *)malloc(1 * sizeof(char));
	if (!ret)
		return (0);
	*ret = '\0';
	return (ret);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	rlen;
	char	*ret;
	size_t	i;

	if (!s)
		return (NULL);
	slen = ft_strlen((char *)s);
	if (start >= slen)
		return (ft_empty());
	rlen = len;
	if (start + len > slen)
		rlen = slen - start;
	ret = (char *)malloc((rlen + 1) * sizeof(char));
	if (!ret)
		return (0);
	i = -1;
	while (++i < rlen)
		ret[i] = s[start + i];
	ret[i] = '\0';
	return (ret);
}
