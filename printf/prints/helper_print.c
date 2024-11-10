#include "../libft/libft.h"
#include "prints.h"
#include "../utils/utils.h"
void	remove_signal_atoi(char *str_of_num, e_argType value_type, t_strfla *info, unsigned char flags)
{
		if (str_of_num[0] == '-')
			ft_putstr_fd(str_of_num + 1, 1);
		else if (value_type == TYPE_CHAR_PTR && flags & padding_precision)
		{
			while (info->precision-- > 0)
				ft_putchar_fd(*str_of_num++, 1);
		}
		else
			ft_putstr_fd(str_of_num, 1);
}

void	is_pos_or_neg(int *padding_space_value, unsigned char flags, char *value)
{
		if ((flags & plus) && value[0] != '-' && (*padding_space_value)--)
			ft_putchar_fd('+', 1);
		else if (flags & space && value[0] != '-' && (*padding_space_value)--)
			ft_putchar_fd(' ', 1);
		else if (value[0] == '-' && (*padding_space_value)--)
			ft_putchar_fd('-', 1);
}

int	general_case(t_strfla *info, unsigned char flags, char *value, int len)
{
	int	padding_space_value;

	if (flags & padding_precision)
		padding_space_value = info->width -  info->precision;  
	else
		padding_space_value = info->width -  len;  
	while (padding_space_value-- > 0)
	{
		ft_putchar_fd(' ', 1);
		if ((flags & plus) && padding_space_value == 1)
			break;
	}
	is_pos_or_neg(&padding_space_value, flags, value);
	if (info->precision - len > 0 && flags & padding_precision) 
	{
		while (info->precision-- -len> 0)
			ft_putchar_fd('0', 1);
	}
	return (1);
}
char	*get_len(void *value, e_argType value_type, int *len)
{
	char	*str;
	
	str = NULL;
	if (value_type == TYPE_CHAR )
	{
		(*len)++;
		str = (char *)value;
	}
	else if (value_type == TYPE_INT)
	{
		str = ft_itoa(*(int *)value);	
		*len = count_digits(*(int *)value);	
	}
	else if (value_type == TYPE_CHAR_PTR)
	{
		if (!(*(char *)value))
			*len = 6;
		else
		{
			*len = ft_strlen((char *)value);
			str = (char *)value;
		}
	}
	return (str);
}
int	show_str(void *value, e_argType value_type, unsigned char flags, t_strfla *info)
{
	char	*str_of_num;
	int		padding_value;
	int	len;
	len = 0;	
	str_of_num = get_len(value, value_type, &len);
	if (str_of_num)
	{
		padding_value = info->width - len;
		if (flags & minus)
		{
			is_pos_or_neg(&padding_value, flags, str_of_num);
			remove_signal_atoi(str_of_num, value_type, info, flags);
			while (padding_value-- > 0)
				ft_putchar_fd(' ', 1);
		}
		else if (!(flags & minus) && !(flags & dot) && (flags & zero))
		{
			is_pos_or_neg(&padding_value, flags, str_of_num);
			while (padding_value-- > 0)
				ft_putchar_fd('0', 1);
			remove_signal_atoi(str_of_num, value_type, info, flags);
		}
		else if (general_case(info, flags, str_of_num, len))
			remove_signal_atoi(str_of_num, value_type, info, flags);
		if (value_type == TYPE_INT || value_type == TYPE_UNSIGNED_INT)
			free(str_of_num);
	}
	return (14821);
}