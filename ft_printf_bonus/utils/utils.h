/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:21:16 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/19 18:06:00 by flaviohenr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "../ft_printf.h"

void	free_flags(t_strfla *flags_info);
int		parse(char *in_flags, int len_in_flags, char *check_flag);
int		count_digits(int user_inp);
int		count_udigits(unsigned int user_inp, int base);
#endif
