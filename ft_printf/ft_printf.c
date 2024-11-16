/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviohenr <flaviohenr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:23:10 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/16 10:47:48 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"
#include "./prints/prints.h"
#include <limits.h>
#include <assert.h>
#include <stdio.h>
static void	set_func_conversion(t_strfla *flag_info)
{
	if (flag_info->conversion == 'c')
		flag_info->fuc = print_char;
	else if (flag_info->conversion == 's')
		flag_info->fuc = print_string;
	else if (flag_info->conversion == 'd')
		flag_info->fuc = print_decimal;
	else if (flag_info->conversion == 'i')	
		flag_info->fuc = print_decimal;
	else if (flag_info->conversion == 'u')	
		flag_info->fuc = print_unsigned_decimal;
	else if (flag_info->conversion == 'x')	
		flag_info->fuc = print_hex;
	else if (flag_info->conversion == 'X')	
		flag_info->fuc = print_hex;
}

// necessary split the p because the unsed variable
// t_strfla in the protytype of the fun inside flag_info
static int	print_args(va_list args, t_strfla *flag_info)
{
	if (flag_info->conversion != 'p')
	{
		set_func_conversion(flag_info);
		return (flag_info->fuc(flag_info, args));
	}
	return (print_pointer(args));
}
/*
check if i have two consecutives percentagem in the string
doing here to avoid the cration of struct and memory allocaiton.
*/ 
static int	check_percentage(const char *str, int *position)
{
	if (str[*position] && str[*position + 1] == '%' && ++(*position))
	{
		ft_putchar_fd(str[(*position)++], 1);
		return (1);
	}
	return (0);
}
/*
flags_len increse two for each iteration because
of the % and the conversion (csdixp)

flags_info modify str_flags_len until the
conversion,this is the reason of the last if 
 */
int	ft_printf(const char *str, ...)
{
	t_strfla	*flags_info;
	va_list		args;
	int			args_len;
	int			str_flags_len;
	int			flags_len;

	str_flags_len = 0;
	args_len = 0;
	flags_len = 0;
	va_start(args, str);
	while (str[str_flags_len])
	{
		while (str[str_flags_len] && str[str_flags_len] != '%')
			ft_putchar_fd(str[str_flags_len++], 1);
		if (check_percentage(str, &str_flags_len) && ++flags_len)
			continue ;
		if (!str[str_flags_len])
			break;
		flags_info = get_flags_info(str + str_flags_len + 1, &str_flags_len);
		args_len += print_args(args, flags_info);
		flags_len += flags_info->total_len + 2;	
		if (str[str_flags_len] != '\0')
			++str_flags_len;
		free_flags(flags_info);
	}
	return (str_flags_len - flags_len + args_len);
}

int	main(void)
{

}
