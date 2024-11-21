/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:38:44 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/21 16:53:02 by flaviohenr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../prints_bonus.h"
#include "../../utils/utils_bonus.h"
#include "numbers_bonus.h"

static char	*get_len(unsigned int value, int *len, char conversion)
{
	char	*str;

	str = NULL;
	*len = count_udigits(value, 16);
	str = ft_uitoa(value, *len, 16, conversion);
	return (str);
}

static void	size_calc_un_hex(unsigned char all_flags,
			t_strfla *flag_info, int *size)
{
	if (all_flags & padding_width || all_flags & padding_precision)
	{
		if (flag_info->precision > *size)
			*size = flag_info->precision;
		if (flag_info->width > *size)
			*size = flag_info->width;
	}
}

static void	hex_notation(t_strfla *flag_info, char unsigned all_flags)
{
	if (flag_info->conversion == 'x')
		ft_putstr_fd("0x", 1);
	else
		ft_putstr_fd("0X", 1);
	if (all_flags & padding_precision)
		flag_info->precision -= 2;
	if (all_flags & padding_width)
		flag_info->width -= 2;
}

static void	invalid_flags_hex(unsigned char *all_flags,
			unsigned int value, t_strfla *flag_info, int *count)
{
	*all_flags &= ~space;
	*all_flags &= ~plus;
	if (value > 0 && *all_flags & minus && *all_flags & hash)
	{
		(*count += 2);
		hex_notation(flag_info, *all_flags);
	}
	else if (value > 0 && (*all_flags & zero) && *all_flags & hash)
	{
		(*count += 2);
		hex_notation(flag_info, *all_flags);
	}
	else if (value > 0 && *all_flags & hash)
		*count += 2;
}

int	print_hex(t_strfla *flag_info, va_list args)
{
	unsigned char		all_flags;
	unsigned int		value;
	char				*str_of_num;
	int					count;

	all_flags = 0x00;
	count = 0;
	value = va_arg(args, unsigned int);
	str_of_num = get_len(value, &count, flag_info->conversion);
	set_flags_values(&all_flags, flag_info, count);
	invalid_flags_hex(&all_flags, value, flag_info, &count);
	if (all_flags & dot && flag_info->precision == 0)
		return (print_nothing(flag_info->width, str_of_num));
	size_calc_un_hex(all_flags, flag_info, &count);
	if (str_of_num)
	{
		show_str_number(str_of_num, all_flags,
			flag_info, count_udigits(value, 16));
		free(str_of_num);
	}
	else
		return (0);
	return (count);
}
