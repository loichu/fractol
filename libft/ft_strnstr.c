/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 02:08:52 by lhumbert          #+#    #+#             */
/*   Updated: 2021/10/22 02:04:26 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*ret;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (*haystack && len--)
	{
		if (*haystack == needle[i])
		{
			if (i == 0)
				ret = (char *)haystack;
			i++;
		}
		else
		{
			len = len + i;
			haystack -= i;
			i = 0;
		}
		if (needle[i] == '\0')
			return (ret);
		haystack++;
	}
	return (0);
}
