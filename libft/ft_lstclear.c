/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:59:18 by lhumbert          #+#    #+#             */
/*   Updated: 2021/10/25 20:59:22 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_rclear(t_list *lst, void (*del)(void*))
{
	if (lst->next)
		ft_rclear(lst->next, del);
	del(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (!lst || !*lst || !del)
		return ;
	ft_rclear(*lst, del);
	*lst = NULL;
}
