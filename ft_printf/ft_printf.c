/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviohenr <flaviohenr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:23:10 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/19 13:47:53 by flaviohenr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "prints/prints.h"
#include <assert.h>
#include <stdio.h>
#include <limits.h>
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
	else if (flag_info->conversion == 'p')
		flag_info->fuc = print_pointer;
	else if (flag_info->conversion == 'u')	
		flag_info->fuc = print_unsigned_decimal;
	else if (flag_info->conversion == 'x')	
		flag_info->fuc = print_hex;
	else if (flag_info->conversion == 'X')	
		flag_info->fuc = print_hex;
}

static int	print_args(va_list args, t_strfla *flag_info)
{
		set_func_conversion(flag_info);
		return (flag_info->fuc(flag_info, args));
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
/*
int val1 = ft_printf("|%.2u|\n", 1);
int val2 = printf("|%.2u|\n", 1);
printf("my - %d ori - %d\n", val1, val2);

val1 = ft_printf("|%.3u|\n", 11);
val2 = printf("|%.3u|\n", 11);
printf("my - %d ori - %d\n", val1, val2);

val1 = ft_printf("|%.4u|\n", 15);
val2 = printf("|%.4u|\n", 15);
printf("my - %d ori - %d\n", val1, val2);

val1 = ft_printf("|%.5u|\n", 16);
val2 = printf("|%.5u|\n", 16);
printf("my - %d ori - %d\n", val1, val2);

val1 = ft_printf("|%.6u|\n", 17);
val2 = printf("|%.6u|\n", 17);
printf("my - %d ori - %d\n", val1, val2);

val1 = ft_printf("|%.12u|\n", UINT_MAX);
val2 = printf("|%.12u|\n", UINT_MAX);
printf("my - %d ori - %d\n", val1, val2);

val1 = ft_printf("|%.2u|\n",1);
val2 = printf("|%.2u|\n",1);
	printf("my - %d ori - %d\n", val1, val2);
val1 = ft_printf("|%.2u|\n",15);
val2 = printf("|%.2u|\n",15);
	printf("my - %d ori - %d", val1, val2);
	*/
	int a = printf("|%.2u|\n", 1);
	int b = ft_printf("|%.2u|\n",1);
	printf("%d %d\n", a, b);
	printf("-----------------");
}
