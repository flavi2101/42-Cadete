#include "../libft/libft.h"

void	print_text(const char *str, int *str_flags_len)
{
	while (str[*str_flags_len] && str[*str_flags_len] != '%')
		ft_putchar_fd(str[(*str_flags_len)++], 1);
}
