/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:42:53 by flferrei          #+#    #+#             */
/*   Updated: 2024/10/18 13:45:24 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;	
	char	*temp;
	size_t	total_size;

	total_size = nmemb * size;
	if (total_size > 4294967296)
		return (NULL);
	temp = malloc(sizeof(char) * total_size);
	ptr = (void *)temp;
	if (!temp)
		return (NULL);
	while (total_size-- > 0)
		*temp++ = 0;
	return (ptr);
}
