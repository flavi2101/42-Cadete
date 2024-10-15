/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:18:38 by flferrei          #+#    #+#             */
/*   Updated: 2024/10/15 13:20:19 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	src_size;
	size_t	counter;

	src_size = ft_strlen(src);
	counter = 0;
	if (dst_size > 0)
	{
		while (counter++ < (dst_size - 1) && *src)
			*dst++ = *src++;
		dst[counter] = '\0';
	}
	return (src_size);
}
