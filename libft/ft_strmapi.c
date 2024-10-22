/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:38:41 by flferrei          #+#    #+#             */
/*   Updated: 2024/10/22 15:42:11 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	counter;
	char			*ptr;

	counter = 0;
	ptr = (char *)malloc(sizeof(char ) * ft_strlen(s) + 1);
	while (*s)
	{
		ptr[counter] = (*f)(counter, *s);
		++s;
		++counter;
	}
	ptr[counter] = '\0';
	return (ptr);
}
