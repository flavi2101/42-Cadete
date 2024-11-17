/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:26:03 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/17 12:40:56 by flaviohenr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"
#include "prints.h"
static char	*get_len_str(void *value, int *len)
{
	char	*str;
	
	str = NULL;
	if (!value)
	{
		str = ft_strdup("(null)");
		*len = 6;
	}
	else
	{
		*len = ft_strlen((char *)value);
		str = ft_strdup((const char *)(value));
	}
       	return (str);
}
// use the print_string to cut some lines 
static void	show_str_str(char *str_of_str, unsigned char flags, t_strfla *info)
{
	int		padding_space_value;
	int	len;
	int	str_position;

	len = 0;	
	str_position = 0;
	if (flags & padding_precision)
		padding_space_value = info->width -  info->precision;  
	else
		padding_space_value = info->width -  len;  
	if (flags & minus)
	{
		if (flags & padding_precision)
		{
			while (info->precision-- > 0)
				ft_putchar_fd(str_of_str[str_position++], 1);
		}
		else
			ft_putstr_fd(str_of_str, 1);
		while (padding_space_value-- > 0)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (padding_space_value-- > 0)
			ft_putchar_fd(' ', 1);
		if (flags & padding_precision)
		{
			while (info->precision-- > 0)
				ft_putchar_fd(str_of_str[str_position++], 1);
		}
		else
			ft_putstr_fd(str_of_str, 1);
	}
}

static void size_calc_str(unsigned char all_flags, t_strfla *flag_info, int *size)
{
    int orig_size = *size;

    if (all_flags & padding_width || all_flags & padding_precision)
    {
        if (flag_info->precision < orig_size)
            *size = flag_info->precision;
            
        if (flag_info->width > *size)
            *size = flag_info->width;
    }
}
static void	invalid_flags_str(t_strfla *flag_info, unsigned char *all_flags, int count)
{
	*all_flags &= ~plus;
	*all_flags &= ~space;
	*all_flags &= ~zero;
	*all_flags &= ~hash;
	if (flag_info->precision < count && flag_info->precision > 0)
		*all_flags |= padding_precision;
	else 
		*all_flags &= ~padding_precision;
}

int	print_string(t_strfla *flag_info, va_list args)
{
	unsigned char	all_flags;
	int	count;
	char	*value;
	char	*str_of_str;

	all_flags = 0x00;
	count = 0;
	value = va_arg(args, char *);
	set_flags_values(&all_flags, flag_info, count);
	invalid_flags_str(flag_info, &all_flags, count);
	str_of_str = get_len_str(value, &count);
	if (str_of_str)
	{
		show_str_str(str_of_str, all_flags, flag_info);
		free(str_of_str);
	}
	else
		free_flags(flag_info);
	size_calc_str(all_flags, flag_info, &count);
	return (count);
}
