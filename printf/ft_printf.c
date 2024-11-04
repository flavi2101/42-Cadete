/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:23:10 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/03 21:59:30 by flaviohenr       ###   ########.fr       */
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
void	free_str_flags(t_strfla *flags_info)
{
		if(flags_info->flags)
		{
			free(flags_info->flags);
			flags_info->flags = NULL;
		}
		free(flags_info);
		flags_info = NULL;
}


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
	if (ft_strlen(flag_info->flags))
		ft_putchar_fd((char)arg, 1);
	while (temp_count-- > 0)
		ft_putchar_fd('p',1);	
	if (!ft_strlen(flag_info->flags))
		ft_putchar_fd((char)arg, 1);
	return (flag_info->width + 1);
}
void	set_func_conversion(t_strfla *flag_info)
{
	if (flag_info->conversion == 'c')
		flag_info->fuc = print_char;
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
int	check_percentage(const char *str, int *position)
{
	if (str[*position] &&  str[*position + 1] == '%' && ++(*position))
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
	int	curr_position;
	t_strfla	*flags_info;

	if (!str_input)	
		return (1);
	curr_position = 0;
	while(str_input[curr_position])
	{
		while(str_input[curr_position] && str_input[curr_position] != '%')
			curr_position++;
		if (check_percentage(str_input, &curr_position))
			continue;	
		if(!str_input[curr_position])
			return (0);
		flags_info = get_flags_width_precision_delimiter(str_input + curr_position + 1, &curr_position);
		if (flags_info == NULL)
			return (1);
		if(!handle_args(flags_info))
			return (1);
		free_str_flags(flags_info);
		// the same problem of printf implementation below - curr_position increment
		//if (str_input[curr_position] != '\0')
		//	++curr_position;
	}
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
	if (invalid_input(str))
		return (-1);
	while(str[len_str_plus_len_flags])
	{
		while(str[len_str_plus_len_flags] && str[len_str_plus_len_flags] != '%')
			ft_putchar_fd(str[len_str_plus_len_flags++], 1);
		if (check_percentage(str, &len_str_plus_len_flags))
			continue;	
		if (!str[len_str_plus_len_flags])
			return (len_str_plus_len_flags + args_len);
		flags_info = get_flags_width_precision_delimiter(str + len_str_plus_len_flags + 1, &len_str_plus_len_flags);
		// removing the condition belown i am getting the correct size? 
		args_len += print_args(args, flags_info) - flags_info->total_len - 2;
		//if (str[len_str_plus_len_flags] != '\0')
		//	++len_str_plus_len_flags;
		// i need to free the flags_info
		free_str_flags(flags_info);
	}
	return (len_str_plus_len_flags + args_len);
}
int	main(void)
{
	ft_printf("%-10c", 'A');
}
