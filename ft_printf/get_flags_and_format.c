/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags_and_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviohenr <flaviohenr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:27:51 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/17 15:25:08 by flaviohenr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"
#include "utils/utils.h"

//calculate the lenght the flag separed with the lenght of values
//after the dot must be a number to be a valid precision.
//insert in the struct this values as integers 
static int	width_precision(t_strfla *flags_info, const char *flags, int *qnty)
{
	char	width;
	char	precision;
	int		len;

	len = 0;
	width = '1';
	precision = '1';
	while (!ft_isalpha(flags[len]))
	{
		if (width && flags[len] != '0'
			&& ft_isdigit(flags[len]) && flags[len -1] != '.')
		{
			flags_info->width = ft_atoi(&flags[len]);
			width = '\0';
			*qnty += count_digits(flags_info->width);
		}
		if (precision && flags[len] == '.' && ft_isdigit(flags[len + 1]))
		{
			flags_info->precision = ft_atoi(&flags[len + 1]);
			*qnty += count_digits(flags_info->precision);
			precision = '\0';
			width = '\0';
		}
		len++;
	}
	return (len);
}

// store only flags in the return
// to a 0 be flag it not must preceded by another number (second if).
static char	*get_flags(t_strfla *flag_info, int len_flags,
int len_fla_num, const char *ptr_aft_perc)
{
	char	*usr_inp_flags;
	char	current_char;

	usr_inp_flags = (char *)malloc(sizeof(char) * (len_flags + 1));
	if (!usr_inp_flags)
	{
		free_flags(flag_info);
		return (NULL);
	}
	ft_memset(usr_inp_flags, 0, len_flags + 1);
	usr_inp_flags[len_flags--] = '\0';
	while (--len_fla_num >= 0 && len_flags >= 0)
	{
		current_char = *(ptr_aft_perc + len_fla_num);
		if (current_char == '0'
			&& !ft_isdigit(*(ptr_aft_perc + len_fla_num - 1)))
			usr_inp_flags[len_flags--] = current_char;
		else if (!ft_isdigit(current_char))
			usr_inp_flags[len_flags--] = current_char;
	}
	return (usr_inp_flags);
}
// generate all information necessary to fetch the struct
// one function responsible to get only the width and precision
// another to get only flags
// the last one to validaded if the flags are valid 

t_strfla	*get_flags_info(const char *ptr_percent, int *len)
{
	t_strfla	*flags_info;
	int			len_flag_num;
	int			len_nums;
	int			len_flag;

	len_nums = 0;
	flags_info = (t_strfla *)malloc(sizeof(t_strfla));
	if (!flags_info)
		return (NULL);
	ft_memset(flags_info, 0, sizeof(t_strfla));
	len_flag_num = width_precision(flags_info, ptr_percent, &len_nums);
// was two the line below, i change is one because i am jump the letter in the caller 
	*len += len_flag_num + 1;
	flags_info->conversion = *(ptr_percent + len_flag_num);
	len_flag = len_flag_num - len_nums;
	flags_info->total_len = len_flag_num;
	flags_info->flags = get_flags(flags_info, len_flag,
			len_flag_num, ptr_percent);
	if (!parse(flags_info->flags, flags_info->total_len - len_nums, "-0.# +"))
		// return NULL if flags are invalid;
		// i must make a clean in the usr_inp_flags and flag_info;
		return (NULL);
	return (flags_info);
}
