
#include "../libft/libft.h"
#include "prints.h"
#include "../utils/utils.h"

static void size_calc_un_hex(unsigned char all_flags, t_strfla *flag_info, int *size)
{

    if (all_flags & padding_width || all_flags & padding_precision)
    {
        if (flag_info->precision > *size)
            *size = flag_info->precision;
            
        if (flag_info->width > *size)
            *size = flag_info->width;
    }
}
static void	invalid_flags_hex(unsigned char *all_flags)
{
	*all_flags &= ~space;
	*all_flags &= ~plus;
}

static void	hex_notation(t_strfla *flag_info, char unsigned all_flags)
{
	ft_putstr_fd("0x",1);
	if (all_flags & padding_precision)
		flag_info->precision -= 2;
	if (all_flags & padding_width)
		flag_info->width -= 2;
}
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
	invalid_flags_hex(&all_flags);
	if (all_flags & minus && all_flags & hash && (count +=2))
		hex_notation(flag_info, all_flags);
	else if ((all_flags & zero) && all_flags & hash && (count +=2))
		hex_notation(flag_info, all_flags);
	else if (all_flags & hash)
		count += 2;
	size_calc_un_hex(all_flags, flag_info,&count);
	show_str(arg, TYPE_HEX, all_flags, flag_info);
	return (count);
}
