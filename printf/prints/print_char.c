#include "../ft_printf.h"
#include "../libft/libft.h"
int	print_char(t_strfla *flag_info, va_list args)
{
	int	arg = va_arg(args,int);
	int	width;

	width = flag_info->width;
	if (!width)
	{
		ft_putchar_fd((char)arg, 1);
		return (1);
	}
	if (ft_strlen(flag_info->flags))
		ft_putchar_fd((char)arg, 1);
	while (width-- > 0)
		ft_putchar_fd('p',1);	
	if (!ft_strlen(flag_info->flags))
		ft_putchar_fd((char)arg, 1);
	return (flag_info->width + 1);
}
