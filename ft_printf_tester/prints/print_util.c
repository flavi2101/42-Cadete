#include "../libft/libft.h"
#include "prints.h"
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
// move to utils/utils.c
char	*ft_uitoa(unsigned n, int counter, int base, char conversion)
{
	char			*ptr;
	
	if (n == 0)
	{
		ptr = (char *)malloc(sizeof(char) * (2));
		ptr[1] = '\0';
		ptr[0] = '0';
		return (ptr);
	}
	ptr = (char *)malloc(sizeof(char) * (counter + 1));
	if (!ptr)
		return (NULL);
	ptr[counter--] = '\0';
	while (n != 0)
	{
		if (conversion == 'x')
			ptr[counter--] = "0123456789abcdef"[(n % base)];
		else if (conversion == 'X')
			ptr[counter--] = "0123456789ABCDEF"[(n % base)];
		else
			ptr[counter--] = "0123456789"[(n % base)];
		n = n / base;
	}
	return (ptr);
}
