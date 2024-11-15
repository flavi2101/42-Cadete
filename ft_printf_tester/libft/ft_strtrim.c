/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:12:28 by flferrei          #+#    #+#             */
/*   Updated: 2024/10/24 17:03:39 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;

	if (!set || !s1)
		return (NULL);
	if (!(*set))
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]) && start <= end)
		++start;
	if (start > end)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[end]) && end >= 0)
		--end;
	str = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + start, (end - start + 2));
	return (str);
}
