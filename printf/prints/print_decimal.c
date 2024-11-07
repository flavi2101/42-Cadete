/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:24:56 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/07 19:11:25 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"
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
		*flags |= padding_space;
	if (user_flag->precision > count)
		*flags |= zero;
	if ((has_flag(user_flag, (int) '.') || has_flag(user_flag, (int) '-')))
		*flags &= ~padding_zero;
	else if (has_flag(user_flag, (int) '0'))
		*flags |= padding_zero;
	if (has_flag(user_flag, (int) '.'))
		*flags |= dot;
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

int	show_str(int value, int len, unsigned char flags, t_strfla *info)
{
	char	*str_of_num;
	int		padding_space;

	padding_space = info->width - len;
	str_of_num = ft_itoa(value);
	if (flags & minus)
	{
		if (flags & plus && value > 0 && padding_space--)
			ft_putchar_fd('+', 1);
		else if (flags & space && value > 0 && padding_space--)
			ft_putchar_fd(' ', 1);
		else if (value < 0 && padding_space--)
			ft_putchar_fd('-', 1);
		while (info->precision-- - len > 0 && padding_space--)
			ft_putchar_fd('0', 1);
		if (value < 0)
			ft_putstr_fd(str_of_num + 1, 1);
		else
			ft_putstr_fd(str_of_num, 1);
		while (padding_space-- > 0)
			ft_putchar_fd(' ', 1);
	}
	free(str_of_num);
	return (14821);
}

int	print_decimal(t_strfla *flag_info, va_list args)
{
	unsigned char		all_flags;
	int					arg;
	int					count;

	all_flags = 0x00;
	arg = va_arg(args, int);
	count = count_digits(arg);
	handle_condition(&all_flags, flag_info, count);
	if (count >= flag_info->width && count >= flag_info->precision)
		// need to be implemented
		count = 14820;
	else
		show_str(arg, count, all_flags, flag_info);
	return ((int)all_flags);
}
