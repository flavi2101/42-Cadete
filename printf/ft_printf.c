/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:23:10 by flferrei          #+#    #+#             */
/*   Updated: 2024/10/28 18:57:41 by flferrei         ###   ########.fr       */
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


static void	print_special_value(const char * letter, int * len)
{
	
	if (*letter == 'c')
		ft_putchar_fd(*letter, 1);
	else if (*letter == 's')	
		ft_putchar_fd(*letter, 1);
	else if (*letter == 'p')	
		ft_putchar_fd(*letter, 1);
	else if (*letter == 'd')	
		ft_putchar_fd(*letter, 1);
	else if (*letter == 'i')	
		ft_putchar_fd(*letter, 1);
	else if (*letter == 'u')	
		ft_putchar_fd(*letter, 1);
	else if (*letter == 'x')	
		ft_putchar_fd(*letter, 1);
	else if (*letter == 'X')	
		ft_putchar_fd(*letter, 1);
	else if (*letter == '%')	
		ft_putchar_fd(*letter, 1);
	*len = *len;
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	int	len;

	len = 0;
	va_start(args, str);
	
	while(str[len])
	{
		while(str[len] && str[len] != '%')
			ft_putchar_fd(str[len++], 1);
		print_special_value(&str[++len], &len);	
		
		if (str[len] != '\0')
			++len;
	}
	
	return (len);
}
int	main(void)
{
	ft_printf("print c %c do");
	ft_printf("print p %p do");
	ft_printf("print d %d do");
	ft_printf("print i %i do");
	ft_printf("print u %u do");
	ft_printf("print x %x do");
	ft_printf("print X %X do");
	ft_printf("print % %% do");
}
