/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:26:03 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/10 14:44:38 by flaviohenr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"
#include "prints.h"
int	print_string(t_strfla *flag_info, va_list args)
{
	unsigned char	all_flags;
	void	*arg;
	int	count;
	char	*value;

	all_flags = 0x00;
	value = va_arg(args, char *);
	count = ft_strlen(value);
	arg = value;
	set_flags_values(&all_flags, flag_info, count);
	all_flags &= ~plus;
	all_flags &= ~space;
	all_flags &= ~zero;
	all_flags &= ~hash;
	if (flag_info->precision < count && flag_info->precision > 0)
		all_flags |= padding_precision;
	else 
		all_flags &= ~padding_precision;
	show_str(arg, TYPE_CHAR_PTR, all_flags, flag_info);
	return (14785);
}
