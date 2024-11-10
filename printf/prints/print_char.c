/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviohenr <flaviohenr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:23:38 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/08 18:27:52 by flaviohenr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"
/*
The minus flag is used to left-align the output of the character.
Meneaing will first print the character and then the padding.
*/
int	print_char(t_strfla *flag_info, va_list args)
{
	int	arg;
	int	width;

	arg = va_arg(args, int);
	width = flag_info->width;
	if (!width)
	{
		ft_putchar_fd((char)arg, 1);
		return (1);
	}
	if (ft_strlen(flag_info->flags))
		ft_putchar_fd((char)arg, 1);
	while (width-- > 0)
		ft_putchar_fd(' ', 1);
	if (!ft_strlen(flag_info->flags))
		ft_putchar_fd((char)arg, 1);
	return (flag_info->width + 1);
}
