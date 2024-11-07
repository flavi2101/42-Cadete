/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:23:38 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/07 17:25:15 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"
#include "../libft/libft.h"

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
		ft_putchar_fd('p', 1);
	if (!ft_strlen(flag_info->flags))
		ft_putchar_fd((char)arg, 1);
	return (flag_info->width + 1);
}
