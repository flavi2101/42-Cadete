/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:23:10 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/02 21:24:40 by flaviohenr       ###   ########.fr       */
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
int	print_char(t_strfla *flag_info, va_list args)
{
	int	arg = va_arg(args,int);
	int	temp_count;

	temp_count = flag_info->width;
	if (!temp_count)
	{
		ft_putchar_fd((char)arg, 1);
		return (1);
	}
	while (temp_count-- > 0)
		ft_putchar_fd(' ',1);	
	ft_putchar_fd((char)arg, 1);
	return (flag_info->width + 1);
}
void	set_func_conversion(t_strfla *flag_info)
{
	if (flag_info->conversion == 'c')
		flag_info->fuc = print_char;
/*	else if (flag_info->conversion == 's')	
		error_handle(flags_info,"-.");
	else if (flag_info->conversion == 'p')	
		error_handle(flags_info,"");
	else if (flag_info->conversion == 'd')	
		error_handle(flags_info,"-0. +");
	else if (flag_info->conversion == 'i')	
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
	set_func_conversion(flag_info);
	return (flag_info->fuc(flag_info, args));
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
		if (str[len_str_plus_len_flags + 1] == '%' && ++len_str_plus_len_flags)
		{
			ft_putchar_fd(str[len_str_plus_len_flags++], 1);
			continue;	
		}
		flags_info = get_flags_width_precision_delimiter(str + len_str_plus_len_flags + 1, &len_str_plus_len_flags);
		if (flags_info == NULL)
			return (0);
		if(!handle_args(flags_info))
			return (0);
		args_len += print_args(args, flags_info) - flags_info->total_len - 2;
		if (str[len_str_plus_len_flags] != '\0')
			++len_str_plus_len_flags;
	}
	return (len_str_plus_len_flags + args_len);
}
int	main(void)
{
	ft_printf("%-5c",'a');
}
