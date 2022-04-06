/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 01:00:16 by lhumbert          #+#    #+#             */
/*   Updated: 2021/10/22 00:43:40 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	ft_inset(char c, char const *set)
{
	if (!c)
		return (0);
	while (*set)
	{
		if (*(set++) == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	len;

	if (!(s1 && set))
		return (NULL);
	len = ft_strlen(s1);
	while (ft_inset(*s1, set))
	{
		s1++;
		len--;
	}
	while (len && ft_inset(s1[len - 1], set))
		len--;
	ret = (char *)malloc((len + 1) * sizeof(char));
	if (!ret)
		return (0);
	ret[len] = '\0';
	if (!len)
		return (ret);
	while (len--)
		ret[len] = s1[len];
	return (ret);
}
