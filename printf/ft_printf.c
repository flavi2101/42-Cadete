/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:23:10 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/01 18:14:14 by flferrei         ###   ########.fr       */
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
#include <assert.h>
// check if the flag are valid and are related with the correct delimiter 
int	parse(char *in_flags, int len_in_flags, char *check_flag)
{
	int	size_check_flag;

	size_check_flag = ft_strlen(check_flag);	
	while(len_in_flags-- > 0)
	{
		if(!ft_memchr(check_flag, *in_flags++, size_check_flag))
			return (0);
	}
	return (1);	
}

int count_digis(int user_inp)
{
	int len;

	len = 0;
	while (user_inp > 0)
	{
		user_inp = user_inp / 10;
		len++;
	}
	return (len);
}
//calculate the lenght the flag separed with the lenght of values
//insert in the struct this values as integers 
static	int get_width_and_precision(t_strfla *pt_flags_info, const char	*flags, int *num_qnty)
{
	int	flags_len;
	char	flag_num_of_width;
	char	flag_num_of_precision;

	flags_len = 0;
	flag_num_of_width = '1';
	flag_num_of_precision = '1';
	while (!ft_isalpha(flags[flags_len]))
	{
		if (flag_num_of_width && flags[flags_len] != '0' && ft_isdigit(flags[flags_len]))
		{
			pt_flags_info->width = ft_atoi(&flags[flags_len]);
			flag_num_of_width = '\0';
			*num_qnty += count_digis(pt_flags_info->width); 
		}
		if (flag_num_of_precision && flags[flags_len] == '.')
		{
			pt_flags_info->precision = ft_atoi(&flags[flags_len + 1]);	
			flag_num_of_precision = '\0';
			*num_qnty += count_digis(pt_flags_info->precision); 
		}	
		flags_len++;
	}
	return (flags_len);

}	
// store only flags in the return
// to a 0 be flag it not must preceded by another number.
static char	*get_flags(int len_only_flags, int len_flags_plus_nums, const char * ptr_after_percentage)
{
	char	*usr_inp_flags;
	char	current_char;

	usr_inp_flags = (char *)malloc(sizeof(char) * (len_only_flags));
	if (!usr_inp_flags)
		// clean flags_info return null
		return (NULL);
	usr_inp_flags[len_only_flags--] = '\0';
	while (--len_flags_plus_nums >= 0)
	{
		current_char = *(ptr_after_percentage + len_flags_plus_nums); 
		if(current_char == '0' && !ft_isdigit(*(ptr_after_percentage + len_flags_plus_nums - 1)))
			usr_inp_flags[len_only_flags--] = current_char;
		else if (!ft_isdigit(current_char)) 
			usr_inp_flags[len_only_flags--] = current_char;
	}
	return (usr_inp_flags);

}
// generate all information necessary to fetch the struct
// one function responsible to get only the width and precision
// another to get only flags
// the last one to validaded if the flags are valid 
static	t_strfla *get_flags_width_precision_delimiter(const char * ptr_after_percentage, int * len)
{
	int	len_flags_plus_nums;
	int	len_only_nums;
	int	len_only_flags;
	t_strfla	*flags_info;

	len_only_nums = 0;	
	flags_info = (t_strfla *)malloc(sizeof(t_strfla));
	if (!flags_info)
		return (NULL);
	len_flags_plus_nums = get_width_and_precision(flags_info, ptr_after_percentage, &len_only_nums); 	
	*len += len_flags_plus_nums + 2;
	flags_info->conversion = *(ptr_after_percentage + len_flags_plus_nums);
	len_only_flags = len_flags_plus_nums - len_only_nums; 
	flags_info->total_len = len_flags_plus_nums;
	flags_info->flags = get_flags(len_only_flags, len_flags_plus_nums, ptr_after_percentage);

	if(!parse(flags_info->flags, flags_info->total_len - len_only_nums,"-0.# +"))
		// return NULL if flags are invalid;
		// i must make a clean in the usr_inp_flags and flag_info;
		return (NULL);	
	return flags_info;
}
int	error_handle(t_strfla	*flags_info, char *conversion_opt)
{
	size_t	len_flag_input;

	len_flag_input = ft_strlen(flags_info->flags);
	if (len_flag_input > ft_strlen(conversion_opt))
		return (0);
	if(!parse(flags_info->flags, len_flag_input, conversion_opt))
		return (0);	
	return (1);
}	

int	handle_args(t_strfla *flags_info)
{
	int valid_input;

	valid_input = 0;
	if (flags_info->conversion == 'c')
		valid_input =	error_handle(flags_info,"-");
	 else if (flags_info->conversion == 's')	
		valid_input =	error_handle(flags_info,"-.");
	 else if (flags_info->conversion == 'p')	
		valid_input =	error_handle(flags_info,"");
	 else if (flags_info->conversion == 'd')	
		valid_input =	error_handle(flags_info,"-0. +");
	 else if (flags_info->conversion == 'i')	
		valid_input =	error_handle(flags_info,"-0. +");
	 else if (flags_info->conversion == 'u')	
		valid_input =	error_handle(flags_info,"-0.");
	 else if (flags_info->conversion == 'x')	
		valid_input =	error_handle(flags_info,"-0.#");
	 else if (flags_info->conversion == 'X')	
		valid_input =	error_handle(flags_info,"-0.#");
// lembrar de liberar memoria de flags_info  apos escrever os dados de 
	if (!valid_input)
		return (0);
	return (1);
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
