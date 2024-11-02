/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:23:10 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/02 00:20:47 by flaviohenr       ###   ########.fr       */
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
int	print_args(va_list args, t_strfla flag_info)
{
	return (0);
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
		// preciso usar o len_str_plus_len_flags na func abaixo para iterar depois das flags.
		flags_info = get_flags_width_precision_delimiter(str + len_str_plus_len_flags + 1, &len_str_plus_len_flags);
		if (flags_info == NULL)
			return (0);
		if(!handle_args(flags_info))
			return (0);
		// what return when invalid input?
		 args_len += print_args(args, flags_info) - flags_info->total_len - 2;

		// SERA PRECISO DA CLEAR NO STRACTURE AFTER ESCREVER A CADA ITERAÇÃO ?
		// se eu incrementar o len_str_plus_len_flags baseado no tamanho do que estiver nos args, vou pegar a posição errada na proxima 
		// intereçao. salvar em uma outra variavel todos os len_str_plus_len_flags dor args e no final somar com o len_str_plus_len_flags da impressao do que não esta no args. Considerar que os caracteres das flags estão sendo somados no len_str_plus_len_flags, isso vai dar um tamanho errado.
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
