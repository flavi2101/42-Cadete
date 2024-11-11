
#include "../libft/libft.h"
#include "prints.h"
#include "../utils/utils.h"

/*void	uitoa_with_malloc(unsigned int value,int *index, char *str_of_num, char conversion)
{
	if (value >= 16)
		uitoa_with_malloc(value / 16, index, str_of_num, conversion);
	if (conversion == 'x')
		str_of_num[(*index)++] = "0123456789abcdef"[value % 16];
	else
		str_of_num[(*index)++] = "0123456789ABCDEF"[value % 16];
}*/


int	print_hex(t_strfla *flag_info, va_list args)
{
        unsigned char   all_flags;
        void    *arg;
        int     count;
        unsigned int    value;

        all_flags = 0x00;
        value = va_arg(args,unsigned int);
        count = count_udigits(value, 16);
        arg = &value;
        set_flags_values(&all_flags, flag_info, count);
	all_flags &= ~space;
	all_flags &= ~plus;
	if (all_flags & minus && all_flags & hash)
		ft_putstr_fd("0x",1);
	else if (!(all_flags & minus) && !(all_flags & dot) && (all_flags & zero) && all_flags & hash)
		ft_putstr_fd("0x",1);
	show_str(arg, TYPE_HEX, all_flags, flag_info);
	return (14869);
}
