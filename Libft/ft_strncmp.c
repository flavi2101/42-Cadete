/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:15:23 by flferrei          #+#    #+#             */
/*   Updated: 2024/10/12 16:58:12 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <assert.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	counter;

	counter = 0;
	if (n == 0)
		return (0);
	while (counter < n && s1[counter] == s2[counter])
	{
		if (s2[counter] == '\0')
			return (0);
		++counter;
	}
	if (counter == n)
		return (1);
	return ((unsigned char)s1[counter] - (unsigned char)s2[counter]);
}
