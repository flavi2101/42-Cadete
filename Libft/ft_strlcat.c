/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:11:46 by flferrei          #+#    #+#             */
/*   Updated: 2024/10/15 18:52:47 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	size_t	counter;
	size_t	dst_avaliable;
	size_t	src_size;

	src_size = ft_strlen(src);
	counter = ft_strlen(dst);
	dst_avaliable = dst_size - counter - 1;
	if (src_size < dst_size)
		return (counter + src_size);	
	if (dst_size > 0)
	{
		while (counter < (dst_avaliable) && *src)
		{
			dst[counter] = *src;
			++counter;
			++src;
		}
		dst[counter] = '\0';
	}
	return (src_size + ft_strlen(dst));
}
