/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:15:23 by flferrei          #+#    #+#             */
/*   Updated: 2024/10/15 15:54:03 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h" 

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	counter;

	counter = 0;
	if (n == 0)
		return (0);
	while ((counter < n) && *s1 == *s2)
	{
		if (*s2 == '\0')
			return (0);
		++counter;
		++s1;
		++s2;
	}
	if (counter > 0)
		return (0);
	return ((unsigned char)s1[counter] - (unsigned char)s2[counter]);
}
