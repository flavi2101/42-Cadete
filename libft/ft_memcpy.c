/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:45:34 by flferrei          #+#    #+#             */
/*   Updated: 2024/10/16 16:54:16 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*cpy_dest;

	cpy_dest = dest;
	if ((size_t)dest - (size_t)src)
	{
		while (n-- > 0)
			*(unsigned char *)dest++ = *(unsigned char *)src++;
	}
	return (cpy_dest);
}
