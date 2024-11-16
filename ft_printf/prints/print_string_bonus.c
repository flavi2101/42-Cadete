/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:26:03 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/15 19:23:50 by flaviohenr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"
#include "prints_bonus.h"

static void size_calc_str(unsigned char all_flags, t_strfla *flag_info, int *size)
{
    int orig_size = *size;

    if (all_flags & padding_width || all_flags & padding_precision)
    {
        if (flag_info->precision < orig_size)
            *size = flag_info->precision;
            
        if (flag_info->width > *size)
            *size = flag_info->width;
    }
}
static void	invalid_flags_str(t_strfla *flag_info, unsigned char *all_flags, int count)
{
	*all_flags &= ~plus;
	*all_flags &= ~space;
	*all_flags &= ~zero;
	*all_flags &= ~hash;
	if (flag_info->precision < count && flag_info->precision > 0)
		*all_flags |= padding_precision;
	else 
		*all_flags &= ~padding_precision;
}

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
	invalid_flags_str(flag_info, &all_flags, count);
	size_calc_str(all_flags, flag_info, &count);
	show_str(arg, TYPE_CHAR_PTR, all_flags, flag_info);
	return (count);
}
