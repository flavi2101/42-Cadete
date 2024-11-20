/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:23:40 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/19 15:42:43 by flaviohenr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

/*int	parse(char *in_flags, int len_in_flags, char *check_flag)
{
	while (len_in_flags-- > 0)
	{
		if (!ft_strchr(check_flag, *in_flags++))
			return (0);
	}
	return (1);
}*/

int	count_digits(int user_inp)
{
	int	len;

	len = 0;
	if (user_inp == 0)
		return (1);
	while (user_inp != 0)
	{
		user_inp = user_inp / 10;
		len++;
	}
	return (len);
}

int	count_udigits(unsigned long long user_inp, int base)
{
	int	len;

	len = 0;
	if (user_inp == 0)
		return (1);
	while (user_inp != 0)
	{
		user_inp = user_inp / base;
		len++;
	}
	return (len);
}

void	free_flags(t_strfla *flags_info)
{
	if (flags_info->flags)
	{
		free(flags_info->flags);
		flags_info->flags = NULL;
	}
	free(flags_info);
	flags_info = NULL;
}
