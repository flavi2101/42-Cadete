/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:15:23 by flferrei          #+#    #+#             */
/*   Updated: 2024/10/15 17:02:09 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	counter;

	counter = 0;
	while ((counter < n) && s1[counter] && s2[counter])
	{
		if (s2[counter] != s1[counter])
			return ((unsigned char)s1[counter] - (unsigned char)s2[counter]);
		++counter;
	}
	if (counter != n)
		return ((unsigned char)s1[counter] - (unsigned char)s2[counter]);
	return (0);
}
