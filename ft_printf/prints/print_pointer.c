/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:18:59 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/19 13:12:08 by flaviohenr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"
#include "../libft/libft.h"
#include "prints.h"
#include "../utils/utils.h"

static void	recursive_division(unsigned long long adrr, int *digits)
{
	if (adrr >= 16)
		recursive_division(adrr / 16, digits);
	(*digits)++;
	ft_putchar_fd("0123456789abcdef"[adrr % 16], 1);
}

static void	show_str_pointer(unsigned long long arg, unsigned char all_flags, int *counter, t_strfla *flag_info)
{
	if(all_flags & minus)
	{
		ft_putstr_fd("0x", 1);
		recursive_division(arg, counter);
		while (flag_info->width-- > *counter)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (flag_info->width-- > *counter)
			ft_putchar_fd(' ', 1);
		ft_putstr_fd("0x", 1);
		recursive_division(arg, counter);
	}
}

void	invalid_flags_pointer(unsigned char *all_flags)
{
	*all_flags &= ~plus;	
	*all_flags &= ~zero;
	*all_flags &= ~padding_precision;
	*all_flags &= ~hash;
	*all_flags &= ~space;
}
int	print_pointer(t_strfla *flag_info, va_list args)
{
	unsigned long long	arg;
	int					counter;
	unsigned char		all_flags;

	arg = va_arg(args, unsigned long long );
	if (!arg)
	{
		ft_putstr_fd("(nil)",1);
		return (5);
	}
	all_flags = 0x00;
	counter = 2;
	set_flags_values(&all_flags, flag_info, counter);
	invalid_flags_pointer(&all_flags);
	show_str_pointer(arg, all_flags, &counter, flag_info);
	return (counter);
}
