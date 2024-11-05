// check if the flag are valid and are related with the correct delimiter 
#include "../libft/libft.h"
#include "../ft_printf.h"
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
void	free_flags(t_strfla *flags_info)
{
		if(flags_info->flags)
		{
			free(flags_info->flags);
			flags_info->flags = NULL;
		}
		free(flags_info);
		flags_info = NULL;
}
