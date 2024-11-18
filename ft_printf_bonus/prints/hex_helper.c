#include "../libft/libft.h"
#include "prints.h"
void	zero_x_printer(unsigned char flags, char conversion)
{
	if (flags & hash)
	{
		if (conversion == 'x')
			ft_putstr_fd("0x", 1);
		else
			ft_putstr_fd("0X", 1);
	}
}
