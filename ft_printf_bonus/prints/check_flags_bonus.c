/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:37:13 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/20 14:32:02 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "prints_bonus.h"

void	*has_flag(t_strfla *input_flags, int looking_for)
{
	const void	*flags;

	flags = (void *)input_flags->flags;
	return (ft_strchr(flags, looking_for));
}

void	set_flags_values(unsigned char *flags, t_strfla *user_flag, int count)
{
	if (user_flag->width > count)
		*flags |= padding_width;
	if (user_flag->precision > count)
		*flags |= padding_precision;
	if ((has_flag(user_flag, (int) '.') || has_flag(user_flag, (int) '-')))
		*flags &= ~zero;
	else if (has_flag(user_flag, (int) '0'))
		*flags |= zero;
	if (has_flag(user_flag, (int) '.'))
		*flags |= dot;
	if (has_flag(user_flag, (int) '#'))
		*flags |= hash;
	if (has_flag(user_flag, (int) '-'))
		*flags |= minus;
	if (has_flag(user_flag, (int) ' '))
		*flags |= space;
	if (has_flag(user_flag, (int) '+'))
	{
		*flags |= plus;
		*flags &= ~space;
	}
}
