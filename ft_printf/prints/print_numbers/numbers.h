
#ifndef NUMBER_H
# define NUMBER_H
#include "../../ft_printf.h"
void	remove_signal_atoi(char *str_of_num, unsigned char flags);
void	is_posi_or_neg(int *padding_space_value, unsigned char flags, char *value);
int	general_case(t_strfla *info, unsigned char flags, char *value, int len);
void	show_str_number(char *str_of_num, unsigned char flags, t_strfla *info, int len);
char	*ft_uitoa(unsigned n, int counter, int base, char conversion);
#endif
