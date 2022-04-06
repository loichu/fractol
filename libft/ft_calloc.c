/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:48:13 by lhumbert          #+#    #+#             */
/*   Updated: 2021/10/22 02:13:34 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ret;

	ret = (char *)malloc(count * size);
	if (!ret)
		return (0);
	ft_bzero(ret, size * count);
	return (ret);
}
