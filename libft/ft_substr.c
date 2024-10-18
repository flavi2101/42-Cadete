/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:50:09 by flferrei          #+#    #+#             */
/*   Updated: 2024/10/18 18:33:30 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dst;
	size_t			size;
	size_t			counter;

	counter = 0;
	size = ft_strlen(s);
	if (start >= size)
		return (ft_strdup(""));
	if (len > size - start)
		len = size - start;
	dst = (char *)malloc(sizeof(char) * len + 1);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s + start, len + 1);
	return (dst);
}
