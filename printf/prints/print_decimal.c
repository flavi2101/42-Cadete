/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviohenr <flaviohenr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:24:56 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/12 20:26:23 by flaviohenr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "prints.h"
#include "../utils/utils.h"

int	print_decimal(t_strfla *flag_info, va_list args)
{
        unsigned char   all_flags;
        void    *arg;
        int     count;
        int    value;

        all_flags = 0x00;
        value = va_arg(args, int);
        count = count_digits(value);
        arg = &value;
        set_flags_values(&all_flags, flag_info, count);
	all_flags &= ~hash;
	show_str(arg, TYPE_INT, all_flags, flag_info);
	return (14869);
}
