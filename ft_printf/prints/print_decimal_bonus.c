/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviohenr <flaviohenr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:24:56 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/15 19:23:12 by flaviohenr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "prints_bonus.h"
#include "../utils/utils_bonus.h"

// if the flag +,space or is the value negative the witdh and precision 
// can be overwrite it. 
// if arg < 0 the precision always increment the size, but the width will depend 

static void size_calc(unsigned char all_flags, t_strfla *flag_info, int *size, int arg)
{
    int orig_size = *size;

    if (all_flags & padding_width || all_flags & padding_precision)
    {
        if (flag_info->precision > orig_size)
            *size = flag_info->precision;
            
        if (arg < 0 || (all_flags & plus) || (all_flags & space))
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
        unsigned char   all_flags;
        void    *arg;
        int     count;
        int    value;

        all_flags = 0x00;
        value = va_arg(args, int);
	if (value == 0)
		count = 1;
	else
		count = count_digits(value);
        arg = &value;
        set_flags_values(&all_flags, flag_info, count);
	all_flags &= ~hash;
	size_calc(all_flags, flag_info, &count, value);
	show_str(arg, TYPE_INT, all_flags, flag_info);
	return (count);
}
