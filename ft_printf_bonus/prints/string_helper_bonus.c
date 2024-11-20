/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_helper_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:37:53 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/20 16:44:05 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "prints_bonus.h"

void	string_has_precision(char *str_of_str, t_strfla *info,
			int *str_position, unsigned char flags)
{
	if (flags & padding_precision)
	{
		while (info->precision-- > 0)
			ft_putchar_fd(str_of_str[(*str_position)++], 1);
	}
	else
		ft_putstr_fd(str_of_str, 1);
}
