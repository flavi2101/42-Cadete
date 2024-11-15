/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:42:53 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/06 23:31:26 by flaviohenr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;	

	if (nmemb > (4294967295 / size))
		return (NULL);
	ptr = malloc((nmemb * size));
	if (!ptr)
		return (NULL);
	return (ft_memset(ptr, 0, (nmemb * size)));
}
