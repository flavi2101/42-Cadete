/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:23:10 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/02 16:14:15 by flferrei         ###   ########.fr       */
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
int	print_args(va_list args, t_strfla *flag_info)
{
	int arg_len;

	arg_len = 0;
	if (flag_info->conversion == 'c')
		arg_len = print_char(flag_info,va_arg(args, int));
/*	 else if (flags_info->conversion == 's')	
		arg_len =	error_handle(flags_info,"-.");
	 else if (flags_info->conversion == 'p')	
		arg_len =	error_handle(flags_info,"");
	 else if (flags_info->conversion == 'd')	
		arg_len =	error_handle(flags_info,"-0. +");
	 else if (flags_info->conversion == 'i')	
		arg_len =	error_handle(flags_info,"-0. +");
	 else if (flags_info->conversion == 'u')	
		arg_len =	error_handle(flags_info,"-0.");
	 else if (flags_info->conversion == 'x')	
		arg_len =	error_handle(flags_info,"-0.#");
	 else if (flags_info->conversion == 'X')	
		arg_len =	error_handle(flags_info,"-0.#");
*/
	return (arg_len);
}


int	ft_printf(const char *str, ...)
{
	va_list args;
	int	len_str_plus_len_flags;
	int	args_len;
	t_strfla	*flags_info;

	len_str_plus_len_flags = 0;
	args_len = 0;
	va_start(args, str);
	while(str[len_str_plus_len_flags])
	{
		while(str[len_str_plus_len_flags] && str[len_str_plus_len_flags] != '%')
			ft_putchar_fd(str[len_str_plus_len_flags++], 1);
		flags_info = get_flags_width_precision_delimiter(str + len_str_plus_len_flags + 1, &len_str_plus_len_flags);
		if (flags_info == NULL)
			return (-1);
		if(!handle_args(flags_info))
			return (-1);
		// what return when invalid input?
		args_len += print_args(args, flags_info) - flags_info->total_len - 2;
		if (str[len_str_plus_len_flags] != '\0')
			++len_str_plus_len_flags;
	}
	va_end(args);	
	return (len_str_plus_len_flags + args_len);
}
int	main(void)
{
	ft_printf("% 010.2c");
}
