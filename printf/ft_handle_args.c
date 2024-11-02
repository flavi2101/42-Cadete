#include "ft_printf.h"
#include "./libft/libft.h"
int	error_handle(t_strfla	*flags_info, char *conversion_opt)
{
	size_t	len_flag_input;

	len_flag_input = ft_strlen(flags_info->flags);
	if (len_flag_input > ft_strlen(conversion_opt))
		return (0);
	if(!parse(flags_info->flags, len_flag_input, conversion_opt))
		return (0);	
	return (1);
}	

int	handle_args(t_strfla *flags_info)
{
	int valid_input;

	valid_input = 0;
	if (flags_info->conversion == 'c')
		valid_input =	error_handle(flags_info,"-");
	 else if (flags_info->conversion == 's')	
		valid_input =	error_handle(flags_info,"-.");
	 else if (flags_info->conversion == 'p')	
		valid_input =	error_handle(flags_info,"");
	 else if (flags_info->conversion == 'd')	
		valid_input =	error_handle(flags_info,"-0. +");
	 else if (flags_info->conversion == 'i')	
		valid_input =	error_handle(flags_info,"-0. +");
	 else if (flags_info->conversion == 'u')	
		valid_input =	error_handle(flags_info,"-0.");
	 else if (flags_info->conversion == 'x')	
		valid_input =	error_handle(flags_info,"-0.#");
	 else if (flags_info->conversion == 'X')	
		valid_input =	error_handle(flags_info,"-0.#");
	return (valid_input);
}
