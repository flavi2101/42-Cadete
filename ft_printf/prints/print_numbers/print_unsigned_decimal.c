/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_decimal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviohenr <flaviohenr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:24:56 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/18 21:03:12 by flaviohenr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../prints.h"
#include "../../utils/utils.h"
#include "../../libft/libft.h"
#include "numbers.h"
// if the flag space is present the witdh and precision 
// can be overwrite it. 
 
static char	*get_len(unsigned int value, int *len, char conversion)
{
	char	*str;
	
	str = NULL;
	*len = count_udigits(value, 10);	
	str = ft_uitoa(value, *len, 10, conversion);	
       	return (str);
}


static void size_calc_un(unsigned char all_flags, t_strfla *flag_info, int *size)
{
    int orig_size = *size;

    if (all_flags & padding_width || all_flags & padding_precision)
    {
        if (flag_info->precision > orig_size)
            *size = flag_info->precision;
            
        if (all_flags & space)
            (*size)++;
            
        if (flag_info->width != 0 && flag_info->width > *size)
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
        int     count;
	char	*str_of_num;
        unsigned int    value;
	int	len;	

        all_flags = 0x00;
	count = 0;
        value = va_arg(args, unsigned int);
        set_flags_values(&all_flags, flag_info, count);
	invalid_flag_uns_dec(&all_flags);
	str_of_num = get_len(value, &count, flag_info->conversion);
	len = count;
	size_calc_un(all_flags, flag_info, &count);
	if(str_of_num)
	{
		show_str_number(str_of_num, all_flags, flag_info, len);
		free(str_of_num);
	}
	else
		return (0);
	return (count);
}
