/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:18:38 by flferrei          #+#    #+#             */
/*   Updated: 2024/10/16 16:06:34 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	counter;

	counter = 0;
	if (dst_size > 0)
	{
		while (counter < (dst_size - 1) && src[counter])
		{
			dst[counter] = src[counter];
			counter++;
		}
		dst[counter] = '\0';
	}
	return (ft_strlen(src));
}
