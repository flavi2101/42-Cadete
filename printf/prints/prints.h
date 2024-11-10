#ifndef PRINTS_H
# define PRINTS_H
#include "../ft_printf.h"
typedef enum t_val_type{
    TYPE_CHAR,
    TYPE_INT,
    TYPE_UNSIGNED_INT,
    TYPE_CHAR_PTR,
    TYPE_VOID_PTR
} e_argType;

typedef enum t_bit_flag
{
	plus = 1 << 0,
	space = 1 << 1,
	dot = 1 << 2,
	zero = 1 << 3,
	minus = 1 << 4,
	hash = 1 << 5,
	padding_width = 1 << 6,
	padding_precision = 1 << 7

} e_bit;
int     print_char(t_strfla *flag_info, va_list args);
int     print_string(t_strfla *flag_info, va_list args);
int     print_pointer(va_list args);
int     print_decimal(t_strfla *flag_info, va_list args);
int     print_decimal_wbase(t_strfla *flag_info, va_list args);
void	*has_flag(t_strfla *input_flags, int looking_for);
void	set_flags_values(unsigned char *flags, t_strfla *user_flag, int count);
void	remove_signal_atoi(char *str_of_num, e_argType value_type, t_strfla *info, unsigned char flags);
void	is_pos_or_neg(int *padding_space_value, unsigned char flags, char *value);
int	general_case(t_strfla *info, unsigned char flags, char *value, int len);
char	*get_len(void *value, e_argType value_type, int *len);
int	show_str(void *value, e_argType value_type, unsigned char flags, t_strfla *info);
#endif
