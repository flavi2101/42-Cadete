/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_decimal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviohenr <flaviohenr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:24:56 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/15 13:14:54 by flaviohenr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "prints.h"
#include "../utils/utils.h"

// if the flag space is present the witdh and precision 
// can be overwrite it. 


static void size_calc_un(unsigned char all_flags, t_strfla *flag_info, int *size)
{
    int orig_size = *size;

    if (all_flags & padding_width || all_flags & padding_precision)
    {
        if (flag_info->precision > orig_size)
            *size = flag_info->precision;
            
        if (all_flags & space)
            (*size)++;
            
        if (flag_info->width > *size)
            *size = flag_info->width;
    }
    else
    {
        if (all_flags & space)
            (*size)++;
    }
}
static void	invalid_flag_uns_dec(unsigned char *all_flags)
{
	*all_flags &= ~hash;
	*all_flags &= ~plus;
}

int	print_unsigned_decimal(t_strfla *flag_info, va_list args)
{
        unsigned char   all_flags;
        void    *arg;
        int     count;
        unsigned int    value;

        all_flags = 0x00;
        value = va_arg(args, unsigned int);
	if (value == 0)
		count = 1;
	else
		count = count_udigits(value, 10);
        arg = &value;
        set_flags_values(&all_flags, flag_info, count);
	invalid_flag_uns_dec(&all_flags);
	size_calc_un(all_flags, flag_info, &count);
	show_str(arg, TYPE_UNSIGNED_INT, all_flags, flag_info);
	return (count);
}
