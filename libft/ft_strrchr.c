/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:48:02 by flferrei          #+#    #+#             */
/*   Updated: 2024/10/23 07:00:27 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		size;
	size_t		counter;
	char		*position;

	counter = 0;
	position = NULL;
	size = ft_strlen(s) + 1;
	while (counter < size)
	{
		if (s[counter] == (char)c)
			position = (char *)s + counter;
		++counter;
	}
	return (position);
}
