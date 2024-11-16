/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviohenr <flaviohenr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:23:38 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/15 19:22:58 by flaviohenr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "prints_bonus.h"

void	invalid_flag_char(unsigned char *all_flags)
{
	*all_flags &= ~plus;
	*all_flags &= ~space;
	*all_flags &= ~dot;
	*all_flags &= ~zero;
	*all_flags &= ~hash;
	*all_flags &= ~padding_precision;
}
int	print_char(t_strfla *flag_info, va_list args)
{

	unsigned char	all_flags;
	void	*arg;
	int	count;
	int	temp_arg;

	all_flags = 0x00;
	count = 1;
	temp_arg = va_arg(args, int);
	arg = &temp_arg;
	set_flags_values(&all_flags, flag_info, count);
	invalid_flag_char(&all_flags);
	if (all_flags & padding_width)
		count = flag_info->width;
	show_str(arg, TYPE_CHAR, all_flags, flag_info);
	return (count);
}
