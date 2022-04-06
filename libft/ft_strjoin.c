/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 00:49:54 by lhumbert          #+#    #+#             */
/*   Updated: 2021/10/22 00:41:59 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	char	*ret;

	if (!(s1 && s2))
		return (NULL);
	l1 = ft_strlen((char *)s1);
	l2 = ft_strlen((char *)s2);
	ret = (char *)malloc((l1 + l2 + 1) * sizeof(char));
	if (!ret)
		return (0);
	while (*s1)
		*(ret++) = *(s1++);
	while (*s2)
		*(ret++) = *(s2++);
	*ret = '\0';
	return (ret - l1 - l2);
}
