/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviohenr <flaviohenr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:23:10 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/17 15:31:32 by flaviohenr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "prints/prints.h"
//#include <assert.h>
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

/*int	main(void)
{
	 int ft_len;
	 int og_len;

    // Test 1: Basic number
    printf("\nTest 1: Basic positive number\n");
    ft_len = ft_printf("%d", 42);
    og_len = printf("%d", 42);
    printf("\nft_len: %d, og_len: %d\n", ft_len, og_len);
    printf("-------------\n");

    // Test 2: Zero
    printf("Test 2: Zero\n");
    ft_len = ft_printf("%d", 0);
    og_len = printf("%d", 0);
    printf("\nft_len: %d, og_len: %d\n", ft_len, og_len);
    printf("-------------\n");

    // Test 3: Negative number
    printf("Test 3: Negative number\n");
    ft_len = ft_printf("%d", -42);
    og_len = printf("%d", -42);
    printf("\nft_len: %d, og_len: %d\n", ft_len, og_len);
    printf("-------------\n");

    // Test 4: Minimum width
    printf("Test 4: Minimum width of 5\n");
    ft_len = ft_printf("%5d", 42);
    og_len = printf("%5d", 42);
    printf("\nft_len: %d, og_len: %d\n", ft_len, og_len);
    printf("-------------\n");

    // Test 5: Left-aligned with width
    printf("Test 5: Left-aligned with width\n");
    ft_len = ft_printf("%-5d", 42);
    og_len = printf("%-5d", 42);
    printf("\nft_len: %d, og_len: %d\n", ft_len, og_len);
    printf("-------------\n");

    // Test 6: Zero padding
    printf("Test 6: Zero padding\n");
    ft_len = ft_printf("%05d", 42);
    og_len = printf("%05d", 42);
    printf("\nft_len: %d, og_len: %d\n", ft_len, og_len);
    printf("-------------\n");

    // Test 7: Precision
    printf("Test 7: Precision\n");
    ft_len = ft_printf("%.5d", 42);
    og_len = printf("%.5d", 42);
    printf("\nft_len: %d, og_len: %d\n", ft_len, og_len);
    printf("-------------\n");

    // Test 8: Width and Precision
    printf("Test 8: Width and Precision\n");
    ft_len = ft_printf("%8.5d", 42);
    og_len = printf("%8.5d", 42);
    printf("\nft_len: %d, og_len: %d\n", ft_len, og_len);
    printf("-------------\n");

    // Test 9: Plus flag
    printf("Test 9: Plus flag\n");
    ft_len = ft_printf("%+d", 42);
    og_len = printf("%+d", 42);
    printf("\nft_len: %d, og_len: %d\n", ft_len, og_len);
    printf("-------------\n");

    // Test 10: Space flag
    printf("Test 10: Space flag\n");
    ft_len = ft_printf("% d", 42);
    og_len = printf("% d", 42);
    printf("\nft_len: %d, og_len: %d\n", ft_len, og_len);
    printf("-------------\n");

    // Test 11: INT_MAX
    printf("Test 11: INT_MAX\n");
    ft_len = ft_printf("%d", INT_MAX);
    og_len = printf("%d", INT_MAX);
    printf("\nft_len: %d, og_len: %d\n", ft_len, og_len);
    printf("-------------\n");

    // Test 12: INT_MIN
    printf("Test 12: INT_MIN\n");
    ft_len = ft_printf("%d", INT_MIN);
    og_len = printf("%d", INT_MIN);
    printf("\nft_len: %d, og_len: %d\n", ft_len, og_len);
    printf("-------------\n");

    // Test 13: Zero with precision
    printf("Test 13: Zero with precision\n");
    ft_len = ft_printf("%.0d", 0);
    og_len = printf("%.0d|------------", 0);
    printf("\nft_len: %d, og_len: %d\n", ft_len, og_len);
    printf("-------------\n");

    // Test 14: Width, left-aligned, plus flag
    printf("Test 14: Width, left-aligned, plus flag\n");
    ft_len = ft_printf("%-+8d", 42);
    og_len = printf("%-+8d", 42);
    printf("\nft_len: %d, og_len: %d\n", ft_len, og_len);
    printf("-------------\n");

    // Test 15: Width, zero padding, plus flag
    printf("Test 15: Width, zero padding, plus flag\n");
    ft_len = ft_printf("%0+8d", 42);
    og_len = printf("%0+8d", 42);
    printf("\nft_len: %d, og_len: %d\n", ft_len, og_len);
    printf("-------------\n");

    // Test 16: Precision with negative number
    printf("Test 16: Precision with negative number\n");
    ft_len = ft_printf("%.7d", -42);
    og_len = printf("%.7d", -42);
    printf("\nft_len: %d, og_len: %d\n", ft_len, og_len);
    printf("-------------\n");

    // Test 17: Width smaller than number
    printf("Test 17: Width smaller than number\n");
    ft_len = ft_printf("%2d", 12345);
    og_len = printf("%2d", 12345);
    printf("\nft_len: %d, og_len: %d\n", ft_len, og_len);
    printf("-------------\n");

    // Test 18: Precision smaller than number
    printf("Test 18: Precision smaller than number\n");
    ft_len = ft_printf("%.2d", 12345);
    og_len = printf("%.2d", 12345);
    printf("\nft_len: %d, og_len: %d\n", ft_len, og_len);
    printf("-------------\n");

    // Test 19: Zero precision with non-zero number
    printf("Test 19: Zero precision with non-zero number\n");
    ft_len = ft_printf("%.0d", 42);
    og_len = printf("%.0d", 42);
    printf("\nft_len: %d, og_len: %d\n", ft_len, og_len);
    printf("-------------\n");

    // Test 20: Space flag with negative number
    printf("Test 20: Space flag with negative number\n");
    ft_len = ft_printf("% d", -42);
    og_len = printf("% d", -42);
    printf("\nft_len: %d, og_len: %d\n", ft_len, og_len);
    printf("-------------\n");

    // Test 21: Complex width and precision
    printf("Test 21: Complex width and precision\n");
    ft_len = ft_printf("%15.10d", -54321);
    og_len = printf("%15.10d", -54321);
    printf("\nft_len: %d, og_len: %d\n", ft_len, og_len);
    printf("-------------\n");

    // Test 22: Width with space flag
    printf("Test 22: Width with space flag\n");
    ft_len = ft_printf("% 10d", 42);
    og_len = printf("% 10d", 42);
    printf("\nft_len: %d, og_len: %d\n", ft_len, og_len);
    printf("-------------\n");

    // Test 24: Zero padding with negative number
    printf("Test 24: Zero padding with negative number\n");
    ft_len = ft_printf("%08d", -42);
    og_len = printf("%08d", -42);
    printf("\nft_len: %d, og_len: %d\n", ft_len, og_len);
    printf("-------------\n");

    // Test 25: Large width with various flags
    printf("Test 25: Large width with various flags\n");
    ft_len = ft_printf("%+25d", -42);
    og_len = printf("%+25d", -42);
    printf("\nft_len: %d, og_len: %d\n", ft_len, og_len);
    printf("-------------\n");
}
*/
