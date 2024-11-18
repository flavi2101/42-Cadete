/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviohenr <flaviohenr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:23:38 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/17 23:47:39 by flaviohenr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "prints_bonus.h"
#include "../libft/libft.h"

static char	*get_len_char(void *value, int *len)
{
	char	*str;
	
	str = NULL;
	(*len)++;
	str = malloc(sizeof(int) * 1);
	if (str)
	{
		str[0] = *(int *)value;
	}	
       	return (str);
}

static void	show_str_char(void *value, unsigned char flags, t_strfla *info)
{
	char	*str_of_num;
	int		padding_value;
	int	len;

	len = 0;	
	str_of_num = get_len_char(value, &len);
	if (str_of_num)
	{
		padding_value = info->width - len;
		if (flags & minus)
		{
			ft_putchar_fd(str_of_num[0], 1);
			while (padding_value-- > 0)
				ft_putchar_fd(' ', 1);
		}
		else
		{
			while (padding_value-- > 0)
				ft_putchar_fd(' ', 1);
			ft_putchar_fd(str_of_num[0], 1);
		}	
		free(str_of_num);
	}
	else
		free_flags(info);
}
static void	invalid_flag_char(unsigned char *all_flags)
{
	*all_flags &= ~plus;
	*all_flags &= ~space;
	*all_flags &= ~dot;
	*all_flags &= ~zero;
	*all_flags &= ~hash;
	*all_flags &= ~padding_precision;
}
int	print_char(t_strfla *flag_info, va_list args)
{

	unsigned char	all_flags;
	void	*arg;
	int	count;
	int	temp_arg;

	all_flags = 0x00;
	count = 1;
	temp_arg = va_arg(args, int);
	arg = &temp_arg;
	set_flags_values(&all_flags, flag_info, count);
	invalid_flag_char(&all_flags);
	if (all_flags & padding_width)
		count = flag_info->width;
	show_str_char(arg, all_flags, flag_info);
	return (count);
}
