/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:17:30 by flferrei          #+#    #+#             */
/*   Updated: 2024/10/18 18:43:22 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*dst;
	size_t		total_len;
	size_t		len1;
	size_t		len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	total_len = len1 + len2 + 1;
	dst = (void *)malloc(sizeof(char) * total_len);
	if (!dst)
		return (NULL);
	ft_memmove(dst, s1, len1);
	ft_memmove((dst + len1), s2, len2);
	dst[total_len -1] = '\0';
	return ((char *)dst);
}
