/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_decimal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviohenr <flaviohenr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:24:56 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/10 19:19:27 by flaviohenr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"
#include "prints.h"
#include "../utils/utils.h"
int	count_udigits(unsigned int user_inp)
{
	int	len;

	len = 0;
	while (user_inp != 0)
	{
		user_inp = user_inp / 10;
		len++;
	}
	return (len);
}
char	*ft_uitoa(unsigned n, int counter)
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
		ptr[counter--] = "0123456789"[(n % 10)];
		n = n / 10;
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
        count = count_udigits(value);
        arg = &value;
        set_flags_values(&all_flags, flag_info, count);
	all_flags &= ~hash;
	all_flags &= ~plus;
	show_str(arg, TYPE_UNSIGNED_INT, all_flags, flag_info);
	return (14869);
}
