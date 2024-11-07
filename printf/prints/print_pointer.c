/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:18:59 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/07 17:23:12 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"
#include "../libft/libft.h"

void	recursive_division(unsigned long long adrr, int *digits)
{
	if (adrr >= 16)
		recursive_division(adrr / 16, digits);
	(*digits)++;
	ft_putchar_fd("0123456789abcdef"[adrr % 16], 1);
}
// fix the return if arg is null

int	print_pointer(va_list args)
{
	unsigned long long	arg;
	int					counter;

	counter = 2;
	arg = (unsigned long long)va_arg(args, void *);
	if (!arg)
		return (14820);
	ft_putstr_fd("0x", 1);
	recursive_division(arg, &counter);
	return (counter);
}
