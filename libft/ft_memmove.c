/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:51:59 by flferrei          #+#    #+#             */
/*   Updated: 2024/10/17 20:52:00 by flaviohenr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void	*src, size_t n)
{
	int	counter;

	counter = (int)n;
	if (dest == (NULL) || src == (NULL) || n == 0)
		return (dest);
	if (dest > src)
	{
		while ( --counter >= 0)
			((unsigned char *)dest)[counter] = ((unsigned char *)src)[counter];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
