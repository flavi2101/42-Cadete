
#include "../libft/libft.h"
#include "prints.h"
#include "../utils/utils.h"
// to get the correct len in the malloc i need divide by 16, 
// i can't use *len = count_udigits in helper_print.c in line 79'
char	*uitoa_with_malloc(unsigned int value,int *len, char *str_of_num, char conversion)
{
	if (value > 0)
		uitoa_with_malloc(value / 16,len, str_of_num, conversion);
	if (conversion == 'x')
		str_of_num[(*len)--] = "0123456789abcdef"[value % 16];
	else
		str_of_num[(*len)--] = "0123456789ABCDEF"[value % 16];
	return (str_of_num);
}


int	print_hex(t_strfla *flag_info, va_list args)
{
        unsigned char   all_flags;
        void    *arg;
        int     count;
        unsigned int    value;

        all_flags = 0x00;
        value = va_arg(args,unsigned int);
        count = count_udigits(value);
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
