/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:23:10 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/07 18:21:37 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Sua função deve lidar com as seguintes conversões: cspdiuxX%
/*%c Imprime um único caractere.
• %s Imprime uma string (conforme definido pela convenção comum do C).
• %p O endereço do ponteiro void * deve ser impresso em formato hexadecimal.
• %d Imprime um número decimal (base 10).
• %i Imprime um inteiro em base 10.
• %u Imprime um número decimal (base 10) sem sinal.
• %x Imprime um número em formato hexadecimal (base 16) em minúsculas.
• %X Imprime um número em formato hexadecimal (base 16) em maiúsculas.
• %% Imprime um sinal de porcentagem.
 */
#include "ft_printf.h"
#include "./libft/libft.h"
#include "./prints/prints.h"

void	set_func_conversion(t_strfla *flag_info)
{
	if (flag_info->conversion == 'c')
		flag_info->fuc = print_char;
	else if (flag_info->conversion == 's')
		flag_info->fuc = print_string;
	else if (flag_info->conversion == 'd')
		flag_info->fuc = print_decimal;
/*	else if (flag_info->conversion == 'i')	
		error_handle(flags_info,"-0. +");
	else if (flag_info->conversion == 'u')	
		error_handle(flags_info,"-0.");
	else if (flag_info->conversion == 'x')	
		error_handle(flags_info,"-0.#");
	else if (flag_info->conversion == 'X')	
		error_handle(flags_info,"-0.#");
*/
}

int	print_args(va_list args, t_strfla *flag_info)
{
	if (flag_info->conversion != 'p')
	{
		set_func_conversion(flag_info);
		return (flag_info->fuc(flag_info, args));
	}
	return (print_pointer(args));
}

int	check_percentage(const char *str, int *position)
{
	if (str[*position] && str[*position + 1] == '%' && ++(*position))
	{
		ft_putchar_fd(str[(*position)++], 1);
		return (1);
	}
	return (0);
}
// this is a trad off implemenation, or i parse the string twice
// or i will need to store the string of each iteration to avoid
// beggin the print and after find a invalid flag + conversion.

int	invalid_input(const char *str_input)
{
	int			posit;
	t_strfla	*flags_info;

	if (!str_input)
		return (-1);
	posit = 0;
	while (str_input[posit])
	{
		while (str_input[posit] && str_input[posit] != '%')
			posit++;
		if (check_percentage(str_input, &posit))
			continue ;
		if (!str_input[posit])
			return (0);
		flags_info = get_flags_info(str_input + posit + 1, &posit);
		if (flags_info == NULL)
			return (1);
		if (!handle_args(flags_info))
			return (1);
		free_flags(flags_info);
		// the same problem of printf implementation below - posit increment
		//if (str_input[posit] != '\0')
		//	++posit;
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	t_strfla	*flags_info;
	va_list		args;
	int			args_len;
	int			len_str_flags;

	len_str_flags = 0;
	args_len = 0;
	va_start(args, str);
	if (invalid_input(str))
		return (-1);
	while (str[len_str_flags])
	{
		while (str[len_str_flags] && str[len_str_flags] != '%')
			ft_putchar_fd(str[len_str_flags++], 1);
		if (check_percentage(str, &len_str_flags))
			continue ;
		if (!str[len_str_flags])
			return (len_str_flags + args_len);
		flags_info = get_flags_info(str + len_str_flags + 1, &len_str_flags);
		// removing the condition belown i am getting the correct size? 
		args_len += print_args(args, flags_info) - flags_info->total_len - 2;
		//if (str[len_str_flags] != '\0')
		//	++len_str_flags;
		// i need to free the flags_info
		free_flags(flags_info);
	}
	return (len_str_flags + args_len);
}

int	main(void)
{
	int	num = 27;

	ft_printf("|%-10d|\n", num);         // Width only, right-aligned
	ft_printf("|%-10.5d|\n", num);         // Width only, right-aligned
	ft_printf("|%-+10d|\n", num);        // Width only, left-aligned
	ft_printf("|%-+10d|\n", -1*num);        // Width only, left-aligned
/*	ft_printf("|%010d|\n", num);        // Width with zero-padding
	ft_printf("|%+10d|\n", num);        // Width with sign
	ft_printf("|% 10d|\n", num);        // Width with space for positive
	ft_printf("|%.5d|\n", num);         // Precision only
	ft_printf("|%10.5d|\n", num);       // Width and precision, right-aligned
	ft_printf("|%+10.5d|\n", num);      // Width, precision, and sign
	ft_printf("|% 10.5d|\n", num);      // Width, precision, and space for positive
	ft_printf("|%010.5d|\n", num);      // Width with zero-padding and precision	
*/ 
}
