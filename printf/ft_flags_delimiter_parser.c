#include "ft_printf.h"
#include "./libft/libft.h"
// check if the flag are valid and are related with the correct delimiter 
int	parse(char *in_flags, int len_in_flags, char *check_flag)
{
	int	size_check_flag;

	size_check_flag = ft_strlen(check_flag);	
	while(len_in_flags-- > 0)
	{
		if(!ft_memchr(check_flag, *in_flags++, size_check_flag))
			return (0);
	}
	return (1);	
}

int count_digis(int user_inp)
{
	int len;

	len = 0;
	while (user_inp > 0)
	{
		user_inp = user_inp / 10;
		len++;
	}
	return (len);
}
//calculate the lenght the flag separed with the lenght of values
//after the dot must be a number to be a valid precision.
//insert in the struct this values as integers 
int get_width_and_precision(t_strfla *pt_flags_info, const char	*flags, int *num_qnty)
{
	int	flags_len;
	char	flag_num_of_width;
	char	flag_num_of_precision;

	flags_len = 0;
	flag_num_of_width = '1';
	flag_num_of_precision = '1';
	while (!ft_isalpha(flags[flags_len]))
	{
		if (flag_num_of_width && flags[flags_len] != '0' && ft_isdigit(flags[flags_len]))
		{
			pt_flags_info->width = ft_atoi(&flags[flags_len]);
			flag_num_of_width = '\0';
			*num_qnty += count_digis(pt_flags_info->width); 
		}
		if (flag_num_of_precision && flags[flags_len] == '.' && ft_isdigit(flags[flags_len + 1]))
		{
			pt_flags_info->precision = ft_atoi(&flags[flags_len + 1]);	
			flag_num_of_precision = '\0';
			*num_qnty += count_digis(pt_flags_info->precision); 
		}	
		flags_len++;
	}
	return (flags_len);

}	
// store only flags in the return
// to a 0 be flag it not must preceded by another number (second if).
char	*get_flags(t_strfla *flag_info, int len_only_flags, int len_flags_plus_nums, const char * ptr_after_percentage)
{
	char	*usr_inp_flags;
	char	current_char;

	usr_inp_flags = (char *)malloc(sizeof(char) * (len_only_flags + 1));
	ft_memset(usr_inp_flags,0, len_only_flags);
	if (!usr_inp_flags)
	{
		free_flags(flag_info);
		return (NULL);
	}
	usr_inp_flags[len_only_flags--] = '\0';
	while (--len_flags_plus_nums >= 0)
	{
		current_char = *(ptr_after_percentage + len_flags_plus_nums); 
		if(current_char == '0' && !ft_isdigit(*(ptr_after_percentage + len_flags_plus_nums - 1)))
			usr_inp_flags[len_only_flags--] = current_char;
		else if (!ft_isdigit(current_char)) 
			usr_inp_flags[len_only_flags--] = current_char;
	}
	return (usr_inp_flags);

}
// generate all information necessary to fetch the struct
// one function responsible to get only the width and precision
// another to get only flags
// the last one to validaded if the flags are valid 
t_strfla *get_flags_width_precision_delimiter(const char * ptr_after_percentage, int * len)
{
	int	len_flags_plus_nums;
	int	len_only_nums;
	int	len_only_flags;
	t_strfla	*flags_info;

	len_only_nums = 0;	
	flags_info = (t_strfla *)malloc(sizeof(t_strfla));
	if (!flags_info)
		return (NULL);
	ft_memset(flags_info,0, sizeof(t_strfla));
	len_flags_plus_nums = get_width_and_precision(flags_info, ptr_after_percentage, &len_only_nums); 	
	*len += len_flags_plus_nums + 2;
	flags_info->conversion = *(ptr_after_percentage + len_flags_plus_nums);
	len_only_flags = len_flags_plus_nums - len_only_nums; 
	flags_info->total_len = len_flags_plus_nums;
	flags_info->flags = get_flags(flags_info, len_only_flags, len_flags_plus_nums, ptr_after_percentage);

	if(!parse(flags_info->flags, flags_info->total_len - len_only_nums,"-0.# +"))
		// return NULL if flags are invalid;
		// i must make a clean in the usr_inp_flags and flag_info;
		return (NULL);	
	return flags_info;
}
