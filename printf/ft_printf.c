/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:23:10 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/01 01:24:59 by flaviohenr       ###   ########.fr       */
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
int	parse(char *in_flags, int len_in_flags, char *check_flag)
{
	int	size_check_flag;

	size_check_flag = ft_strlen(check_flag);	
	while(--len_in_flags > 0)
	{
		if(!ft_memchr(check_flag, *in_flags++, size_check_flag))
			return (0);
	}
	return (1);	
}
/*
recive the string after the % char
iterate to get the symbols using !ft_isalpha
increment the len that represet the size of string and
	 plus two because of flag_counter stop at last flag,so
	 increment to count this flag plus the conversion char.
allocate all this information in the flag_info struct. 
*/

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
static	t_strfla *get_flags_width_precision_delimiter(const char * ptr_after_percentage, int * len)
{
	char	*usr_inp_flags;
	int	flags_len;
	int	flags_len_adjust_num;
	int	flags_total_len;
	t_strfla	*flags_info;

	flags_len_adjust_num = 0;	
	flags_info = (t_strfla *)malloc(sizeof(t_strfla));
	if (!flags_info)
		return (NULL);
	flags_len = get_width_and_precision(flags_info, ptr_after_percentage, &flags_len_adjust_num); 	
	*len += flags_len + 2;
	flags_info->conversion = *(ptr_after_percentage + flags_len);
	flags_total_len = flags_len - flags_len_adjust_num; 
	flags_info->len_flags = flags_len;
	usr_inp_flags = (char *)malloc(sizeof(char) * (flags_total_len));
	if (!usr_inp_flags)
		// clean flags_info return null
		return (NULL);
	usr_inp_flags[flags_total_len--] = '\0';
	while (--flags_len >= 0)
	{
		if(*(ptr_after_percentage + flags_len) == '0' && !ft_isdigit(*(ptr_after_percentage + flags_len - 1))) 	
			usr_inp_flags[flags_total_len--] = *(ptr_after_percentage + flags_len);
		else if (!ft_isdigit(*(ptr_after_percentage + flags_len))) 
			usr_inp_flags[flags_total_len--] = *(ptr_after_percentage + flags_len);
	}
	if(!parse(usr_inp_flags, flags_info->len_flags - flags_len_adjust_num,"-0.# +"))
		// return NULL if flags are invalid;
		// i must make a clean in the usr_inp_flags and flag_info;
		return (NULL);	
	flags_info->flags = usr_inp_flags;
	return flags_info;
}
int print_args(va_list args, t_strfla *flags_info)
{
	char	*compatibility;

	if (flags_info->conversion == 'c')
	{
		compatibility = "-";
		va_arg(args, int);
		//handle_char(flags_info, va_arg(args, int), compatibility);
		assert(*compatibility != '-');
	}
/*		ft_putchar_fd(*spc_value, 1);
	else if (flags_info->conversion == 's')	
		ft_putchar_fd(*spc_value, 1);
	else if (flags_info->conversion == 'p')	
		ft_putchar_fd(*spc_value, 1);
	else if (flags_info->conversion == 'd')	
		ft_putchar_fd(*spc_value, 1);
	else if (flags_info->conversion == 'i')	
		ft_putchar_fd(*spc_value, 1);
	else if (flags_info->conversion == 'u')	
		ft_putchar_fd(*spc_value, 1);
	else if (flags_info->conversion == 'x')	
		ft_putchar_fd(*spc_value, 1);
	else if (*spc_value == 'X')	
		ft_putchar_fd(*spc_value, 1);
*/
// lembrar de liberar memoria de flags_info  apos escrever os dados de 
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
		args_len += print_args(args, flags_info) - flags_info->len_flags;
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
	ft_printf("% 010.2f");
}
