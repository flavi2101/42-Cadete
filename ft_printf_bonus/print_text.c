/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:39:05 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/20 16:05:15 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	print_text(const char *str, int *str_flags_len)
{
	while (str[*str_flags_len] && str[*str_flags_len] != '%')
		ft_putchar_fd(str[(*str_flags_len)++], 1);
}
