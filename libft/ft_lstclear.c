/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:31:32 by flferrei          #+#    #+#             */
/*   Updated: 2024/10/23 12:39:59 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ref;

	while ((*lst) != NULL)
	{
		ref = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = ref;
	}
	*lst = (NULL);
}
