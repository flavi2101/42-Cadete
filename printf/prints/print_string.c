#include "../ft_printf.h"
#include "../libft/libft.h"
/* incomplete, don't consider the precision'
static int	size_of_arg(int str_len, int width)
{
	if(str_len > width) 
		return (str_len);
	return (width);
}*/
static void	set_order_print(int signed_flag, int padding, int precision, char *arg, char symb)
{
	if (signed_flag)
	{
		while (precision-- > 0 )
			ft_putchar_fd(*arg++, 1);
		while (padding-- > 0 )
			ft_putchar_fd(symb, 1);
	}
	else
	{
		while (padding-- > 0 )
			ft_putchar_fd(symb, 1);
		while (precision-- > 0 )
			ft_putchar_fd(*arg++, 1);
	}

}

static void	handle_signal_in_string(t_strfla * flag_info, char * arg, int	signed_flag, char symb)
{
	int	padding;
	int	str_len;

	str_len = ft_strlen(arg);
	padding = 0;
	if (flag_info->width > str_len)
	{
		if (flag_info->precision > str_len)
			flag_info->precision = str_len;
		else
			padding = str_len - flag_info->precision;
		padding += flag_info->width - str_len;
		set_order_print(signed_flag, padding, flag_info->precision, arg, symb);
	}
	else
	{
		flag_info->width = str_len;
		if (flag_info->precision > str_len)
			flag_info->precision = str_len;
		padding += flag_info->width - str_len;
		set_order_print(signed_flag, padding, flag_info->precision, arg, symb);
	}
}
int	print_string(t_strfla *flag_info, va_list args)
{
	char	*arg; 
	const void	*flags;
	char	symb;
	void	*has_signal;

	flags = flag_info->flags;
	arg = va_arg(args,char *);
	symb = 'P';
	has_signal = ft_strchr(flags, (int)'-');
	// check if i can remove the condition below
	if (flag_info->width == 0 && flag_info->precision == 0)
	{
		ft_putstr_fd(arg, 1);	
		return ft_strlen((char const *)arg);
	}
	else if(has_signal)
		handle_signal_in_string(flag_info, arg, 1, symb);
	else
		handle_signal_in_string(flag_info, arg, 0, symb);

	return (14580);
}
