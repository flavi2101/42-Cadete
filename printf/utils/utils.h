#ifndef UTILS_H
# define UTILS_H
#include "../ft_printf.h"
int	parse(char *in_flags, int len_in_flags, char *check_flag);
int	count_digits(int user_inp);
void    free_flags(t_strfla *flags_info);
#endif
