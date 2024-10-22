/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:25:22 by flferrei          #+#    #+#             */
/*   Updated: 2024/10/20 13:14:19 by flaviohenr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*count_digis(int user_inp, int *counter)
{
	unsigned int	temp;

	*counter = 0;
	temp = user_inp;
	if (user_inp <= 0)
	{
		(*counter)++;
		if (user_inp == 0)
			return ((char *)malloc(sizeof(char) * 2));
		temp = (user_inp ^ 0xffffffff) + 1;
	}
	while (temp > 0)
	{
		temp = temp / 10;
		(*counter)++;
	}
	return ((char *)malloc(sizeof(char) * (*counter + 1)));
}

char	*ft_itoa(int n)
{
	unsigned int	temp;
	char			*ptr;
	int				counter;

	ptr = count_digis(n, &counter);
	temp = n;
	if (!ptr)
		return (NULL);
	ptr[counter--] = '\0';
	if (n == 0)
	{
		ptr[counter] = '0';
		return (ptr);
	}
	if (n < 0)
	{
		temp = (n ^ 0xffffffff) + 1;
		ptr[0] = '-';
	}
	while (temp > 0)
	{
		ptr[counter--] = "0123456789"[(temp % 10)];
		temp = temp / 10;
	}
	return (ptr);
}
