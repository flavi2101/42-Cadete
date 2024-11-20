/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:36:56 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/20 14:33:58 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTS_BONUS_H
# define PRINTS_BONUS_H
# include "../ft_printf_bonus.h"

/*typedef enum t_val_type
{
	TYPE_CHAR,
	TYPE_INT,
	TYPE_UNSIGNED_INT,
	TYPE_CHAR_PTR,
	TYPE_HEX,
	TYPE_PTR
} e_argType;*/

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
}	t_bit;
int		print_char(t_strfla *flag_info, va_list args);
int		print_string(t_strfla *flag_info, va_list args);
int		print_pointer(t_strfla *flag_info, va_list args);
int		print_decimal(t_strfla *flag_info, va_list args);
int		print_hex(t_strfla *flag_info, va_list args);
int		print_unsigned_decimal(t_strfla *flag_info, va_list args);
void	*has_flag(t_strfla *input_flags, int looking_for);
void	set_flags_values(unsigned char *flags, t_strfla *user_flag, int count);
int		show_str(void *value, unsigned char flags, t_strfla *info);
void	zero_x_printer(unsigned char flags, char conversion);
void	string_has_precision(char *str_of_str, t_strfla *info,
			int *str_position, unsigned char flags);
#endif
