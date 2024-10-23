/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:45:29 by flferrei          #+#    #+#             */
/*   Updated: 2024/10/23 04:05:19 by flaviohenr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		size;
	size_t		counter;

	counter = 0;
	size = ft_strlen(s);
	while (counter < size)
	{
		if (s[counter] == (char)c)
			return ((char *)(s + counter));
		++counter;
	}
	return (NULL);
}
