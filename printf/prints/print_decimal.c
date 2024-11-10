/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviohenr <flaviohenr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:24:56 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/09 21:37:16 by flaviohenr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../utils/utils.h"
#include "prints.h"


void	*has_flag(t_strfla *input_flags, int looking_for)
{
	const void	*flags;

	flags = (void *)input_flags->flags;
	return (ft_strchr(flags, looking_for));
}

void	handle_condition(unsigned char *flags, t_strfla *user_flag, int count)
{
	if (user_flag->width > count)
		*flags |= padding_width;
	if (user_flag->precision > count)
		*flags |= padding_precision;
	if ((has_flag(user_flag, (int) '.') || has_flag(user_flag, (int) '-')))
		*flags &= ~zero;
	else if (has_flag(user_flag, (int) '0'))
		*flags |= zero;
	if (has_flag(user_flag, (int) '.'))
		*flags |= dot;
	if (has_flag(user_flag, (int) '#'))
		*flags |= hash;
	if (has_flag(user_flag, (int) '-'))
		*flags |= minus;
	if (has_flag(user_flag, (int) ' '))
		*flags |= space;
	if (has_flag(user_flag, (int) '+'))
	{
		*flags |= plus;
		*flags &= ~space;
	}
}
void	remove_signal_atoi(int value, char *str_of_num)
{
		if (value < 0)
			ft_putstr_fd(str_of_num + 1, 1);
		else
			ft_putstr_fd(str_of_num, 1);
}

void	is_pos_or_neg(int *padding_space_value, unsigned char flags, int value)
{
		if ((flags & plus) && value > 0 && (*padding_space_value)--)
			ft_putchar_fd('+', 1);
		else if (flags & space && value > 0 && (*padding_space_value)--)
			ft_putchar_fd(' ', 1);
		else if (value < 0 && (*padding_space_value)--)
			ft_putchar_fd('-', 1);
}

int	general_case(t_strfla *info, unsigned char flags, int value, int len)
{
	int	padding_space_value;

	if (flags & padding_precision)
		padding_space_value = info->width -  info->precision;  
	else
		padding_space_value = info->width -  len;  
	while (padding_space_value-- > 0)
	{
		ft_putchar_fd(' ', 1);
		if ((flags & plus) && padding_space_value == 1)
			break;
	}
	is_pos_or_neg(&padding_space_value, flags, value);
	while (info->precision-- -len> 0)
		ft_putchar_fd('0', 1);
	return (1);
}
int	show_str(int value, int len, unsigned char flags, t_strfla *info)
{
	char	*str_of_num;
	int		padding_value;

	padding_value = info->width - len;
	str_of_num = ft_itoa(value);
	if (flags & minus)
	{
		is_pos_or_neg(&padding_value, flags, value);
		while (info->precision-- - len > 0 && padding_value--)
			ft_putchar_fd('0', 1);
		remove_signal_atoi(value, str_of_num);
		while (padding_value-- > 0)
			ft_putchar_fd(' ', 1);
	}
	else if (!(flags & minus) && !(flags & dot) && (flags & zero))
	{
		is_pos_or_neg(&padding_value, flags, value);
		while (padding_value-- > 0)
			ft_putchar_fd('0', 1);
		remove_signal_atoi(value, str_of_num);
	}
	else if (general_case(info, flags, value, len))
		remove_signal_atoi(value, str_of_num);
	free(str_of_num);
	return (14821);
}

// return value not implemented yet.
int	print_decimal(t_strfla *flag_info, va_list args)
{
	unsigned char		all_flags;
	int					arg;
	int					count;

	all_flags = 0x00;
	arg = va_arg(args, unsigned int);
	count = count_digits(arg);
	handle_condition(&all_flags, flag_info, count);
	show_str(arg, count, all_flags, flag_info);
	return ((int)all_flags);
}
