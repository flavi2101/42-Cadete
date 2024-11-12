/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_decimal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviohenr <flaviohenr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:24:56 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/12 20:10:44 by flaviohenr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"
#include "prints.h"
#include "../utils/utils.h"

void	invalid_flag_uns_dec(unsigned char *all_flags)
{
	*all_flags &= ~hash;
	*all_flags &= ~plus;
}
char	*ft_uitoa(unsigned n, int counter, int base, char conversion)
{
	char			*ptr;
	
	if (n == 0)
	{
		ptr = (char *)malloc(sizeof(char) * (2));
		ptr[1] = '\0';
		ptr[0] = '0';
		return (ptr);
	}
	ptr = (char *)malloc(sizeof(char) * (counter + 1));
	if (!ptr)
		return (NULL);
	ptr[counter--] = '\0';
	while (n != 0)
	{
		if (conversion == 'x')
			ptr[counter--] = "0123456789abcdef"[(n % base)];
		else if (conversion == 'X')
			ptr[counter--] = "0123456789ABCDEF"[(n % base)];
		else
			ptr[counter--] = "0123456789"[(n % base)];
		n = n / base;
	}
	return (ptr);
}
// return value not implemented yet.
int	print_unsigned_decimal(t_strfla *flag_info, va_list args)
{
        unsigned char   all_flags;
        void    *arg;
        int     count;
        unsigned int    value;

        all_flags = 0x00;
        value = va_arg(args, unsigned int);
        count = count_udigits(value, 10);
        arg = &value;
        set_flags_values(&all_flags, flag_info, count);
	show_str(arg, TYPE_UNSIGNED_INT, all_flags, flag_info);
	return (14869);
}
