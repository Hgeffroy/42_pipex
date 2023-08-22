/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:57:45 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/05/26 11:11:52 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmpb;

	if (!lst)
		return ;
	if (!*lst || !del)
	{
		lst = NULL;
		return ;
	}
	while (*lst)
	{
		tmpb = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(tmpb, del);
	}
	lst = NULL;
}
