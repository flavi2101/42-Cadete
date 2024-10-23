/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:43:13 by flferrei          #+#    #+#             */
/*   Updated: 2024/10/23 12:43:39 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	*temp;

	if (!(lst->next))
	{
		(*del)(lst->content);
		free(lst);
	}
	else
	{
		temp = lst->next;
		(*del)(lst->content);
		free(lst);
	}
}
