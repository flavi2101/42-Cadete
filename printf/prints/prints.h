#ifndef PRINTS_H
# define PRINTS_H
#include "../ft_printf.h"
typedef enum t_bit_flag
{
	plus = 1 << 0,
	space = 1 << 1,
	dot = 1 << 2,
	zero = 1 << 3,
	minus = 1 << 4,
	hash = 1 << 5,
	padding_space = 1 << 6,
	padding_zero = 1 << 7

} e_bit;
int     print_char(t_strfla *flag_info, va_list args);
int     print_string(t_strfla *flag_info, va_list args);
int     print_pointer(va_list args);
int     print_decimal(t_strfla *flag_info, va_list args);
#endif
