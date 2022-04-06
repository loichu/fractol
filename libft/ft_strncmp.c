/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 03:02:12 by lhumbert          #+#    #+#             */
/*   Updated: 2021/10/22 01:46:04 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n && !*s1)
		return (0 - *s2);
	while (n--)
	{
		if (*s1 != *s2)
			return ((unsigned char)*(s1) - (unsigned char)*(s2));
		if (!*s1 && *s2)
			return ((unsigned char)(0 - *s2));
		if (*s1)
			s1++;
		if (*s2)
			s2++;
	}
	return (0);
}
