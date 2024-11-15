/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:07:06 by flferrei          #+#    #+#             */
/*   Updated: 2024/10/24 13:33:26 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char		*byte_str;
	size_t				counter;

	byte_str = (unsigned char *)str;
	counter = 0;
	while (n-- > 0)
		byte_str[counter++] = (unsigned char)c;
	return (str);
}
