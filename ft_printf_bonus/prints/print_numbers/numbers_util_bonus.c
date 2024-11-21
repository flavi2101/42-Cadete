/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_util_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:38:04 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/21 16:41:31 by flaviohenr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../prints_bonus.h"
#include "../../libft/libft.h"

static void	remove_signal_atoi(char *str_of_num,
			unsigned char flags, char conversion)
{
	if (str_of_num[0] == '-')
		ft_putstr_fd(str_of_num + 1, 1);
	else if (!(flags & padding_precision)
		&& (flags & hash) && !(flags & minus) && !(flags & zero))
	{
		if (str_of_num[0] != '0')
			zero_x_printer(flags, conversion);
		ft_putstr_fd(str_of_num, 1);
	}
	else
		ft_putstr_fd(str_of_num, 1);
}

static void	is_posi_or_neg(int *padding_space_value,
			unsigned char flags, char *value)
{
	if ((flags & plus) && value[0] != '-')
	{
		(*padding_space_value)--;
		ft_putchar_fd('+', 1);
	}
	else if (flags & space && value[0] != '-')
	{
		(*padding_space_value)--;
		ft_putchar_fd(' ', 1);
	}
	else if (value[0] == '-')
	{
		(*padding_space_value)--;
		ft_putchar_fd('-', 1);
	}
}


static int	general_case(t_strfla *info, unsigned char flags,
			char *value, int len)
{
	int	padding_space_value;

	if (flags & padding_precision)
		padding_space_value = info->width - info->precision;
	else
	{
		padding_space_value = info->width - len;
	}
	is_posi_or_neg_general_case(&padding_space_value, flags, value);
	if (flags & hash)
		padding_space_value -= 2;
	while (padding_space_value-- > 0)
		ft_putchar_fd(' ', 1);
	is_posi_or_neg(&padding_space_value, flags, value);
	if (info->precision - len > 0 && flags & padding_precision)
	{
		zero_x_printer(flags, info->conversion);
		while (info-> precision-- - len > 0)
			ft_putchar_fd('0', 1);
	}
	return (1);
}

void	show_str_number(char *str_of_num, unsigned char flags,
			t_strfla *info, int len)
{
	int		padding_value;

	padding_value = info->width - len;
	if (flags & minus)
	{
		is_posi_or_neg(&padding_value, flags, str_of_num);
		if (info->precision - len > 0 && flags & padding_precision)
		{
			while (info->precision-- - len > 0 && padding_value--)
				ft_putchar_fd('0', 1);
		}
		remove_signal_atoi(str_of_num, flags, info->conversion);
		while (padding_value-- > 0)
			ft_putchar_fd(' ', 1);
	}
	else if (!(flags & minus) && !(flags & dot) && (flags & zero))
	{
		is_posi_or_neg(&padding_value, flags, str_of_num);
		while (padding_value-- > 0)
			ft_putchar_fd('0', 1);
		remove_signal_atoi(str_of_num, flags, info->conversion);
	}
	else if (general_case(info, flags, str_of_num, len))
		remove_signal_atoi(str_of_num, flags, info->conversion);
}

char	*ft_uitoa(unsigned int n, int counter, int base, char conversion)
{
	char			*ptr;

	if (n == 0)
	{
		ptr = (char *)malloc(sizeof(char) * (2));
		ptr[1] = '\0';
		ptr[0] = '0';
		return (ptr);
	}
	ptr = (char *)malloc(sizeof(char) * (counter + 1));
	if (!ptr)
		return (NULL);
	ptr[counter--] = '\0';
	while (n != 0)
	{
		if (conversion == 'x')
			ptr[counter--] = "0123456789abcdef"[(n % base)];
		else if (conversion == 'X')
			ptr[counter--] = "0123456789ABCDEF"[(n % base)];
		else
			ptr[counter--] = "0123456789"[(n % base)];
		n = n / base;
	}
	return (ptr);
}
