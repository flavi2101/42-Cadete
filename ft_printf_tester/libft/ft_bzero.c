/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:25:34 by flferrei          #+#    #+#             */
/*   Updated: 2024/10/16 16:26:03 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*str_byte;

	str_byte = (unsigned char *)str;
	while (n-- > 0)
		*str_byte++ = '\0';
}
