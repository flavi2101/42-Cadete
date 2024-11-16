/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:04:04 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/14 16:05:04 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

typedef struct s_flag_info_plus_conver
{
	int		(*fuc)(struct s_flag_info_plus_conver *, va_list);
	int		width;	
	int		total_len;
	int		precision;
	char	*flags;
	char	conversion;
}	t_strfla;
t_strfla	*get_flags_info(const char *ptr_after_percentage, int *len);
void		free_flags(t_strfla *flags_info);
int			handle_args(t_strfla *flags_info);
int	ft_printf(const char *str, ...);
#endif
