/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviohenr <flaviohenr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:23:10 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/13 10:33:05 by flaviohenr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"
#include "./prints/prints.h"
#include <stdio.h>
void	set_func_conversion(t_strfla *flag_info)
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
int	print_args(va_list args, t_strfla *flag_info)
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
int	check_percentage(const char *str, int *position)
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
conversion,this is the reason of the last if and 
the minus 1 below.

In the return minus 1 to exclude de \0;
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
		// i have a problem with this percentage
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
	return (str_flags_len + args_len - flags_len - 1);
}

int	main(void)
{
	unsigned  num1 = 4052;	
	unsigned int  zero2 = 0;
	int  num = 42;	
	char c2 = 'Z';        // Uppercase letter
	ft_printf("bato%%%c%10c",c2, c2);
/*	char *s2 = "Hello my frind";        // Empty string
	char *s1 = "cinco";   // Simple string
	char c1 = 'a';        // Lowercase letter
	char c3 = '@';        // Symbol
	int  zero = 0;
	ft_printf("Printing char\n");
	ft_printf("|%c|\n",c1);
	printf("|%c|\n",c1);
	printf("|%c|\n",c2);
	ft_printf("|%c|\n",c3);
	printf("|%c|\n",c3);
	ft_printf("|%-10c|\n",c1);
	printf("|%-10c|\n",c1);
	ft_printf("|%-10c|\n",c2);
	printf("|%-10c|\n",c2);
	ft_printf("|%-10c|\n",c3);
	printf("|%-10c|\n",c3);
	ft_printf("|%10c|\n",c1);
	printf("|%10c|\n",c1);
	ft_printf("|%10c|\n",c2);
	printf("|%10c|\n",c2);
	ft_printf("|%10c|\n",c3);
	printf("|%10c|\n",c3);
	ft_printf("-----------\n");
	
	ft_printf("Printing string\n");
	ft_printf("|%s|\n",s1);
	printf("|%s|\n",s1);
	ft_printf("|%s|\n",s2);
	printf("|%s|\n",s2);
	ft_printf("|%-2s|\n",s1);
	printf("|%-2s|\n",s1);
	ft_printf("|%-5s|\n",s2);
	printf("|%-5s|\n",s2);
	ft_printf("|%2s|\n",s1);
	printf("|%2s|\n",s1);
	ft_printf("|%5s|\n",s2);
	printf("|%5s|\n",s2);
	ft_printf("|%-8s|\n",s1);
	printf("|%-8s|\n",s1);
	ft_printf("|%-15s|\n",s2);
	printf("|%-15s|\n",s2);
	ft_printf("|%8s|\n",s1);
	printf("|%8s|\n",s1);
	ft_printf("|%15s|\n",s2);
	ft_printf("-----------\n");
	
	ft_printf("|%s|\n",s1);
	printf("|%s|\n",s1);
	ft_printf("|%s|\n",s2);
	printf("|%s|\n",s2);
	ft_printf("|%-.2s|\n",s1);
	printf("|%-.2s|\n",s1);
	ft_printf("|%-.5s|\n",s2);
	printf("|%-.5s|\n",s2);
	ft_printf("|%.2s|\n",s1);
	printf("|%.2s|\n",s1);
	ft_printf("|%.5s|\n",s2);
	printf("|%.5s|\n",s2);
	ft_printf("|%-.8s|\n",s1);
	printf("|%-.8s|\n",s1);
	ft_printf("|%-.15s|\n",s2);
	printf("|%-.15s|\n",s2);
	ft_printf("|%.8s|\n",s1);
	printf("|%.8s|\n",s1);
	ft_printf("|%.15s|\n",s2);
	ft_printf("-----------\n");
	
	ft_printf("|%2s|\n",s1);
	printf("|%2s|\n",s1);
	ft_printf("|%5s|\n",s2);
	printf("|%5s|\n",s2);
	ft_printf("|%-2.2s|\n",s1);
	printf("|%-2.2s|\n",s1);
	ft_printf("|%-5.5s|\n",s2);
	printf("|%-5.5s|\n",s2);
	ft_printf("|%8.2s|\n",s1);
	printf("|%8.2s|\n",s1);
	ft_printf("|%17.5s|\n",s2);
	printf("|%17.5s|\n",s2);
	ft_printf("|%-9.8s|\n",s1);
	printf("|%-9.8s|\n",s1);
	ft_printf("|%-17.15s|\n",s2);
	printf("|%-17.15s|\n",s2);
	ft_printf("|%2.3s|\n",s1);
	printf("|%2.3s|\n",s1);
	ft_printf("|%5.15s|\n",s2);

	ft_printf("-----------\n");
	ft_printf("Basic: |%d|\n", num);
	printf("Basic: |%d|\n", num);
	ft_printf("Negative: |%d|\n", -num);
	printf("Negative: |%d|\n", -num);
	ft_printf("Zero: |%d|\n", zero);
	printf("Zero: |%d|\n", zero);
	ft_printf("Width 5: |%5d|\n", num);
	printf("Width 5: |%5d|\n", num);*/
	ft_printf("Width 5, negative: |%5d| |%8d|\n", -num, num);
	printf("Width 5, negative: |%5d|\n", -num);
	ft_printf("Width 2 for 3 digits: |%2d|\n", 123);
	printf("Width 2 for 3 digits: |%2d|\n", 123);
	ft_printf("Width 5 with zeros: |%05d|\n", num);
	printf("Width 5 with zeros: |%05d|\n", num);
	ft_printf("Width 5 with zeros, negative: |%05d|\n", -num);
	printf("Width 5 with zeros, negative: |%05d|\n", -num);
	ft_printf("Left-justify width 5: |%-5d|\n", num);
	printf("Left-justify width 5: |%-5d|\n", num);
	ft_printf("Left-justify width 5, negative: |%-5d|\n", -num);
	printf("Left-justify width 5, negative: |%-5d|\n", -num);
	ft_printf("Precision 4: |%.4d|\n", num);
	printf("Precision 4: |%.4d|\n", num);
	ft_printf("Precision 4, negative: |%.4d|\n", -num);
	printf("Precision 4, negative: |%.4d|\n", -num);
	ft_printf("Precision 0: |%.0d|\n", num);
	printf("Precision 0: |%.0d|\n", num);
	ft_printf("Precision 0, zero: |%.0d|\n", zero);
	printf("Precision 0, zero: |%.0d|\n", zero);
	ft_printf("Width 8, Precision 4: |%8.4d|\n", num);
	printf("Width 8, Precision 4: |%8.4d|\n", num);
	ft_printf("Width 8, Precision 4, negative: |%8.4d|\n", -num);
	printf("Width 8, Precision 4, negative: |%8.4d|\n", -num);
	ft_printf("Width 2, Precision 4: |%2.4d|\n", num);
	printf("Width 2, Precision 4: |%2.4d|\n", num);
	ft_printf("Plus flag: |%+d|\n", num);
	printf("Plus flag: |%+d|\n", num);
	ft_printf("Plus flag, negative: |%+d|\n", -num);
	printf("Plus flag, negative: |%+d|\n", -num);
	ft_printf("Plus flag, zero: |%+d|\n", num);
	printf("Plus flag, zero: |%+d|\n", num);
	ft_printf("Space flag: |% d|\n", num);
	printf("Space flag: |% d|\n", num);
	ft_printf("Space flag, negative: |% d|\n", -num);
	printf("Space flag, negative: |% d|\n", -num);
	ft_printf("Space flag, zero: |% d|\n", zero);
	printf("Space flag, zero: |% d|\n", zero);
	ft_printf("Everything: |%+8.4d|\n", num);
	printf("Everything: |%+8.4d|\n", num);
	ft_printf("Everything, negative: |%+8.4d|\n", -num);
	printf("Everything, negative: |%+8.4d|\n", -num);
	ft_printf("Left-justify, plus, width, prec: |%-+8.4d|\n", num);
	printf("Left-justify, plus, width, prec: |%-+8.4d|\n", num);
	ft_printf("Space, width, precision: |% 8.4d|\n", num);
	printf("Space, width, precision: |% 8.4d|\n", num);
	ft_printf("Zero, width, no precision: |%08d|\n", num);
	printf("Zero, width, no precision: |%08d|\n", num);
	ft_printf("Max int: |%d|\n", 2147483647);
	printf("Max int: |%d|\n", 2147483647);
	ft_printf("Zero precision with zero: |%.0d|\n",num);
	printf("Zero precision with zero: |%.0d|\n",num);
	ft_printf("Zero width with zero: |%0d|\n", zero);
	printf("Zero width with zero: |%0d|\n", zero);
	ft_printf("Space and plus: |%+ d|\n", num);
	

	ft_printf("-----------\n");
	ft_printf("Basic: |%u|\n", num1);
	printf("Basic: |%u|\n", num1);
	ft_printf("Negative: |%u|\n", -num1);
	printf("Negative: |%u|\n", -num1);
	ft_printf("Zero: |%u|\n", zero2);
	printf("Zero: |%u|\n", zero2);
	ft_printf("Width 5: |%5u|\n", num1);
	printf("Width 5: |%5u|\n", num1);
	ft_printf("Width 5, negative: |%5u|\n", -num1);
	printf("Width 5, negative: |%5u|\n", -num1);
	ft_printf("Width 2 for 3 digits: |%2u|\n", 123);
	printf("Width 2 for 3 digits: |%2u|\n", 123);
	ft_printf("Width 5 with zero2s: |%05d|\n", num1);
	printf("Width 5 with zero2s: |%05d|\n", num1);
	ft_printf("Width 5 with zero2s, negative: |%05u|\n", -num1);
	printf("Width 5 with zero2s, negative: |%05u|\n", -num1);
	ft_printf("Left-justify width 5: |%-5d|\n", num1);
	printf("Left-justify width 5: |%-5d|\n", num1);
	ft_printf("Left-justify width 5, negative: |%-5u|\n", -num1);
	printf("Left-justify width 5, negative: |%-5u|\n", -num1);
	ft_printf("Precision 4: |%.4u|\n", num1);
	printf("Precision 4: |%.4u|\n", num1);
	ft_printf("Precision 4, negative: |%.4u|\n", -num1);
	printf("Precision 4, negative: |%.4u|\n", -num1);
	ft_printf("Precision 0: |%.0u|\n", num1);
	printf("Precision 0: |%.0u|\n", num1);
	ft_printf("Precision 0, zero2: |%.0d|\n", zero2);
	printf("Precision 0, zero2: |%.0d|\n", zero2);
	ft_printf("Width 8, Precision 4: |%8.4u|\n", num1);
	printf("Width 8, Precision 4: |%8.4u|\n", num1);
	ft_printf("Width 8, Precision 4, negative: |%8.4u|\n", -num1);
	printf("Width 8, Precision 4, negative: |%8.4u|\n", -num1);
	ft_printf("Width 2, Precision 4: |%2.4u|\n", num1);
	printf("Width 2, Precision 4: |%2.4u|\n", num1);
	ft_printf("Zero, width, no precision: |%08u|\n", num1);
	printf("Zero, width, no precision: |%08u|\n", num1);
	ft_printf("Max int: |%u|\n", 2147483647);
	printf("Max int: |%u|\n", 2147483647);
	ft_printf("Zero precision with zero2: |%.0u|\n",num1);
	printf("Zero precision with zero2: |%.0u|\n",num1);
	ft_printf("Zero width with zero2: |%0u|\n", zero2);
	printf("Zero width with zero2: |%0u|\n", zero2);


	ft_printf("tes with #: |%#x|\n",num1);
	printf("tes with #: |%#x|\n",num1);
	ft_printf("test with width and precision : |%4.3x|\n",num1);
	printf("test with width and precision : |%4.3x|\n",num1);
	ft_printf("test zero and width: |%08x|\n",num1);
	printf("test zero and width: |%08x|\n",num1);
	ft_printf("test #, zero, width: |%#08x|\n",num1);
	printf("test #, zero, width: |%#08x|\n",num1);
	ft_printf("test with minus, #, width and precision: |%-#8.5x|\n",num1);
}
