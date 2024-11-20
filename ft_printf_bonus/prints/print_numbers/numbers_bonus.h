/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:38:41 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/20 14:35:32 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUMBERS_BONUS_H
# define NUMBERS_BONUS_H
# include "../../ft_printf_bonus.h"

void	remove_signal_atoi(char *str_of_num, unsigned char flags);
void	is_posi_or_neg(int *padding_space_value,
			unsigned char flags, char *value);
int		general_case(t_strfla *info, unsigned char flags, char *value, int len);
void	show_str_number(char *str_of_num, unsigned char flags,
			t_strfla *info, int len);
char	*ft_uitoa(unsigned int num, int counter, int base, char conversion);
#endif
