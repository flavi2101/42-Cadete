/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:07:13 by flferrei          #+#    #+#             */
/*   Updated: 2024/10/24 17:11:41 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			temp;

	temp = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (temp < n)
	{
		if (str1[temp] != str2[temp])
			return (str1[temp] - str2[temp]);
		++temp;
	}
	return (0);
}
