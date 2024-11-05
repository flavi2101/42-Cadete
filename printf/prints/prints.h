#ifndef PRINTS_H
# define PRINTS_H
#include "../ft_printf.h"
int     print_char(t_strfla *flag_info, va_list args);
int     print_string(t_strfla *flag_info, va_list args);
int     print_pointer(va_list args);
#endif
