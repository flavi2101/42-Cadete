/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:18:59 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/15 19:23:36 by flaviohenr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf_bonus.h"
#include "../libft/libft.h"

void	recursive_division(unsigned long long adrr, int *digits)
{
	if (adrr >= 16)
		recursive_division(adrr / 16, digits);
	(*digits)++;
	ft_putchar_fd("0123456789abcdef"[adrr % 16], 1);
}
int	print_pointer(va_list args)
{
	unsigned long long	arg;
	int					counter;

	counter = 2;
	arg = (unsigned long long)va_arg(args, void *);
	if (!arg)
	{
		ft_putstr_fd("(nil)",1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	recursive_division(arg, &counter);
	return (counter);
}
