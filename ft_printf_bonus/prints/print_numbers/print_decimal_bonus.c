/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviohenr <flaviohenr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:24:56 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/20 14:36:27 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../ft_printf_bonus.h"
#include "../../utils/utils_bonus.h"
#include "../../libft/libft.h"
#include "../prints_bonus.h"
#include "numbers_bonus.h"
// if the flag +,space or is the value negative the witdh and precision 
// can be overwrite it. 
// if arg < 0 the precision always increment the size,
// but the width will depend 

static char	*get_len(int value, int *len)
{
	char	*str;

	str = NULL;
	str = ft_itoa(value);
	*len = count_digits(value);
	return (str);
}

static void	size_calc(unsigned char all_flags, t_strfla *flag_info,
			int *size, int arg)
{
	int	orig_size;

	orig_size = *size;
	if (all_flags & padding_width || all_flags & padding_precision)
	{
		if (flag_info->precision > orig_size)
			*size = flag_info->precision;
		if (arg > 0 && ((all_flags & plus) || (all_flags & space)))
			(*size)++;
		else if (arg < 0)
			(*size)++;
		if (flag_info->width > *size)
			*size = flag_info->width;
	}
	else
	{
		if (arg < 0 || (all_flags & plus) || (all_flags & space))
			(*size)++;
	}
}

int	print_decimal(t_strfla *flag_info, va_list args)
{
	unsigned char	all_flags;
	char			*str_of_num;
	int				count;
	int				value;
	int				len;

	all_flags = 0x00;
	count = 0;
	value = va_arg(args, int);
	set_flags_values(&all_flags, flag_info, count);
	all_flags &= ~hash;
	str_of_num = get_len(value, &count);
	len = count;
	size_calc(all_flags, flag_info, &count, value);
	if (str_of_num)
	{
		show_str_number(str_of_num, all_flags, flag_info, len);
		free(str_of_num);
	}
	else
		return (0);
	return (count);
}
