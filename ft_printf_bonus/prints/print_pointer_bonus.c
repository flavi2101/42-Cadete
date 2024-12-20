/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:18:59 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/20 14:33:20 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf_bonus.h"
#include "../libft/libft.h"
#include "prints_bonus.h"
#include "../utils/utils_bonus.h"

static void	recursive_division(unsigned long long adrr, int *counter)
{
	if (adrr >= 16)
		recursive_division(adrr / 16, counter);
	(*counter)++;
	ft_putchar_fd("0123456789abcdef"[adrr % 16], 1);
}

static void	show_str_pointer(unsigned long long arg, unsigned char all_flags,
	int *counter, t_strfla *flag_info)
{
	if (all_flags & minus)
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
	void				*ptr;
	int					counter;
	unsigned char		all_flags;

	ptr = va_arg(args, void *);
	arg = (unsigned long long)ptr;
	if (!arg)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	all_flags = 0x00;
	counter = 2;
	set_flags_values(&all_flags, flag_info, counter);
	invalid_flags_pointer(&all_flags);
	show_str_pointer(arg, all_flags, &counter, flag_info);
	return (counter);
}
