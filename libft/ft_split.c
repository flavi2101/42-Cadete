/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:54:39 by flferrei          #+#    #+#             */
/*   Updated: 2024/10/23 03:34:09 by flaviohenr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	count_word(char *s, char c)
{
	int	temp;

	temp = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
			++temp;
		while (*s != c && *s)
			s++;
	}
	return (temp);
}

int	cleaner(char **ptr, int temp)
{
	while (temp >= 0)
	{
		free(ptr[temp--]);
	}
	free(ptr);
	return (1);
}

char	**transfer(char *s, int splits, char c, char **ptr)
{
	char	*word_end;
	int		counter;

	counter = 0;
	while (*s && splits-- > 0)
	{
		while (*s == c && *s)
			s++;
		word_end = ft_strchr((char *)s, c);
		if (word_end)
		{
			ptr[counter] = ft_substr((char *)s, 0, (word_end - s));
			s = word_end;
		}
		else
		{
			ptr[counter] = ft_strdup((char *)s);
			s += ft_strlen(s);
		}
		if (!ptr[counter] && cleaner(ptr, splits))
			return (NULL);
		counter++;
	}
	ptr[counter] = (NULL);
	return (ptr);
}

char	**ft_split(char const	*s, char c)
{
	char	**ptr;
	int		splits;

	splits = count_word((char *)s, c);
	ptr = (char **)malloc(sizeof(char *) * (splits + 1));
	if (!ptr)
		return (NULL);
	return (transfer((char *)s, splits, c, ptr));
}
