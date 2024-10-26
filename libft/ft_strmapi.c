/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:38:41 by flferrei          #+#    #+#             */
/*   Updated: 2024/10/26 09:45:38 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	counter;
	char			*ptr;

	counter = 0;
	ptr = (char *)malloc(sizeof(char ) * ft_strlen(s) + 1);
	if (!ptr)
		return (NULL);
	while (*s)
	{
		ptr[counter] = (*f)(counter, *s);
		++s;
		++counter;
	}
	ptr[counter] = '\0';
	return (ptr);
}
