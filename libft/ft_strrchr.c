/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 00:11:31 by lhumbert          #+#    #+#             */
/*   Updated: 2021/10/22 02:08:09 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	char	found;

	found = 0;
	while (*s)
	{
		if (*s == (char)c)
		{
			found = 1;
			last = (char *)s;
		}
		s++;
	}
	if (*s == '\0' && (char)c == '\0')
		return ((char *)s);
	if (!found)
		return (0);
	return (last);
}
