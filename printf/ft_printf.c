/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:23:10 by flferrei          #+#    #+#             */
/*   Updated: 2024/10/30 11:00:28 by flaviohenr       ###   ########.fr       */
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
#include "printf.h"
#include "./libft/libft.h"

typedef struct s_flag_info_plus_conver
{
	char conversion;
	char *flags;
	int	len_flags;
} t_strfla;

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

static t_strfla *get_flags_and_delimiter(const char * spc_value, int * len)
{
	char	*in_flags;
	int	flag_counter;
	t_strfla	*flags_info;

	flag_counter = 0;
	flags_info = NULL;
	while (!ft_isalpha(spc_value[flag_counter]))
		flag_counter++;
	*len +=  flag_counter + 1 ;
	flags_info->len_flags = flag_counter;
	flags_info->conversion = *(spc_value + flag_counter);
	in_flags = (char *)malloc(sizeof(char) * flag_counter);
	in_flags[flag_counter] = '\0';
	while (--flag_counter >= 0)
		in_flags[flag_counter] = *(spc_value + flag_counter);
	if(!parse(in_flags, flags_info->len_flags,"-0.# +"))
		// return NULL if flags are invalid;
		// i must make a clean in the in_flags;
		return (NULL);	
	flags_info->flags = in_flags;
	return flags_info;
	}
int print_args(va_list args, t_strfla *flags_info)
{
/*	if (*spc_value == 'c')
		ft_putchar_fd(*spc_value, 1);
	else if (*spc_value == 's')	
		ft_putchar_fd(*spc_value, 1);
	else if (*spc_value == 'p')	
		ft_putchar_fd(*spc_value, 1);
	else if (*spc_value == 'd')	
		ft_putchar_fd(*spc_value, 1);
	else if (*spc_value == 'i')	
		ft_putchar_fd(*spc_value, 1);
	else if (*spc_value == 'u')	
		ft_putchar_fd(*spc_value, 1);
	else if (*spc_value == 'x')	
		ft_putchar_fd(*spc_value, 1);
	else if (*spc_value == 'X')	
		ft_putchar_fd(*spc_value, 1);
*/
// lembrar de liberar memoria de flags_info  apos escrever os dados de 
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	int	len;
	int	args_len;
	t_strfla	*flags_info;

	len = 0;
	args_len = 0;
	va_start(args, str);
	
	while(str[len])
	{
		while(str[len] && str[len] != '%')
			ft_putchar_fd(str[len++], 1);
		// preciso usar o len na func abaixo para iterar depois das flags.
		flags_info = get_flags_and_delimiter(str + len + 1, &len);
		args_len += print_args(args, flags_info);
	// se eu incrementar o len baseado no tamanho do que estiver nos args, vou pegar a posição errada na proxima 
	// intereçao. salvar em uma outra variavel todos os len dor args e no final somar com o len da impressao do que não esta no args	
		if (str[len] != '\0')
			++len;
	}
	
	return (len + args_len);
}
int	main(void)
{
	ft_printf("casa%0.#c do");
}
