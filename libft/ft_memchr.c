/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:30:56 by flferrei          #+#    #+#             */
/*   Updated: 2024/10/16 18:37:36 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*memchr(const void *s, int c, size_t n)
{
	size_t	counter;

	counter = 0;

	while (counter < n)
	{
		if ((unsigned char)c == *(unsigned char *)s)
			return ((void *)s);
		s++;
		counter++;
	}
	return (NULL);
}
