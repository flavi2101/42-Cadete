/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:09:34 by flferrei          #+#    #+#             */
/*   Updated: 2024/10/16 10:20:55 by flaviohenr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	source_size;
	char	*dst;
	size_t		counter;

	counter = 0;
	source_size = ft_strlen(s); 
	dst = (char *)malloc(sizeof(char) * (source_size + 1));
	if (!dst)
		return (NULL);
	while (counter < source_size)
		dst[counter++] = *s++;
	dst[counter] = '\0';
	return (dst);
}
