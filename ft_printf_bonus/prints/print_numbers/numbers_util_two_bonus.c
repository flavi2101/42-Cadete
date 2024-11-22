/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_util_two_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:41:01 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/22 12:42:06 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../prints_bonus.h"
#include "../../libft/libft.h"

void	is_posi_or_neg_general_case(int *padding_space_value,
			unsigned char flags, char *value)
{
	if ((flags & plus) && value[0] != '-')
		(*padding_space_value)--;
	else if (flags & space && value[0] != '-')
		(*padding_space_value)--;
	else if (value[0] == '-')
		(*padding_space_value)--;
}

int	print_nothing(int width, char *str_of_num)
{
	int	len;

	if (str_of_num)
		free(str_of_num);
	len = width;
	while (width-- > 0)
		ft_putchar_fd(' ', 1);
	return (len);
}
