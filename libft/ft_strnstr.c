/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:22:14 by flferrei          #+#    #+#             */
/*   Updated: 2024/10/15 17:14:42 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	big_iterator;
	size_t	little_size;

	little_size = ft_strlen(little);
	if (!little_size)
		return ((char *)big);
	big_iterator = 0;
	while (big[big_iterator] && big_iterator < len)
	{
		if ((big_iterator + little_size <= len)
			&& !(ft_strncmp((&big[big_iterator]), little, little_size)))
			return ((char *)(&big[big_iterator]));
		big_iterator++;
	}
	return (NULL);
}
