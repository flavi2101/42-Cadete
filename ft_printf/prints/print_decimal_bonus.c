/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviohenr <flaviohenr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:24:56 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/16 16:57:52 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "prints_bonus.h"
#include "../utils/utils_bonus.h"
#include "../libft/libft.h"
// if the flag +,space or is the value negative the witdh and precision 
// can be overwrite it. 
// if arg < 0 the precision always increment the size, but the width will depend 

void	remove_signal_atoi_d(char *str_of_num)
{
	if (str_of_num[0] == '-')
		ft_putstr_fd(str_of_num + 1, 1);
	else
		ft_putstr_fd(str_of_num, 1);
}
void	is_posi_or_neg(int *padding_space_value, unsigned char flags, char *value)
{
		if ((flags & plus) && value[0] != '-' && (*padding_space_value)--)
			ft_putchar_fd('+', 1);
		else if (flags & space && value[0] != '-' && (*padding_space_value)--)
			ft_putchar_fd(' ', 1);
		else if (value[0] == '-' && (*padding_space_value)--)
			ft_putchar_fd('-', 1);
}
char	*get_len_dec(void *value, int *len)
{
	char	*str;
	
	str = NULL;
	str = ft_itoa(*(int *)value);	
	*len = count_digits(*(int *)value);	
	if (*(int *)value < 0)
		(*len)++;
       	return (str);
}
int	general_case_dec(t_strfla *info, unsigned char flags, char *value, int len)
{
	int	padding_space_value;

	if (flags & padding_precision)
		padding_space_value = info->width -  info->precision;  
	else
		padding_space_value = info->width -  len;  
	while (padding_space_value-- > 0)
	{
		ft_putchar_fd(' ', 1);
		if ((flags & plus || flags & space) && padding_space_value == 1)
			break;
		if ((value[0] == '-') && padding_space_value == 1)
			break;
	}
	is_posi_or_neg(&padding_space_value, flags, value);
	if (info->precision - len > 0 && flags & padding_precision) 
	{
		while (info->precision-- -len> 0)
			ft_putchar_fd('0', 1);
	}
	return (1);
}
static int	show_str_dec(void *value, unsigned char flags, t_strfla *info)
{
	char	*str_of_num;
	int		padding_value;
	int	len;

	len = 0;	
	str_of_num = get_len_dec(value, &len);
	if (str_of_num)
	{
		padding_value = info->width - len;
		if (flags & minus)
		{
			is_posi_or_neg(&padding_value, flags, str_of_num);
			if (info->precision - len > 0 && flags & padding_precision) 
			{
				while (info->precision-- -len> 0 && padding_value--)
					ft_putchar_fd('0', 1);
			}
			remove_signal_atoi_d(str_of_num);
			while (padding_value-- > 0)
				ft_putchar_fd(' ', 1);
		}
		else if (!(flags & minus) && !(flags & dot) && (flags & zero))
		{
			is_posi_or_neg(&padding_value, flags, str_of_num);

			while (padding_value-- > 0)
				ft_putchar_fd('0', 1);
			remove_signal_atoi_d(str_of_num);
		}
		else if (general_case_dec(info, flags, str_of_num, len))
			remove_signal_atoi_d(str_of_num);
		free(str_of_num);
	}
	else
		free_flags(info);
	return (14821);
}
static void size_calc(unsigned char all_flags, t_strfla *flag_info, int *size, int arg)
{
    int orig_size = *size;

    if (all_flags & padding_width || all_flags & padding_precision)
    {
        if (flag_info->precision > orig_size)
            *size = flag_info->precision;
            
        if (arg < 0 || (all_flags & plus) || (all_flags & space))
            (*size)++;
            
        if (flag_info->width > *size)
            *size = flag_info->width;
    }
    else
    {
        if (arg < 0 || (all_flags & plus) || (all_flags & space))
            (*size)++;
    }
}
int	print_decimal(t_strfla *flag_info, va_list args)
{
        unsigned char   all_flags;
        void    *arg;
        int     count;
        int    value;

        all_flags = 0x00;
        value = va_arg(args, int);
	count = count_digits(value);
        arg = &value;
        set_flags_values(&all_flags, flag_info, count);
	all_flags &= ~hash;
	size_calc(all_flags, flag_info, &count, value);
	show_str_dec(arg, all_flags, flag_info);
	return (count);
}
